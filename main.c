#include "msp.h"
#include "delay.h"

/**
 * main.c
 */
int main() {

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    // Set up LED P1.0 //RED LED
    P1->SEL0 &= ~BIT0;
    P1->SEL1 &= ~BIT0;      // set P2.1 (Green RGB LED) as GPIO
    P1->DIR  |= BIT0;       // set P2.1 (Green RGB LED) as output

    // Oscilloscope
    P4->SEL1 &= ~BIT3;      // set P4.3 as GPIO
    P4->SEL0 &= ~BIT3;
    P4->DIR  |= BIT3;

    setDCO(FREQ_3_MHZ);

    while (1) {
        P1->OUT |= BIT0;    // P2.1 on
        P4->OUT |= BIT3;    // P4.3 on
        delay_us(40);
        P1->OUT &= ~BIT0;   // P2.1 off
        P4->OUT &= ~BIT3;   // P4.3 off
        delay_us(40);
    }
}
