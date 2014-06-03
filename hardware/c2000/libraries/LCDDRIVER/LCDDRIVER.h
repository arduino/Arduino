/*-
 * Name: LCD_driver.h
 * Introduction: the driver codes for LCD NHD-C0216CZ-NSW-BBW-3V3
 * Created on: Dec 11, 2012
 * Author: a0219294
 */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

void LCD_init(void);			//initialize LCD
void LCD_set_pointer(unsigned char H, unsigned char L);
void LCD_clear(void);			//Clean LCD
void LCD_display_string(unsigned char L, char *ptr);
void LCD_display_string(char *ptr);
void LCD_display_number(unsigned char L,unsigned char H,unsigned int num);
void LCD_display_temp(unsigned char L,unsigned char H,unsigned int num);
void LCD_display_HEX(unsigned char L,unsigned char H,unsigned int num);
void LCD_display_char(unsigned char L,unsigned char H,char ch);
void LCD_display_time(unsigned char L,unsigned char H,unsigned long seconds);

void LCD_writecom(unsigned char c);		//write command
void LCD_writedata(unsigned char d);	//write data
void LCD_delay_Nms(unsigned char i);	//delay i ms

#define LCD_CS_LOW 		digitalWrite(6, LOW);	//set CS low
#define LCD_CS_HIGH 	digitalWrite(6, HIGH);	//set CS high
#define LCD_RS_LOW 		digitalWrite(7, LOW);	//set RS low
#define LCD_RS_HIGH 	digitalWrite(7, HIGH);	//set RS high
#define LCD_RST_LOW 	digitalWrite(AB6, LOW);	//set RST low
#define LCD_RST_HIGH 	digitalWrite(AB6, HIGH);

// Set CS high to end transaction


#endif /* LCD_DRIVER_H_ */
