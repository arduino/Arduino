#include <Energia.h>

#include <xdc/std.h>

#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Types.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/utils/Load.h>

/*
 * This is the sketch for the UART debug console. Nothing else should be using the same
 * serial connection.
 *
 * To add a command, simply create a prototype for the handler function following the
 * model of the handler prototypes in the `local functions' section below, add the
 * function itself in the `local function defs' section below, and add a line to the
 * _consoleCommandTable definition in the `command table' section. The name of your
 * command must have a length < MAX_COMMAND_LEN, and the handler's name should follow
 * the format `consoleHandler_<NAME>'. Also note that the line that is passed into the
 * handler starts right after the command's name; if arguments were supplied to the
 * command, *line will be a space character.
 */

#define DM_CMD 1     /* dump memory cmd */
#define WM_CMD 1     /* write to memory cmd */
#define DRW_CMDS 1   /* digital read/write cmds */
#define ARW_CMDS 1   /* analog read/write cmds */
#define SPI_CMD 1    /* SPI transfer cmd */
#define PRI_CMD 1    /* Set Task priority cmd */
#define STATS_CMD 1  /* CPU and task utilzation stats cmd */

#define MAX_COMMAND_LEN 48
#define MAX_COMMAND_NAME_LEN 8
#define MAX_COMMAND_LINES 5


// Return codes for handlers
#define RETURN_SUCCESS          (0)
#define RETURN_FAIL             (-1)
#define RETURN_FAIL_PRINT_USAGE (-2)

typedef void (*RepeatFunc)(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3);
static void doRepeat(RepeatFunc func, uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3);

static void sanitizeLine(char *line);

static int consoleHandler_help(const char *line);

#if DRW_CMDS == 1
static int consoleHandler_dr(const char *line);
static int consoleHandler_dw(const char *line);
#endif

#if ARW_CMDS == 1
static int consoleHandler_ar(const char *line);
static int consoleHandler_aw(const char *line);
#endif

#if WM_CMD == 1
static int consoleHandler_wm(const char *line);
static int consoleHandler_wm1(const char *line);
static int consoleHandler_wm2(const char *line);
#endif

#if DM_CMD == 1
static int consoleHandler_dm(const char *line);
#endif

#if STATS_CMD == 1
static int consoleHandler_stats(const char *line);
#endif

#if SPI_CMD == 1
static int consoleHandler_spi(const char *line);
#endif

#if PRI_CMD == 1
static int consoleHandler_pri(const char *line);
#endif

static char home[] = "\e[H";
static char clear[] = "\e[2J";

/*
 *  ======== command table ========
 */
#define GEN_COMMTABLE_ENTRY(name, desc, detail) {   #name,  consoleHandler_##name,  desc,   detail  }

static const struct {
    const char*name;                    // The name of the command
    int (*handler)(const char*line);    // Pointer to the command's handler
    const char*description;             // A short description of the command (for use by help)
    const char*detailedUsage;           // A detailed description of the command's usage (for use by help)
} _consoleCommandTable[] = {
#if DM_CMD == 1
    GEN_COMMTABLE_ENTRY(dm,      "dump memory",                 "usage: dm <address (hex)> <num words> <word size (1/4)>"),
#endif
#if WM_CMD == 1
    GEN_COMMTABLE_ENTRY(wm,      "write to memory (32 bits)",   "usage: wm <address (hex)> <words..>"),
    GEN_COMMTABLE_ENTRY(wm2,     "write to memory (16 bits)",   "usage: wm <address (hex)> <half words..>"),
    GEN_COMMTABLE_ENTRY(wm1,     "write to memory (8 bits)",    "usage: wm <address (hex)> <bytes..>"),
#endif
#if DRW_CMDS == 1
    GEN_COMMTABLE_ENTRY(dw,      "digitalWrite to pin",         "usage: dw <pin> <value>"),
    GEN_COMMTABLE_ENTRY(dr,      "digitalRead from pin",        "usage: dr <pin>"),
#endif
#if ARW_CMDS == 1
    GEN_COMMTABLE_ENTRY(aw,      "analogWrite to pin",          "usage: aw <pin> <value>"),
    GEN_COMMTABLE_ENTRY(ar,      "analogRead from pin",         "usage: ar <pin>"),
#endif
#if PRI_CMD == 1
    GEN_COMMTABLE_ENTRY(pri,     "Set task priority",           "usage: pri <task handle> <priority>"),
#endif
#if SPI_CMD == 1
    GEN_COMMTABLE_ENTRY(spi,     "SPI transfer",                "usage: spi <cs pin> <data>"),
#endif
#if STATS_CMD == 1
    GEN_COMMTABLE_ENTRY(stats,   "Print CPU utlization info",   "usage: stats"),
#endif
    GEN_COMMTABLE_ENTRY(help,    "Get information on commands. Usage: help [command]",  NULL),
    {NULL,NULL,NULL,NULL}   // Indicates end of table
};

void mon_setup(void)
{
    Serial.begin(9600);
    Serial.println("Welcome! This is the Serial debug console.");
}

#define UP_ARROW 0x0b    /* ctrl K */
#define DOWN_ARROW 0x0C  /* ctrl L */

void mon_loop()
{
    // each loop iteration is one command

    Serial.print("> ");

    // ------------------------------------- read line
    static char line[MAX_COMMAND_LINES][MAX_COMMAND_LEN];

    static int line_num = 0;
    int char_index = 0;
    bool line_end = false;
    int escape_index = 0;

    while (true) {
        char c = Serial.read();

        if (escape_index) {
            if (++escape_index == 3) {
                escape_index = 0;
                switch(c) {
                    case 'A':
                        c = UP_ARROW;
                        break;
                    case 'B':
                        c = DOWN_ARROW;
                        break;
                    default:
                        continue;
                }
            }
            else {
                continue;
            }
        }

        switch (c) {
            case 0x1b: /* escape */
                escape_index = 1;
                continue;
                
            case UP_ARROW:
                if (--line_num < 0) { 
                    line_num = MAX_COMMAND_LINES - 1;
                }
                Serial.print("\r                         \r> ");
                char_index = strlen(line[line_num]);
                Serial.print(line[line_num]);
                continue;
            case DOWN_ARROW:
                if (++line_num == MAX_COMMAND_LINES) { 
                    line_num = 0;
                }
                Serial.print("\r                         \r> ");
                char_index = strlen(line[line_num]);
                Serial.print(line[line_num]);
                continue;
            case '\r':
                Serial.println("");
                if (char_index == 0) {
                    Serial.print("> ");
                    continue;
                }
                else {
                    line_end = true;
                    break;
                }
            case 0x08:
            case 0x7f:   /* Backspace */
                if (char_index >= 1) {
                    char_index -= 1;
                    Serial.print("\b \b");
                }
                continue;
            case 3: /* control 'c' */
                Serial.println("^C");
                return;
        }

        if (line_end == false) {        
            line[line_num][char_index++] = c;

            if (char_index == MAX_COMMAND_LEN) {
                // The user typed something too long; abort so they don't get surprise commands running
                Serial.println("\r\nCommand too long.");
                return;
            }

            // default for Serial is ECHO_OFF, and there doesn't seem to be a way to change that
            Serial.print(c);
        }
        else {
            line[line_num][char_index] = 0;
            break;
        }
    }

    // ------------------------------------- process line
    sanitizeLine(line[line_num]);

    char cmdstr[MAX_COMMAND_NAME_LEN+1];
    
    memset(cmdstr, 0, sizeof(cmdstr));

    int i;

    for (i = 0; i < MAX_COMMAND_NAME_LEN && line[line_num][i] && line[line_num][i] != ' '; i++) {
        cmdstr[i] = line[line_num][i];
    }

    // ignore empty command
    if (!*cmdstr) {
        return;
    }

    int commandIndex = -1;
    for (i=0; _consoleCommandTable[i].name; i++) {
        if (!strncmp(cmdstr,_consoleCommandTable[i].name,MAX_COMMAND_NAME_LEN)) {
            commandIndex = i;
            break;
        }
    }

    if (commandIndex == -1) {
        Serial.print("The command `");
        Serial.print(cmdstr);
        Serial.println("' was not recognized.");
        return;
    }

    if (!_consoleCommandTable[commandIndex].handler) {
        Serial.println("That command has not yet been implemented.");
        return;
    }

    int returnVal = _consoleCommandTable[commandIndex].handler(line[line_num]
            +strlen(_consoleCommandTable[commandIndex].name));

    if (++line_num == MAX_COMMAND_LINES) {
        line_num = 0;
    }
    
    switch (returnVal) {
        case RETURN_SUCCESS:    break;
        case RETURN_FAIL:       break;

        case RETURN_FAIL_PRINT_USAGE: {
            const char*toPrint = _consoleCommandTable[commandIndex].detailedUsage
                     ? _consoleCommandTable[commandIndex].detailedUsage
                     : _consoleCommandTable[commandIndex].description;

            Serial.println(toPrint);
            break;
        }

        default:
            Serial.println("Warning: unknown return value!");
            break;
    }
}

static void sanitizeLine(char *line)
{
    int len = strlen(line);
    char buf[MAX_COMMAND_LEN];

    strncpy(buf, line, len);    // copy original line to buf (which is our source)
    memset(line, 0, len);       // zero out provided line (which is our destination)

    int bufIndex    = 0;
    int lineIndex   = 0;

    for (; bufIndex < len && lineIndex < len; bufIndex++) {
        char c = buf[bufIndex];
        bool copy = ('A'<=c && c<='Z') ||
                    ('a'<=c && c<='z') ||
                    ('0'<=c && c<='9') ||
                    c=='_' || c==' ' ||
                    c=='.' || c==',' ||
                    c==';' || c==':' ||
                    c=='*' || c=='-';
        if(copy) {
            line[lineIndex++] = c;
        }
    }
}

static int consoleHandler_help(const char *line){
    int i;

    if (!*line) {
        // No command in particular specified; just print them all
        Serial.println("Available commands:");
        for (i=0; _consoleCommandTable[i].name; i++) {
            if(!_consoleCommandTable[i].handler)    // if NYI, don't list
                continue;

            Serial.print("  ");
            Serial.print(_consoleCommandTable[i].name);
            Serial.print("\t  ");
            Serial.println(_consoleCommandTable[i].description);
        }
    } else {
        // get past the space so we can parse the command
        while (*line && *line==' ') {
            line++;
        }

        char cmdstr[MAX_COMMAND_NAME_LEN+1];
        memset(cmdstr,0,sizeof(cmdstr));
        for (i=0; i<MAX_COMMAND_NAME_LEN && line[i] && line[i] != ' '; i++) {
            cmdstr[i] = line[i];
        }

        int commandIndex = -1;
        for (i=0; _consoleCommandTable[i].name; i++) {
            if (!strncmp(cmdstr,_consoleCommandTable[i].name,MAX_COMMAND_NAME_LEN)) {
                commandIndex = i;
                break;
            }
        }

        if (commandIndex == -1) {
            Serial.print("The command `");
            Serial.print(cmdstr);
            Serial.println("' was not recognized.");
            return RETURN_FAIL;
        }

        const char*toPrint = _consoleCommandTable[i].detailedUsage
                     ? _consoleCommandTable[i].detailedUsage
                     : _consoleCommandTable[i].description;

        Serial.print(cmdstr);
        Serial.print(": ");
        Serial.println(toPrint);
    }

    return RETURN_SUCCESS;
}


static void doRepeat(RepeatFunc func, uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    Serial.print(clear);
    while(!Serial.available()) {
        Serial.print(home);
        func(arg0, arg1, arg2, arg3);
    }
    Serial.read(); /* remove char from input buf */
}

#if DRW_CMDS == 1

static void doDr(uint32_t pin)
{
    Serial.print("digitalRead(");
    Serial.print(pin);
    Serial.print(") = ");
    Serial.println(digitalRead(pin));
}

static int consoleHandler_dr(const char *line)
{
    if (*line++ != ' ') {
        return RETURN_FAIL_PRINT_USAGE;
    }
    char *endptr = NULL;
    uint32_t pin = strtol(line, &endptr, 10);

    if (*endptr == ' ') {
        doRepeat((RepeatFunc)doDr, pin, 0, 0, 0);
    }
    else {
        doDr(pin);
    }
    return RETURN_SUCCESS;
}

static int consoleHandler_dw(const char *line)
{
    if (*line++ != ' ') {
        return RETURN_FAIL_PRINT_USAGE;
    }
    char *endptr = NULL;
    uint32_t pin = strtoul(line, &endptr, 10);
    int32_t val = strtol(endptr, NULL, 0);
    Serial.print("Calling digitalWrite(");
    Serial.print(pin);
    Serial.print(", ");
    Serial.print(val);
    Serial.println(").");
    digitalWrite(pin, val);
    return RETURN_SUCCESS;
}

#endif /* DRW_CMDS */

#if ARW_CMDS == 1

static void doAr(uint32_t pin)
{
    Serial.print("analogRead(");
    Serial.print(pin);
    Serial.print(") = ");
    Serial.println(analogRead(pin));
}

static int consoleHandler_ar(const char *line)
{
    if (*line++ != ' ') {
        return RETURN_FAIL_PRINT_USAGE;
    }
    char *endptr = NULL;
    uint32_t pin = strtol(line, &endptr, 10);
    
    if (*endptr == ' ') {
        doRepeat((RepeatFunc)doAr, pin, 0, 0, 0);
    }
    else {
        doAr(pin);
    }
    return RETURN_SUCCESS;
}

static int consoleHandler_aw(const char *line)
{
    if (*line++ != ' ') {
        return RETURN_FAIL_PRINT_USAGE;
    }
    char *endptr = NULL;
    uint32_t pin = strtol(line, &endptr, 10);
    int32_t val = strtol(endptr, NULL, 0);
    Serial.print("Calling analogWrite(");
    Serial.print(pin);
    Serial.print(", ");
    Serial.print(val);
    Serial.println(").");
    analogWrite(pin,val);
    return RETURN_SUCCESS;
}

#endif /* ARW_CMDS */

#if DM_CMD == 1
static void dumpMemory(uint32_t *address, uint32_t len, uint32_t size)
{
    static char response[80];

    uint8_t *base_addr = (uint8_t*)address;

    int i;
    if (size == 1) {
        for (i=0; i < len; i+=16) {
            uint8_t *addr = base_addr+i;

            // for printing literal values
            uint8_t asciiBytes[16];
            int j;
            for (j=0; j<16; j++) {
                asciiBytes[j] = (addr[j] > 31 && addr[j] < 127) ? addr[j] : '.';
            }

            System_snprintf(response,sizeof(response),
                "0x%x | %02x %02x %02x %02x  %02x %02x %02x %02x  %02x %02x %02x %02x  %02x %02x %02x %02x | %.16s",
                (int)addr,
                addr[0], addr[1], addr[2], addr[3], addr[4], addr[5], addr[6], addr[7],
                addr[8], addr[9], addr[10], addr[11], addr[12], addr[13], addr[14], addr[15],
                asciiBytes);
            Serial.println(response);
        }
    }

    if (size == 2) {
        for (i=0; i < len; i+=8) {
            uint16_t *addr = (uint16_t *)base_addr+i;
            uint8_t *baddr = (uint8_t *)addr;

            // for printing literal values
            uint8_t asciiBytes[16];
            int j;
            for (j=0; j<16; j++) {
                asciiBytes[j] = (baddr[j] > 31 && baddr[j] < 127) ? baddr[j] : '.';
            }

            System_snprintf(response,sizeof(response),
                "0x%x | %04x %04x  %04x %04x  %04x %04x  %04x %04x | %.16s",
                (int)addr,
                addr[0], addr[1], addr[2], addr[3], addr[4], addr[5], addr[6], addr[7],
                asciiBytes);
            Serial.println(response);
        }
    }

    if (size == 4) {
        for (i=0; i < len; i+=4) {
            uint32_t *addr = (uint32_t *)base_addr+i;
            uint8_t *baddr = (uint8_t *)addr;

            // for printing literal values
            uint8_t asciiBytes[16];
            int j;
            for (j=0; j<16; j++) {
                asciiBytes[j] = (baddr[j] > 31 && baddr[j] < 127) ? baddr[j] : '.';
            }

            System_snprintf(response,sizeof(response),
                "0x%x | %08x %08x %08x %08x | %.16s",
                (int)addr,
                addr[0], addr[1], addr[2], addr[3],
                asciiBytes);
            Serial.println(response);
        }
    }
}

static int consoleHandler_dm(const char *line)
{
    static uint32_t address = 0x00000000;
    static uint32_t len = 0x10;
    static uint32_t size = 4;
    static bool repeat = false;
    
    char *endptr;

    if (*line == ' ') {
        address = strtoul(line, &endptr, 16);
        repeat = false;
        if (*endptr == ' ') {
            len = strtoul(endptr, &endptr, 0);
            if (*endptr == ' ') {
                size = strtoul(endptr, &endptr, 10);
                if ((size !=1) && (size != 2) && (size != 4)) {
                    size = 4;
                }
                if (*endptr == ' ') {
                    repeat = true;
                }
            }
        }
    }

    if (len <= 0) {
        Serial.println("Bad number of bytes to dump.");
        return RETURN_FAIL_PRINT_USAGE;
    }

    if (repeat) {
         doRepeat((RepeatFunc)dumpMemory, address, len, size, 0);
    }
    else {
        dumpMemory((uint32_t *)address, len, size);
    }

    return RETURN_SUCCESS;
}

#endif /* DM_CMD */

#if WM_CMD == 1

static int consoleHandler_wm(const char *line)
{
    char *endptr;
    uint32_t word = 0;
    uint32_t *ptr;

    if (*line != ' ') {
        return RETURN_FAIL_PRINT_USAGE;
    }

    ptr = (uint32_t *)strtoul(line, &endptr, 16);

    if (*endptr != ' ') {
        return RETURN_FAIL_PRINT_USAGE;
    }

    while (*endptr)  {
        word = strtol(endptr , &endptr, 16);
        *ptr++ = word;
    }

    return RETURN_SUCCESS;
}

static int consoleHandler_wm1(const char *line)
{
    char *endptr;
    uint8_t word = 0;
    uint8_t *ptr;

    if (*line != ' ') {
        return RETURN_FAIL_PRINT_USAGE;
    }

    ptr = (uint8_t *)strtoul(line, &endptr, 16);

    if (*endptr != ' ') {
        return RETURN_FAIL_PRINT_USAGE;
    }

    while (*endptr)  {
        word = strtol(endptr , &endptr, 16);
        *ptr++ = word;
    }

    return RETURN_SUCCESS;
}

static int consoleHandler_wm2(const char *line)
{
    char *endptr;
    uint16_t word = 0;
    uint16_t *ptr;

    if (*line != ' ') {
        return RETURN_FAIL_PRINT_USAGE;
    }

    ptr = (uint16_t *)strtoul(line, &endptr, 16);

    if (*endptr != ' ') {
        return RETURN_FAIL_PRINT_USAGE;
    }

    while (*endptr)  {
        word = strtol(endptr , &endptr, 16);
        *ptr++ = word;
    }

    return RETURN_SUCCESS;
}

#endif /* WM_CMD */

#if SPI_CMD == 1

static int consoleHandler_spi(const char *line)
{
    static bool spiBegun = false;

    if (*line++ != ' ') {
        return RETURN_FAIL_PRINT_USAGE;
    }
    char *endptr = NULL;
    uint32_t data;
    uint32_t cs = 0;

    if (spiBegun == false) {
        SPI.begin();
        spiBegun = true;
    }

    data = strtol(line, &endptr, 10);

    if (*endptr == ' ') {
        cs = data;
        data = strtol(endptr, &endptr, 10);
    }

    Serial.print("Calling SPI.transfer(");
    if (cs) {
        Serial.print(cs);
        Serial.print(", ");
    }
    Serial.print(data);
    Serial.println(").");
    
    if (cs) {
        SPI.transfer(cs, data);
    }
    else {
        SPI.transfer(data);
    }
    return RETURN_SUCCESS;
}

#endif /* SPI_CMD */

#if STATS_CMD == 1

static char *getModeStr(xdc_UInt mode)
{
    switch (mode) {
        case Task_Mode_RUNNING:
            return((char *)"RUNNING");
        case Task_Mode_READY:
            return((char *)"READY");
        case Task_Mode_BLOCKED:
            return((char *)"BLOCKED");
        case Task_Mode_TERMINATED:
            return((char *)"TERMINATED");
        case Task_Mode_INACTIVE:
            return((char *)"INACTIVE");
    }
    return(NULL);
}

static void printTaskInfo(Task_Handle task)
{
    Task_Stat taskStat;
    Load_Stat loadStat;
    xdc_String name;
    static char buf[100];
    uint32_t loadInt, loadFrac;

    Task_stat(task, &taskStat);
    Load_getTaskLoad(task, &loadStat);

    if (taskStat.priority == 0) {
        name = (xdc_String)"Idle";
    }
    else {
        name = Task_Handle_name(task);
        if (name[0] == '{') {
            name = (xdc_String)"Unnamed";
        }
    }

    /* only show 1 decimal place of precision */
    /* System_snprintf() does not support %2.1f */ 
    loadInt = 100.0*(float)loadStat.threadTime/(float)loadStat.totalTime;
    loadFrac = 1000.0*(float)loadStat.threadTime/(float)loadStat.totalTime - 10.0*loadInt;
  
    /* use System_snprintf() because it uses 500 fewer bytes of stack than snprintf() */ 
    System_snprintf(buf, sizeof(buf),
          " task: %s/0x%x, pri: %d, stack usage: %d/%d, mode: %s load: %d.%1u",
          name, task, taskStat.priority, taskStat.used, taskStat.stackSize, getModeStr(taskStat.mode),
          loadInt, loadFrac);
    Serial.println(buf);
}

static void printUtilization()
{
    xdc_UInt i;
    Memory_Stats memStat;
    Hwi_StackInfo hwiStackStat;
    Load_Stat loadStat;
    Task_Handle tsk;
    float idleLoad;
    uint32_t idleLoadInt, idleLoadFrac;

    /* collect current stats */
    Load_update();   

    /* use time NOT spent in idle task for Total CPU Load */ 
    Load_getTaskLoad(Task_getIdleTask(), &loadStat);
    idleLoad = 100.0 - 100.0*(float)loadStat.threadTime/(float)loadStat.totalTime;
    idleLoadInt = idleLoad;
    idleLoadFrac = 10.0*idleLoad - 10.0*idleLoadInt;
 
    Serial.write("Total CPU Load: ");
    Serial.print(idleLoadInt);
    Serial.print(".");
    Serial.println(idleLoadFrac);
    Serial.println("");
    
    /* collect stats on all statically Created tasks */
    Serial.println("Task info:");
    for (i = 0; i < Task_Object_count(); i++) {
        tsk = Task_Object_get(NULL, i);
        printTaskInfo(tsk);
    }

    /* collect stats on all dynamically Created tasks */
    tsk = Task_Object_first();
    while (tsk) {
        printTaskInfo(tsk);
        tsk = Task_Object_next(tsk);
    }
    Serial.println("");

    Hwi_getStackInfo(&hwiStackStat, TRUE);
    Serial.print("Hwi stack usage: ");
    Serial.print(hwiStackStat.hwiStackPeak);
    Serial.print("/");
    Serial.println(hwiStackStat.hwiStackSize);
    Serial.println("");
    
    Memory_getStats(NULL, &memStat);
    Serial.print("Heap usage: ");
    Serial.print(memStat.totalSize - memStat.totalFreeSize);
    Serial.print("/");
    Serial.println(memStat.totalSize);
}

static int consoleHandler_stats(const char *line)
{
    if (*line == ' ') {
        doRepeat((RepeatFunc)printUtilization, 0, 0, 0, 0);
    }
    else {
        printUtilization();
    }
    return RETURN_SUCCESS;
}

#endif /* STATS_CMD */

#if PRI_CMD == 1

static int consoleHandler_pri(const char *line)
{
    Task_Handle tsk;
    char *endptr;
    int pri = 3;
    if (*line != ' ') {
        return RETURN_FAIL_PRINT_USAGE;
    }

    tsk = (Task_Handle)strtoul(line, &endptr, 16);
    pri = strtol(endptr, NULL, 10);

    if ((pri < -1) || (pri >= (int)Task_numPriorities)) {
        Serial.println("Invalid priority!");
        return RETURN_FAIL_PRINT_USAGE;
    }
    
    Task_setPri(tsk, pri);
    
    return RETURN_SUCCESS;
}

#endif /* PRI_CMD */

