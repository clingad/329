#include "msp.h"
#include "delay.h"

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Code for Oscilloscope
	//Mux Select
	P4->SEL0 |= (BIT3); // set to 1
	P4->SEL1 &= ~(BIT3); //set to 0

	//Bit Flip direction out
	P4->DIR |= (BIT3);   //set as output

	setDCO(FREQ_3_MHZ);

    while(1){
	delay_us(1000000,FREQ_3_MHZ);
    }

}

