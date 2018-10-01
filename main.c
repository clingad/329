#include "msp.h"
#include "delay.h"
#include "LED.H"
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
int main() {

    int i;
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
    setDCO(FREQ_24_MHZ);

  init(); // initalize the LCD
  clear_LCD(); // clear the lcd
  write_char_LCD('A', 0,0x0); // 'A' in the top left first line
  write_char_LCD('B', 1,15); // write B in the lower right. The second line
  write_char_LCD('F',0,15);
  write_char_LCD('S',1,0x00);
  home_LCD(); // return the cursor to the top left without erasing what is currently written

}
/**********************************************************/
