/*
 * LED.H
 *
 *  Created on: Sep 30, 2018
 *      Author: samma
 */

// P3.0 = RS
// P3.2 = r/w
// P3.3 = E
// P4.1 = DB4
// P4.2 = DB5
// P4.3 = DB6
// P4.4 = DB7

#ifndef LED_H_
#define LED_H_
#define BIT_CHECK(var,pos) ((var) & (1<<(pos)))
/*****Pound Define Renames***********************/
#define ENABLE BIT3
#define RW BIT2
#define RS BIT0
#define LOWERNIBBLE 0x0F
#define NIBBLEFUNCSET1 0x03
#define NIBBLEFUNCSET2 0x02
#define FUNCSET4B2L 0x28
#define CURSOR 0x10
#define DISPLAYON 0x0F
#define ENTRYMODESET 0x06
#define RETURNCURSOR 0x02
#define CLEARDISPLAY 0x01

#define FIRSTLINE 0x80
#define SECONDLINE 0x40


void home_LCD();
void clear_LCD();
void write_char_LCD(char i, int line, int pos);
void cursorSet(int line,int pos);
void command(char i);
void Nybble();
void init();


#endif /* LED_H_ */
