/*
 * LED.C
 *
 *  Created on: Sep 30, 2018
 *      Author: samma
 */
#include "msp.h"
#include "LED.H"
#include "delay.h"
#include "string.h"

  // P3.0 = RS
    // P3.2 = r/w
    // P3.3 = E
    // P4.1 = DB4
    // P4.2 = DB5
    // P4.3 = DB6
    // P4.4 = DB7

// Write Char LCD takes in the character the line and
// position in the line you want the character to be set in
void write_char_LCD(char i, int line, int pos)
{
 int j;
 cursorSet(line,pos);
 j = i >> 4; // send upper bits
 P4->OUT = j;
 P3->OUT |= (RS);  // send data
 P3->OUT &= ~(RW); // write
 Nybble(); //Clock lower 4 bits
 P4->OUT = i; // send lower bits
 Nybble(); //Clock upper 4 bits
 delay_ms(1);

}
/**********************************************************/
// Returns Cursor back to the top left line
void home_LCD(){
    command(RETURNCURSOR);
     delay_ms(2);// return to upper left part of display
}
// clears LCD
void clear_LCD(){
    command(CLEARDISPLAY);
    delay_ms(2);
}

// sends commands to the LCD
void command(char i)
{
 int j;
 j = i >> 4;
 P4->OUT = j; // send upper bits
 P3->OUT &= ~(RS | RW);
 Nybble(); //Send lower 4 bits
 P4->OUT = i;  // Send Lower bits
 Nybble(); //Send upper 4 bits
 delay_us(40);
}
// enable pulse
void Nybble()
{

     P3->OUT |= ENABLE;  // Set E High
     delay_us(0);
     P3->OUT &= ~ENABLE; // E LOW

 }
// base address is 0x80 for 1st line
// second line base address is 0xC0
// the length of a line is 0 to 15
void cursorSet(int line,int pos){ // first line is 0 // second line 1
    int address = FIRSTLINE;
        if(line >= 0 && line < 2){
            if(pos >= 0 && pos < 16){
                if(line == 1){
                    address += SECONDLINE;
                }
                address += pos;
            }
            // writing off the screen
        }
        command(address);
}

 /**********************************************************/

 void init()
 {
    P3->SEL0 &= ~(RS | RW | ENABLE);// Where is 3.1?
    P3->SEL1 &= ~(RS | RW | ENABLE);
    P4->SEL0 = 0x00;
    P4->SEL1 = 0x00;
    P3->DIR |= (RS | RW | ENABLE);
    P4->DIR = 0x0F; // P4.0 to P4.3

  delay_ms(40); //Wait >40 msec after power is applied
  P4->OUT = 0x03;//put 0x03 on the output port
  delay_ms(5); //must wait 5ms, busy flag not available
  Nybble(); //command 0x30 = Wake up #3
  delay_us(40);//can check busy flag now instead of delay
  P4->OUT = 0x02; //put 0x02 on the output port
  delay_us(40); //Function set: 4-bit interface
  command(0x28); //Function set: 4-bit/2-line
  command(CURSOR); //Set cursor
  command(0x0F); //Display ON; Blinking cursor
  command(0x06); //Entry Mode set

}

