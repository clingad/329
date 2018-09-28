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

	//MLK
	P4->SEL0 &= ~(BIT3); // set to 1
	//P4->SEL1 &= ~(BIT3); //set to 0  s



    P4->DIR |= (BIT3);
	//Bit Flip direction out
	   //set as output

	setDCO(FREQ_3_MHZ);

     //P1->DIR = 0x01;
	//delay_us(10,FREQ_3_MHZ);

   while(1){

    P4->OUT |= (BIT3); // on
    P2->OUT |= (0x01);
	delay_ms(50,FREQ_3_MHZ);
	P4->OUT &= ~(BIT3);
	P2->OUT |= (0x00);
	delay_ms(50,FREQ_3_MHZ);
   }


}

