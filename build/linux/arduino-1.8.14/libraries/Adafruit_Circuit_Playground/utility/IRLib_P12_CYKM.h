/* IRLib_P12_CYKM.h
  Chris Young keyboard mouse protocol 
  See COPYRIGHT.txt and LICENSE.txt for license information (spoilers it's GPL 3) 
  
  This library implements a custom protocol for IRLib to assist in creating 
  Arduino based mouse and keyboard controls. Documentation will be updated soon.
  
  Protocol information: Header 3100, 3100
      Zero bit: 650, 650, 
      One bit:  650*3, 650, 38 kHz, stop=true
      15 bits of data which means 34 intervals of marks and spaces
  Description of bits high order to low order
    3 bits: Command: 3 bits 
      0 mouse click
      1 mouse hold
      2 mouse move
      3 mouse and keyboard toggle
      4 keyboard hold
      5 keyboard write
      6 speed command
      7 Custom devices
    4 bits: Modifier one time use. Only valid for mouse click, 
            mouse hold and keyboard write and hold not toggles
      1 Shift
      2 Control
      4 Alt
      8 GUI
    8 bits: data
      If mouse click or hold or toggle
        1 left click
        2 right click
        4 middle click
      If mouse move 
        1 right, 2 left, 4 up, 8 down
        0x10 wheel up, 0x20 wheel down
        0x40 increase speed, 0x80 decrease speed    
      If keyboard hold or key write then ASCII or Arduino code
      If speed command = absolute speed 0 to 255
      If Toggle 255= clear everything
      If custom devices… To be determined later.
*/

#define CYKM_MOUSE_CLICK 0x0000
#define CYKM_MOUSE_HOLD 0x1000
#define CYKM_MOUSE_MOVE 0x2000
#define CYKM_TOGGLE 0x3000
#define CYKM_KEY_HOLD 0x4000
#define CYKM_KEY_WRITE 0x5000
#define CYKM_SPEED 0x6000
#define CYKM_CUSTOM_DEVICE 0x7000
#define CYKM_SHIFT  0x100
#define CYKM_CONTROL  0x200
#define CYKM_ALT  0x400
#define CYKM_GUI  0x800
#define CYKM_LEFT_BUTTON 1
#define CYKM_RIGHT_BUTTON 2
#define CYKM_MIDDLE_BUTTON 4
#define CYKM_DIR_RIGHT  0x01
#define CYKM_DIR_LEFT  0x02
#define CYKM_DIR_UP  0x04
#define CYKM_DIR_DOWN  0x08
#define CYKM_WHEEL_UP  0x10
#define CYKM_WHEEL_DOWN  0x20
#define CYKM_SPEED_INCREASE  0x40
#define CYKM_SPEED_DECREASE  0x80
#define CYKM_TOGGLE_LEFT    0x01
#define CYKM_TOGGLE_RIGHT   0x02
#define CYKM_TOGGLE_MIDDLE  0x04
#define CYKM_TOGGLE_SHIFT   0x08
#define CYKM_TOGGLE_CONTROL 0x10
#define CYKM_TOGGLE_ALT     0x20
#define CYKM_TOGGLE_GUI     0x40
#define CYKM_TOGGLE_RESET   0xff
#ifndef IRLIB_PROTOCOL_12_H
#define IRLIB_PROTOCOL_12_H
#define IR_SEND_PROTOCOL_12		case 12: IRsendCYKM::send(data); break;
#define IR_DECODE_PROTOCOL_12	if(IRdecodeCYKM::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_12 ,public virtual IRdecodeCYKM
	#define PV_IR_SEND_PROTOCOL_12   ,public virtual IRsendCYKM
#else
	#define PV_IR_DECODE_PROTOCOL_12  public virtual IRdecodeCYKM
	#define PV_IR_SEND_PROTOCOL_12    public virtual IRsendCYKM
#endif

#if defined(__AVR_ATmega32U4__) || defined(ARDUINO_SAM_DUE) || defined(ARDUINO_SAM_ZERO)
  #include <Keyboard.h>
  #include <Mouse.h>
  #include <HID.h>
#endif

#ifdef IRLIBSENDBASE_H
class IRsendCYKM: public virtual IRsendBase {
  public:
    void send(uint32_t data) {
      sendGeneric(data,15, 3100, 3100, 650, 650, 650*3, 650, 38, true);
      delay(10);
    };
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H
class IRdecodeCYKM: public virtual IRdecodeBase {
  public:
    bool decode(void) {
      IRLIB_ATTEMPT_MESSAGE(F("CYKM"));
      if(!decodeGeneric(34,3100,3100,650,650*3,650)) return false;
      protocolNum = CYKM;
      parseValue();
      return true;
    }
    virtual void dumpResults(void){
      Serial.print(F("Gap=")); Serial.print(recvGlobal.decodeBuffer[0],DEC);
      Serial.print(F(" CYKM decoded:")); Serial.print(value,HEX);Serial.print("  ");
      switch (cmdType) {
        case CYKM_MOUSE_CLICK: //deliberate fall through
        case CYKM_MOUSE_HOLD:
          Serial.print(F("Mouse ")); 
          showMods();
          switch(cmdData) {
            case CYKM_LEFT_BUTTON: Serial.print(F("left"));break;  
            case CYKM_RIGHT_BUTTON: Serial.print(F("right"));break;  
            case CYKM_MIDDLE_BUTTON: Serial.print(F("middle"));break;  
            default: Serial.println(F("ERROR"));  
          };
          if (cmdType==CYKM_MOUSE_CLICK)Serial.println(F(" click")); else Serial.println(F(" hold"));
          break;
        case CYKM_MOUSE_MOVE: 
          if(cmdData & (CYKM_DIR_RIGHT|CYKM_DIR_LEFT|CYKM_DIR_UP|CYKM_DIR_DOWN)){
            Serial.print(F("Mouse move "));
            if(cmdData & CYKM_DIR_RIGHT) Serial.print(F("right ")); else if(cmdData & CYKM_DIR_LEFT) Serial.print(F("left "));
            if(cmdData & CYKM_DIR_UP) Serial.print(F("up ")); else if(cmdData & CYKM_DIR_DOWN) Serial.print(F("down "));
          } else {
            if(cmdData & (CYKM_WHEEL_UP|CYKM_WHEEL_DOWN)){
              Serial.print(F("Mouse Wheel "));
              if(cmdData & CYKM_DIR_UP) Serial.print(F("up ")); else Serial.print(F("down "));
            } else {
              if (cmdData & CYKM_SPEED_DECREASE) {
                Serial.print(F("Decrease speed from ")); 
              } else {
                if (cmdData & CYKM_SPEED_INCREASE) {
                  Serial.print(F("Increase speed from "));
                } else Serial.println(F("Mouse Move Error"));
              }
            };
          };
          Serial.println(mouseSpeed,DEC);
          break;  
        case CYKM_TOGGLE: 
          Serial.print(F("Toggle"));
          if(cmdData==CYKM_TOGGLE_RESET) {
            Serial.print(F(" clear all"));
          } else {
            if(cmdData & CYKM_TOGGLE_LEFT) Serial.print(F(" left button"));
            if(cmdData & CYKM_TOGGLE_RIGHT) Serial.print(F(" right button"));
            if(cmdData & CYKM_TOGGLE_MIDDLE) Serial.print(F(" middle button"));
            if(cmdData & CYKM_TOGGLE_SHIFT ) Serial.print(F(" shift key"));
            if(cmdData & CYKM_TOGGLE_CONTROL) Serial.print(F(" control key"));
            if(cmdData & CYKM_TOGGLE_ALT) Serial.print(F(" alt key"));
            if(cmdData & CYKM_TOGGLE_GUI) Serial.print(F(" GUI"));
          }
          Serial.print(F(" Bits= "));Serial.println(toggleData,HEX);
          break;  
        case CYKM_KEY_WRITE:
        case CYKM_KEY_HOLD:
          if (cmdType==CYKM_KEY_WRITE) {
            Serial.print(F("Key write"));showMods();
          } else {
          Serial.print(F("Key hold")); 
          };
          Serial.print(F(" value:")); Serial.print(cmdData,HEX); Serial.print("  "); Serial.print(cmdData,DEC);
          if((cmdData>31) && (cmdData< 128)) {Serial.print(" '"); Serial.write(cmdData);Serial.print("'");};
          Serial.println();
          break;  
        case CYKM_SPEED:
          Serial.print(F("Change speed to:")); Serial.println(cmdData,DEC);
          break;
        case CYKM_CUSTOM_DEVICE: Serial.print(F("Custom Device data:")); Serial.println(cmdData,HEX);
      };

    };  
    void doMouseKeyboard(void){
      #if defined(__AVR_ATmega32U4__) || defined(ARDUINO_SAM_DUE) || defined(ARDUINO_SAM_ZERO)
      int8_t Button; 
      int8_t xDir=0; int8_t yDir=0; int8_t wDir=0;
      switch (cmdType) {
        case CYKM_MOUSE_CLICK: //deliberate fall through
        case CYKM_MOUSE_HOLD:
          doMods (true); //presses modifier key
          switch(cmdData) {
            case CYKM_LEFT_BUTTON: Button= MOUSE_LEFT; break;  
            case CYKM_RIGHT_BUTTON: Button= MOUSE_RIGHT; break;  
            case CYKM_MIDDLE_BUTTON: Button= MOUSE_MIDDLE; break;  
          };
          //only release if this was a click and not a hold
          if (cmdType==CYKM_MOUSE_CLICK) {
            Mouse.click(Button); doMods(false);
          } else Mouse.press(Button);
          break;
        case CYKM_MOUSE_MOVE: 
          if(cmdData & CYKM_DIR_RIGHT) xDir=mouseSpeed; else if(cmdData & CYKM_DIR_LEFT)   xDir= -mouseSpeed;
          //NOTE: Upper left corner is 0, 0 and positive numbers go down
          if(cmdData & CYKM_DIR_UP)    yDir=-mouseSpeed; else if(cmdData & CYKM_DIR_DOWN)   yDir= mouseSpeed;
          if(cmdData & CYKM_WHEEL_UP)  wDir=1; else if(cmdData & CYKM_WHEEL_DOWN) wDir= -1;
          if(xDir || yDir || wDir) {
            Mouse.move(xDir,yDir,wDir);
          } else {
              if ( (cmdData & CYKM_SPEED_DECREASE) && (mouseSpeed>0) ) mouseSpeed--;
              if ( (cmdData & CYKM_SPEED_INCREASE) && (mouseSpeed<=255) ) mouseSpeed++;
          };
          break;  
        case CYKM_TOGGLE: 
          if(cmdData==CYKM_TOGGLE_RESET) {
            Mouse.release(MOUSE_LEFT);
            Mouse.release(MOUSE_RIGHT);
            Mouse.release(MOUSE_MIDDLE);
            Keyboard.releaseAll();
          } else {
            if(cmdData & CYKM_TOGGLE_LEFT) {if(toggleData & CYKM_TOGGLE_LEFT) Mouse.release(MOUSE_LEFT);else Mouse.press(MOUSE_LEFT);};
            if(cmdData & CYKM_TOGGLE_RIGHT) {if(toggleData & CYKM_TOGGLE_RIGHT) Mouse.release(MOUSE_RIGHT);else Mouse.press(MOUSE_RIGHT);};
            if(cmdData & CYKM_TOGGLE_MIDDLE) {if(toggleData & CYKM_TOGGLE_MIDDLE) Mouse.release(MOUSE_MIDDLE);else Mouse.press(MOUSE_MIDDLE);};
            if(cmdData & CYKM_TOGGLE_SHIFT)  {if(toggleData & CYKM_TOGGLE_SHIFT) Keyboard.release(KEY_LEFT_SHIFT);else Keyboard.press(KEY_LEFT_SHIFT);};
            if(cmdData & CYKM_TOGGLE_CONTROL) {
              if(toggleData & CYKM_TOGGLE_CONTROL) Keyboard.release(KEY_LEFT_CTRL);else Keyboard.press(KEY_LEFT_CTRL);
            };
            if(cmdData & CYKM_TOGGLE_ALT)  {if(toggleData & CYKM_TOGGLE_ALT) Keyboard.release(KEY_LEFT_ALT);else Keyboard.press(KEY_LEFT_ALT);};
            if(cmdData & CYKM_TOGGLE_GUI)  {if(toggleData & CYKM_TOGGLE_GUI) Keyboard.release(KEY_LEFT_GUI);else Keyboard.press(KEY_LEFT_GUI);};
            toggleData= toggleData ^ cmdData;
          }
          break;  
        case CYKM_KEY_WRITE:
          doMods(true); //press modifier key
          Keyboard.write(cmdData);
          doMods(false); //release modifier key
          break;
        case CYKM_KEY_HOLD:
          doMods(true);//press modifier key
          Keyboard.press(cmdData);
          //Do not release modifier
          break;  
        case CYKM_SPEED:
          mouseSpeed=cmdData;
          break;
//      case CYKM_CUSTOM_DEVICE: 
//        break;
      };
      #endif
    };
    void doMouseKeyboard(uint16_t code) {
      #if defined(__AVR_ATmega32U4__) || defined(ARDUINO_SAM_DUE) || defined(ARDUINO_SAM_ZERO)
        value=code;
        parseValue();
        doMouseKeyboard();
      #endif
    };
    uint8_t mouseSpeed;
    uint8_t toggleData;
    uint16_t cmdType;
    uint16_t cmdData;
  private:
    void showMods(void){
      if(value & CYKM_SHIFT) Serial.print(F(" shift"));
      if(value & CYKM_CONTROL) Serial.print(F(" control"));
      if(value & CYKM_ALT) Serial.print(F(" alt"));
      if(value & CYKM_GUI) Serial.print(F(" GUI"));
    };  
    void doMods(bool Press){
      #if defined(__AVR_ATmega32U4__) || defined(ARDUINO_SAM_DUE) || defined(ARDUINO_SAM_ZERO)
        if(value & CYKM_SHIFT) {if(Press) Keyboard.press(KEY_LEFT_SHIFT); else Keyboard.release(KEY_LEFT_SHIFT);}
        if(value & CYKM_CONTROL) {if(Press) Keyboard.press(KEY_LEFT_CTRL); else Keyboard.release(KEY_LEFT_CTRL);}
        if(value & CYKM_ALT) {if(Press) Keyboard.press(KEY_LEFT_ALT); else Keyboard.release(KEY_LEFT_ALT);}
        if(value & CYKM_GUI) {if(Press) Keyboard.press(KEY_LEFT_GUI); else Keyboard.release(KEY_LEFT_GUI);}
      #endif
    };
    void parseValue(void) {
      cmdType= value & 0x7000;  //highest order 3 bits command type
      cmdData= value & 0xff; //lowest order 8 bits command data
      //To get Shift,Control,Alt, GUI modifiers do (value & CYKM_SHIFT) etc.
    };
};

#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO
/*
  If you have a board capable of using the "Keyboard.h" library 
  such as a Leonardo then these defines are already defined.
  However suppose you want to transmit a signal for the up arrow
  from an Arduino Uno you would need to look up the value.
  We are going to presume that if KEY_LEFT_CTRL is not defined
  then none of the are defined so we will define here for your convenience.
  */
#ifndef  KEY_LEFT_CTRL
 #define KEY_LEFT_CTRL	0x80
 #define KEY_LEFT_SHIFT	0x81
 #define KEY_LEFT_ALT	0x82
 #define KEY_LEFT_GUI	0x83
 #define KEY_RIGHT_CTRL	0x84
 #define KEY_RIGHT_SHIFT	0x85
 #define KEY_RIGHT_ALT	0x86
 #define KEY_RIGHT_GUI	0x87
 #define KEY_UP_ARROW	0xDA
 #define KEY_DOWN_ARROW	0xD9
 #define KEY_LEFT_ARROW	0xD8
 #define KEY_RIGHT_ARROW	0xD7
 #define KEY_BACKSPACE	0xB2
 #define KEY_TAB	0xB3
 #define KEY_RETURN	0xB0
 #define KEY_ESC	0xB1
 #define KEY_INSERT	0xD1
 #define KEY_DELETE	0xD4
 #define KEY_PAGE_UP	0xD3
 #define KEY_PAGE_DOWN	0xD6
 #define KEY_HOME	0xD2
 #define KEY_END	0xD5
 #define KEY_CAPS_LOCK	0xC1
 #define KEY_F1	0xC2
 #define KEY_F2	0xC3
 #define KEY_F3	0xC4
 #define KEY_F4	0xC5
 #define KEY_F5	0xC6
 #define KEY_F6	0xC7
 #define KEY_F7	0xC8
 #define KEY_F8	0xC9
 #define KEY_F9	0xCA
 #define KEY_F10	0xCB
 #define KEY_F11	0xCC
 #define KEY_F12	0xCD
#endif

#endif //IRLIB_PROTOCOL_12_H
