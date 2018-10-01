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

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
    setDCO(FREQ_24_MHZ);
    init();
    //command(0x01);
    command(0xC2);
    write(0x30);


}
/**********************************************************/
