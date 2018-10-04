#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msp.h"
#include "delay.h"
#include "LED.H"
#include "keypad.H"


#define BIT_CHECK(var,pos) ((var) & (1<<(pos)))

/**
 * main.c
 */
    // P3.0 = RS
    // P3.2 = r/w
    // P3.3 = E
    // P4.1 = DB4
    // P4.2 = DB5
    // P4.3 = DB6
    // P4.4 = DB7
int pos = 0;
int main() {

    int i;
    char data[16];

 //  String hel;

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
    setDCO(FREQ_24_MHZ);
    init(); // initalize the LCD
    clear_LCD(); // clear the lcd
    initKeypad();
  while(1){
     delay_ms(180);

    int num = keypad_getkey();
    if(num != 0XFF){
     write_char_LCD(num,0,pos);
     pos++;
     if(pos > 15){
         pos = 0;
     }
  }


  }
    home_LCD(); // return the cursor to the top left without erasing what is currently written

}
/**********************************************************/
