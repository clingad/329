#include "msp.h"
#include "delay.h"

/**
 * main.c
 */
int main() {

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
    setDCO(FREQ_24_MHZ);
    init();


}
/**********************************************************/
void command(char i)
{
 P4->OUT = i; //put data on output Port
 P3->OUT &= ~(BIT0 | BIT2);
 Nybble(); //Send lower 4 bits
 i = i<<4; //Shift over by 4 bits
 P4->OUT = i; //put data on output Port
 Nybble(); //Send upper 4 bits
}
/**********************************************************/
void write(char i)
{
 P4->OUT = i; //put data on output Port
// D_I = 1; //D/I=HIGH : send data
 //R_W = 0; //R/W=LOW : Write
 P3->OUT |= (BIT0);
 P3->OUT &= ~( BIT2);
 Nybble(); //Clock lower 4 bits
 //i = i<<4; //Shift over by 4 bits
 P4->OUT = i; //put data on output Port
 Nybble(); //Clock upper 4 bits
}
/**********************************************************/
void Nybble()
{
/* E = 1;
 Delay(1); //enable pulse width >= 300ns
 E = 0; //Clock enable: falling edge*/

     P3->OUT |= BIT3;  // Set E High
     delay_us(0);
     P3->OUT &= ~BIT3; // E LOW


 }
 /**********************************************************/
 void init()
 {
     P3->SEL0 &= ~(BIT0 | BIT2 | BIT3);// Where is 3.1?
        P3->SEL1 &= ~(BIT0 | BIT2 | BIT3);
        P4->SEL0 = 0x00;
        P4->SEL1 = 0x00;
        P3->DIR |= (BIT0 | BIT2 | BIT3);
        P4->DIR = 0x0F;
  delay_ms(40); //Wait >40 msec after power is applied
  P4->OUT = 0x30; //put 0x30 on the output port
  delay_ms(5); //must wait 5ms, busy flag not available
  Nybble(); //command 0x30 = Wake up
  delay_us(40); //must wait 160us, busy flag not available
  Nybble(); //command 0x30 = Wake up #2
  delay_us(40); //must wait 160us, busy flag not available
  Nybble(); //command 0x30 = Wake up #3
  delay_us(40);//can check busy flag now instead of delay
  P4->OUT= 0x20; //put 0x20 on the output port
  delay_us(40); //Function set: 4-bit interface
  command(0x28); //Function set: 4-bit/2-line
  command(0x10); //Set cursor

  command(0x0F); //Display ON; Blinking cursor
  command(0x06); //Entry Mode set


 }
 /**********************************************************/
