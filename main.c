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
   write_char_LCD('H', 0, 0x00);
    write_char_LCD('E', 0, 0x01);
    write_char_LCD('L', 0, 0x02);
    write_char_LCD('L', 0, 0x03);
    write_char_LCD('O', 0, 0x04);
    write_char_LCD(',', 0, 0x05);
    write_char_LCD('W', 0, 0x06);
    write_char_LCD('O', 0, 0x07);
    write_char_LCD('R', 0, 0x08);
    write_char_LCD('L', 0, 0x09);
    write_char_LCD('D', 0, 0x0A);

    write_char_LCD('A', 1, 0x00);
    write_char_LCD('S', 1, 0x01);
    write_char_LCD('S', 1, 0x02);
    write_char_LCD('I', 1, 0x03);
    write_char_LCD('G', 1, 0x04);
    write_char_LCD('N', 1, 0x05);
    write_char_LCD('M', 1, 0x06);
    write_char_LCD('E', 1, 0x07);
    write_char_LCD('N', 1, 0x08);
    write_char_LCD('T', 1, 0x09);
    write_char_LCD(' ', 1, 0x0A);
    write_char_LCD('3', 1, 0x0B);

  home_LCD(); // return the cursor to the top left without erasing what is currently written

}
/**********************************************************/
