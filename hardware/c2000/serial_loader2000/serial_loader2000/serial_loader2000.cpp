// serial_loader2000.cpp : Defines the entry point for the console application.
//

#ifndef __linux__
#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <dos.h>
#endif

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//// Linux exclusive
#ifdef __linux__

#include <string.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int _kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

#define TRUE true
#define FALSE false

typedef unsigned long DWORD;
typedef unsigned short WORD;

#define _tfopen     fopen
#define wchar_t char
#define fscanf_s fscanf
#define _tmain main
//////////////////

#define _tcslen     strlen
#define _tcscpy     strcpy
#define _tcscpy_s   strcpy_s
#define _tcsncpy    strncpy
#define _tcsncpy_s  strncpy_s
#define _tcscat     strcat
#define _tcscat_s   strcat_s
#define _tcsupr     strupr
#define _tcsupr_s   strupr_s
#define _tcslwr     strlwr
#define _tcslwr_s   strlwr_s

#define _stprintf_s sprintf_s
#define _stprintf   sprintf
#define _tprintf    printf

#define _vstprintf_s    vsprintf_s
#define _vstprintf      vsprintf

#define _tscanf     scanf

#define TCHAR char

#define _T(x) x

////////////////////

#endif




//*****************************************************************************
//
// Helpful macros for generating output depending upon verbose and quiet flags.
//
//*****************************************************************************
#define VERBOSEPRINT(...) if(g_bVerbose) { _tprintf(__VA_ARGS__); }
#define QUIETPRINT(...) if(!g_bQuiet) { _tprintf(__VA_ARGS__); }

//*****************************************************************************
//
// Globals whose values are set or overridden via command line parameters.
//
//*****************************************************************************
bool g_bVerbose = false;
bool g_bQuiet = false;
bool g_bOverwrite = false;
bool g_bUpload = false;
bool g_bClear = false;
bool g_bBinary = false;
bool g_bWaitOnExit = false;
bool g_bReset = false;
bool g_bSwitchMode = false;
wchar_t *g_pszAppFile = NULL;
wchar_t *g_pszKernelFile = NULL;
wchar_t *g_pszComPort = NULL;
wchar_t *g_pszBaudRate;

int g_iDeviceIndex = 0;

//COM Port stuff
#ifdef __linux__
int fd;
#else
HANDLE file;
DCB port;
#endif
//*****************************************************************************
//
// Exit the application, optionally pausing for a key press first.
//
//*****************************************************************************
void
ExitApp(int iRetcode)
{

	//
	// Has the caller asked us to pause before exiting?
	//
	if (g_bWaitOnExit)
	{
		_tprintf(_T("\nPress any key to exit...\n"));
		while (!_kbhit())
		{
			//
			// Wait for a key press.
			//
		}
	}

	exit(iRetcode);
}

//*****************************************************************************
//
// Display the welcome banner when the program is started.
//
//*****************************************************************************
void
PrintWelcome(void)
{
	if (g_bQuiet)
	{
		return;
	}

	_tprintf(_T("\nC2000 Serial Firmware Upgrader\n"));
	_tprintf(_T("Copyright (c) 2013 Texas Instruments Incorporated.  All rights reserved.\n\n"));
}

//*****************************************************************************
//
// Show help on the application command line parameters.
//
//*****************************************************************************
void
ShowHelp(void)
{
	//
	// Only print help if we are not in quiet mode.
	//
	if (g_bQuiet)
	{
		return;
	}

	_tprintf(_T("This application may be used to download images to a Texas Instruments\n"));
	_tprintf(_T("C2000 microcontroller in the SCI boot mode.\n\n"));
	_tprintf(_T("Supported parameters are:\n\n"));

	_tprintf(_T("-f <file>    - The file name for download use.\n"));
	_tprintf(_T("               This file must be in the SCI boot format.\n"));
	_tprintf(_T("-k <file>    - The file name for flash kernel.\n"));
	_tprintf(_T("               This file must be in the SCI boot format.\n"));
	_tprintf(_T("-p COM<num>  - Set the COM port to be used for communications.\n"));
	_tprintf(_T("-b <num>     - Set the baud rate for the COM port.\n"));
	_tprintf(_T("-? or -h     - Show this help.\n"));
	_tprintf(_T("-q           - Quiet mode. Disable output to stdio.\n"));
	_tprintf(_T("-w           - Wait for a key press before exiting.\n"));
	_tprintf(_T("-v           - Enable verbose output\n\n"));
	_tprintf(_T("-f, -k, and -p are mandatory parameters.  If baud rate is omitted, \nthe communications will occur at 9600 baud.\n\n"));


	_tprintf(_T("Example:\n\n"));
	_tprintf(_T("serial_loader2000 -f application.txt -k flash_kernel.txt -p COM4 -b 38400\n"));
	_tprintf(_T("Writes an application in application.txt to flash of the target device using\n"));
    _tprintf(_T("the kernel in flash_kernel.txt.  COM port 4 is used to do the load \nat 38400 Baud.\n\n"));

	_tprintf(_T("Application and kernel files must be in the SCI8 boot format. \nThese can be generated using the hex2000 utility.  An example of how to do \nthis follows:\nhex2000 application.out -boot -sci8 -a -o application.txt\n\n"));


}

//*****************************************************************************
//
// Parse the command line, extracting all parameters.
//
// Returns 0 on success. On failure, calls ExitApp(1).
//
//*****************************************************************************
int
ParseCommandLine(int argc, wchar_t *argv[])
{
	int iParm;
	bool bShowHelp;
	wchar_t *pcOptArg;

	//
	// By default, don't show the help screen.
	//
	bShowHelp = false;

	// Set the default baud rate
    #ifdef __linux__
    g_pszBaudRate = (char *)"9600";
    #else
	g_pszBaudRate = L"9600";
    #endif
	//
	// Walk through each of the parameters in the list, skipping the first one
	// which is the executable name itself.
	//
	for (iParm = 1; iParm < argc; iParm++)
	{
		//
		// Does this look like a valid switch?
		//
		if (!argv || ((argv[iParm][0] != L'-') && (argv[iParm][0] != L'/')) ||
			(argv[iParm][1] == L'\0'))
		{
			//
			// We found something on the command line that didn't look like a
			// switch so bomb out.
			//
			_tprintf(_T("Unrecognized or invalid argument: %s\n"), argv[iParm]);
			ExitApp(1);
		}
		else
		{
			//
			// For convenience, get a pointer to the next argument since this
			// is often a parameter for a given switch (and since this code was
			// converted from a previous version which used getopt which is not
			// available in the Windows SDK).
			//
			pcOptArg = ((iParm + 1) < argc) ? argv[iParm + 1] : NULL;
		}

		switch (argv[iParm][1])
		{
		case 'w':
			g_bWaitOnExit = true;
			break;

		case 'f':
			g_pszAppFile = pcOptArg;
			iParm++;
			break;

		case 'k':
			g_pszKernelFile = pcOptArg;
			iParm++;
			break;

		case 'b':
			g_pszBaudRate = pcOptArg;
			iParm++;
			break;

		case 'p':
			g_pszComPort = pcOptArg;
			iParm++;
			break;

		case 'v':
			g_bVerbose = TRUE;
			break;

		case 'q':
			g_bQuiet = TRUE;
			break;

		case 'x':
			g_bOverwrite = TRUE;
			break;

		case '?':
		case 'h': 
			bShowHelp = TRUE;
			break;

		default:
			_tprintf(_T("Unrecognized argument: %s\n"), argv[iParm]);
			ExitApp(1);
		}
	}

	//
	// Show the welcome banner unless we have been told to be quiet.
	//
	PrintWelcome();

	//
	// Show the help screen if requested.
	//
	if (bShowHelp)
	{
		ShowHelp();
		ExitApp(0);
	}

	//
	// Catch various invalid or pointless parameter cases.
	//
	if (!g_pszAppFile || !g_pszKernelFile || !g_pszComPort)
	{
		//
		// No file name provided.  If we haven't displayed it already,
		// show command line help then display the error information.
		//
		ShowHelp();

		if (!g_pszAppFile)
		{
			QUIETPRINT(_T("ERROR: No application file name was specified. Please use -f to provide one.\n"));
		}
		if (!g_pszKernelFile)
		{
			QUIETPRINT(_T("ERROR: No flash kernel file name was specified. Please use -k to provide one.\n"));
		}
		if (!g_pszComPort)
		{
			QUIETPRINT(_T("ERROR: No COM port number was specified. Please use -p to provide one.\n"));
		}

		ExitApp(1);
	}

	

	//
	// Tell the caller that everything is OK.
	//
	return(0);
}



//*****************************************************************************
//
// Download an image to the the device identified by the passed handle.  The
// image to be downloaded and other parameters related to the operation are
// controlled by command line parameters via global variables.
//
// Returns 0 on success or a positive error return code on failure.
//
//*****************************************************************************
int
DownloadImage(void)
{
	FILE *Kfh;
	FILE *Afh;
	

	unsigned int rcvData = 0;
	unsigned int rcvDataH = 0;
	int txCount = 0;

	uint16_t checksum;
	unsigned int fileStatus;
	DWORD dwRead;
    #ifdef __linux__
    unsigned char buf[8];
	int readf;
	unsigned int sendData[8];
	#else
	errno_t error;
	DWORD dwWritten;
	unsigned char sendData[8];
	#endif

	QUIETPRINT(_T("Downloading %s to device...\n"), g_pszAppFile);



	//
	// Does the input file exist?
	//
	// Opens the Flash Kernel File
    #ifdef  __linux__
	Kfh = fopen(g_pszKernelFile, _T("rb"));
	#else
	error = _wfopen_s(&Kfh, g_pszKernelFile, _T("rb"));
    #endif
	if (!Kfh)
	{
		QUIETPRINT(_T("Unable to open Kernel file %s. Does it exist?\n"), g_pszAppFile);
		return(10);
	}

    //Opens the application file 
    #ifdef __linux__
    Afh = fopen(g_pszAppFile, _T("rb"));
    #else
	error = _wfopen_s(&Afh, g_pszAppFile, L"rb");
	#endif
	if (!Afh)
	{
		QUIETPRINT(_T("Unable to open Application file %s. Does it exist?\n"), g_pszAppFile);
		return(10);
	}

	//Both Kernel, Application, and COM port are open
	//Time to blow an go!

	//Do AutoBaud
 	dwRead = 0;
	sendData[0] = 'A';
	#ifdef __linux__
	write(fd, &sendData[0], 1);
    while (dwRead == 0)
    {

    	readf = read(fd,&buf,1);
        if(readf == -1)
        {
        	QUIETPRINT(_T("Error %s\n"), strerror(errno));
        }
        dwRead = readf;
        rcvData = buf[0];
    	if(readf == 0)
    	{
    	write(fd, &sendData[0], 1);
    	}
    }
	#else
	WriteFile(file, &sendData[0], 1, &dwWritten, NULL);
	while (dwRead == 0)
	{
		ReadFile(file, &rcvData, 1, &dwRead, NULL);
	}
    #endif

	if (sendData[0] != rcvData)
		return(12);


	VERBOSEPRINT(_T("\nKernel AutoBaud Successful"));
	//Find the start of the kernel data
	#ifndef __linux__
	getc(Kfh);
	getc(Kfh);
	#endif
	getc(Kfh);

	fileStatus = fscanf_s(Kfh, "%x", &sendData[0]);
    int i = 0;
	while (fileStatus == 1)
	{
		i++;

		//Send next char

	 	#ifdef __linux__
		write(fd,&sendData[0],1);
		//usleep(10000);
		#else
		WriteFile(file, &sendData[0], 1, &dwWritten, NULL);
		#endif

		//Read next char

		fileStatus = fscanf_s(Kfh, "%x", &sendData[0]);
	}

	VERBOSEPRINT(_T("\nKernel Loaded"));
	#ifdef __linux__
	sleep(5);
	#else
	Sleep(5000);
	#endif
	VERBOSEPRINT(_T("\nDone Waiting for kernel boot...attempting autobaud"));
	#ifdef __linux__
		if(tcflush(fd,TCIOFLUSH)== 0)
		{
			//printf("Input and Output successfully flushed");
		}
		else
		{
			perror("tcflush error");
		}
	#else
	    PurgeComm(file, PURGE_RXCLEAR);
    #endif


	//Do AutoBaud
	sendData[0] = 'A';
	#ifdef __linux__
	write(fd,&sendData[0],1);
	buf[0] = 0;
    dwRead = 0;
   // int counter = 0 ;
    while (dwRead == 0)
    {
    	//counter++;
     	readf = read(fd,&buf,1);
        if(readf == -1)
        {
        	QUIETPRINT(_T("Error %s\n"), strerror(errno));
        }
        dwRead = readf;
        rcvData = buf[0];
    }

    #else
	    WriteFile(file, &sendData[0], 1, &dwWritten, NULL);

	dwRead = 0;
	while (dwRead == 0)
	{
		ReadFile(file, &rcvData, 1, &dwRead, NULL);
	}
    #endif


	if (sendData[0] != rcvData)
		return(12);

	VERBOSEPRINT(_T("\nApplication AutoBaud Successful"));
	//Find the start of the application data
	txCount = 0;
	checksum = 0;
	#ifndef __linux__
	getc(Afh);
	getc(Afh);
	#endif
	getc(Afh);



	while (txCount < 22)
	{
		txCount++;
		fscanf_s(Afh, "%x", &sendData[0]);
		checksum += sendData[0];
		//Send next char
		#ifdef __linux__
		   write(fd,&sendData[0],1);
		#else
		   WriteFile(file, &sendData[0], 1, &dwWritten, NULL);
        #endif
	}
	dwRead = 0;
	while (dwRead == 0)
	{
		#ifdef __linux__
    	readf = read(fd,&buf,1);
        if(readf == -1)
        {
        	QUIETPRINT(_T("Error %s\n"), strerror(errno));
        }
        dwRead = readf;
        rcvData = buf[0];
		#else
		ReadFile(file, &rcvData, 1, &dwRead, NULL);
	    #endif
	}	
	dwRead = 0;
	while (dwRead == 0)
	{
	    #ifdef __linux__
    	readf = read(fd,&buf,1);
        if(readf == -1)
        {
        	QUIETPRINT(_T("Error %s\n"), strerror(errno));
        }
        dwRead = readf;
        rcvDataH = buf[0];
		#else
		ReadFile(file, &rcvDataH, 1, &dwRead, NULL);
	    #endif
	}

	//Ensure checksum matches
	if (checksum != (rcvData | (rcvDataH << 8)))
		return(12);


	//RONNIES CODE
	int wordData;
	int byteData;
	txCount = 0;
	checksum = 0;

	int totalCount = 0;
	wordData = 0x0000;
	byteData = 0x0000;
	fileStatus = 1;

	//Load the flash kernel
	while (1){

		fileStatus = fscanf_s(Afh, "%x ", &sendData[0]);
		if (fileStatus == 0)
			break;
		#ifdef __linux__
        write(fd,&sendData[0],1);
		#else
		WriteFile(file, &sendData[0], 1, &dwWritten, NULL);
		#endif
		checksum += sendData[0];

		// Get a dest addr
		if (txCount == 0x00)
		{
			wordData = sendData[0];
		}
		else if (txCount == 0x01)
		{
			byteData = sendData[0];
			// form the wordData from the MSB:LSB
			wordData |= (byteData << 8);
		}

		txCount++;
		totalCount++;

		//If the next block size is 0, exit the while loop. 
		if (wordData == 0x00 && txCount > 1)
		{



			wordData = 0x0000;
			byteData = 0x0000;

			break;
		}
		//If the block size is bigger than 0x400 words, every 0x400 words later it takes time for flash program. Them waiting for feedback.
		else if ((txCount - 6) % 0x800 == 0 && txCount > 6)
		{
			dwRead = 0;
			while (dwRead == 0)
			{
			    #ifdef __linux__
		    	readf = read(fd,&buf,1);
		        if(readf == -1)
		        {
		        	QUIETPRINT(_T("Error %s\n"), strerror(errno));
		        }
		        dwRead = readf;
		        rcvData = buf[0];
		        #else
				ReadFile(file, &rcvData, 1, &dwRead, NULL);
				#endif
			}
			dwRead = 0;
			while (dwRead == 0)
			{
				#ifdef __linux__
		    	readf = read(fd,&buf,1);
		        if(readf == -1)
		        {
		        	QUIETPRINT(_T("Error %s\n"), strerror(errno));
		        }
		        dwRead = readf;
		        rcvDataH = buf[0];
				#else
				ReadFile(file, &rcvDataH, 1, &dwRead, NULL);
			    #endif
			}
			//Ensure checksum matches
			if (checksum != (rcvData | (rcvDataH << 8)))
				return(12);
			else
				checksum = 0;
		}
		//If CountInt meets the block size, countint and dest addr will be initialized. 
		else if (txCount == 2 * (wordData + 3))
		{
			dwRead = 0;
			while (dwRead == 0)
			{
				#ifdef __linux__
		    	readf = read(fd,&buf,1);
		        if(readf == -1)
		        {
		        	QUIETPRINT(_T("Error %s\n"), strerror(errno));
		        }
		        dwRead = readf;
		        rcvData = buf[0];
				#else
				ReadFile(file, &rcvData, 1, &dwRead, NULL);
			    #endif
			}
			dwRead = 0;
			while (dwRead == 0)
			{
				#ifdef __linux__
		    	readf = read(fd,&buf,1);
		        if(readf == -1)
		        {
		        	QUIETPRINT(_T("Error %s\n"), strerror(errno));
		        }
		        dwRead = readf;
		        rcvDataH = buf[0];
				#else				
				ReadFile(file, &rcvDataH, 1, &dwRead, NULL);
				#endif
			}
			//Ensure checksum matches
			if (checksum != (rcvData | (rcvDataH << 8)))
				return(12);
			else
				checksum = 0;

			wordData = 0x0000;
			byteData = 0x0000;
			txCount = 0x00;
		}
	}
	VERBOSEPRINT(_T("\nApplication Load Successful"));

	//not sure if should add?
    return 0;
}

//*****************************************************************************
//
// The main entry point of the DFU programmer example application.
//
//*****************************************************************************

int
_tmain(int argc, TCHAR* argv[])
{

	
	int iExitCode = 0;

	//
	// Parse the command line parameters, print the welcome banner and
	// tell the user about any errors they made.
	//
	ParseCommandLine(argc, argv);

	//Try opening the COM Port
	// open the comm port.


	///For Linux
    #ifdef __linux__
    // Get Baud Rate 
	int speed = atoi(g_pszBaudRate); 
    // Open Port for linux - comes in the form of  dev/ttyUSB#
	const char * portname = g_pszComPort;
    fd = open(portname, O_RDWR | O_NOCTTY );
    if(fd == -1)
    {
    	printf("error %d opening %s: %s", errno, portname, strerror (errno));
        ExitApp(1);
    }
     
    // Creates structure for configurations
    struct termios newtio;

	bzero(&newtio, sizeof(newtio));
	newtio.c_cflag = CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
	newtio.c_oflag = 0;
    cfsetospeed(&newtio, speed);  //set baudrate
    cfsetispeed(&newtio, speed);
	/* set input mode (non-canonical, no echo,...) */
	newtio.c_lflag = 0;

	newtio.c_cc[VTIME]    = 5;   /* inter-character timer unused */
	newtio.c_cc[VMIN]     = 0;   /* blocking read until 5 chars received */

	tcflush(fd, TCIOFLUSH);   // flushes the input
	tcsetattr(fd,TCSANOW,&newtio); // sets the configurations

    //For Windows
    #else

	int iRetCode = 0;
	TCHAR baudString[32];
	TCHAR comString[32];

	//Append stupid windows crap to COM port name
	_stprintf_s(comString, _T("\\\\.\\%s"), g_pszComPort);
	file = CreateFile((LPCWSTR)comString,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);

	//Check if COM port opened correctly
	if (INVALID_HANDLE_VALUE == file) {
		QUIETPRINT(_T("Unable to open COM port %s...does someone else have it open?\n"), g_pszComPort);
		ExitApp(1);
	}
    
    //Append baudrate to config string
	_stprintf_s(baudString, _T("%s,n,8,1"), g_pszBaudRate);



	// get the current DCB, and adjust a few bits to our liking.
	memset(&port, 0, sizeof(port));
	port.DCBlength = sizeof(port);
	iRetCode = GetCommState(file, &port);
	if (iRetCode)
	{
		QUIETPRINT(_T("getting comm state \n"));
	}
	else
	{
		QUIETPRINT(_T("Problem Getting Comm State \n"));
		ExitApp(iExitCode);
	}


	iRetCode = BuildCommDCB((LPCTSTR)baudString, &port);
	if (iRetCode)
	{
		QUIETPRINT(_T("building comm DCB\n"));
	}
	else
	{
		QUIETPRINT(_T("Problem Building DCB...are your parameters correct? \n"));
		ExitApp(iExitCode);
	}

	iRetCode = SetCommState(file, &port);
	if (iRetCode)
	{
		QUIETPRINT(_T("adjusting port settings\n"));
	}
	else
	{
		QUIETPRINT(_T("Problem setting port configuration \n"));
		ExitApp(iExitCode);
	}
    #endif

	DownloadImage();
	
	#ifdef __linux__
    close(fd);
	#endif
	ExitApp(iExitCode);


	
}


