#include "msp.h"
#include "delay.h"

/**
 * main.c
 */
int main() {

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    // P3.0 = RS
    // P3.2 = r/w
    // P3.3 = E
    // P4.0 = DB4
    // P4.1 = DB5
    // P4.2 = DB6
    // P4.3 = DB7
    setDCO(FREQ_24_MHZ);

    P3->SEL0 &= ~(BIT0 | BIT2 | BIT3);// Where is 3.1?
    P3->SEL1 &= ~(BIT0 | BIT2 | BIT3);
    P4->SEL0 = 0x00;
    P4->SEL1 = 0x00;
    P3->DIR |= (BIT0 | BIT2 | BIT3);
    P4->DIR = 0x0F;

    delay_us(40000);

    P3->OUT &= ~BIT3; // E LOW
    P3->OUT &= ~(BIT0 | BIT2);    //RS and RW LOw
    P4->OUT = 0x03;
    // Pulse Enable
    P3->OUT |= BIT3;  // Set E High
    delay_us(0);
    P3->OUT &= ~BIT3; // E LOW
    delay_us(37);
    // Pulse Enable
    P3->OUT |= BIT3;  // Set E High
    delay_us(0);
    P3->OUT &= ~BIT3; // E LOW
    // delay
    delay_us(37);

    // Data
    P3->OUT &= ~(BIT0|BIT2); // Set RS/RW
    P4->OUT = 0x0C;
     // Pulse Enable
    P3->OUT |= BIT3;  // Set E High
    delay_us(0);
    P3->OUT &= ~BIT3; // E LOW

    // delay
    delay_us(37);
    // data
    P4->OUT = 0x0F;
    P3->OUT |= BIT3;  // Set E High
    delay_us(0);
    P3->OUT &= ~BIT3; // E LOW

    delay_us(1520);

    P4->OUT = 0x01;
    // pulse enable
    P3->OUT |= BIT3;  // Set E High
    delay_us(0);
    P3->OUT &= ~BIT3; // E LOW
    // delay
    delay_us(37);

    // Pulse Enable
    P3->OUT |= BIT3;  // Set E High
    delay_us(0);
    P3->OUT &= ~BIT3; // E LOW
    // delay

    P4->OUT = 0x07;

    // Pulse Enable
    P3->OUT |= BIT3;  // Set E High
    delay_us(0);
    P3->OUT &= ~BIT3; // E LOW
    delay_us(37);





}
