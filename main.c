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


  /***********old code**************************************/
  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

     // P3.0 = RS
     // P3.2 = r/w
     // P3.3 = E
     // P4.1 = DB4
     // P4.2 = DB5
     // P4.3 = DB6
     // P4.4 = DB7
    setDCO(FREQ_24_MHZ);
 /*****************SET GPIO for P3 and P4 ****************************/
     P3->SEL0 &= ~(BIT0 | BIT2 | BIT3);// Where is 3.1?
     P3->SEL1 &= ~(BIT0 | BIT2 | BIT3);
     P4->SEL0 = 0x00;
     P4->SEL1 = 0x00;
     P3->DIR |= (BIT0 | BIT2 | BIT3);
     P4->DIR = 0x0F;
 /******************************************************************/
     delay_ms(40);
     // Delay For LCD  Boot Up


     /**********Function Set***********/
     P3->OUT &= ~BIT3; // E LOW
     P3->OUT &= ~(BIT0 | BIT2);    // Set RS and RW low

     P4->OUT = 0x03; // 2 Lines by 11

     // Take data in
     P3->OUT |= BIT3;  // Set E High
     delay_us(0);
     P3->OUT &= ~BIT3; // E LOW
     delay_us(37);
     // Clear Data
     // Pulse Enable
     P3->OUT |= BIT3;  // Set E High
     delay_us(0);
     P3->OUT &= ~BIT3; // E LOW
     // delay
     delay_us(37);



     P3->OUT &= ~(BIT0|BIT2); // Set RS/RW
   /*********Function Set*******/

     P4->OUT = 0x0C; //
     P3->OUT |= BIT3;  // Set E High
     delay_us(0);
     P3->OUT &= ~BIT3; // E LOW
     delay_us(37);

     /*****Display On/Off*****************/
     P4->OUT  = 0x0F; //
     P3->OUT |= BIT3;  // Set E High
     delay_us(0);
     P3->OUT &= ~BIT3; // E LOW
     delay_us(37);


     /*****Display Clear****************/
     P4->OUT  = 0x01; //
     P3->OUT |= BIT3;  // Set E High
     delay_us(0);
     P3->OUT &= ~BIT3; // E LOW
     delay_us(1520);


     /****** Entry Set Mode*************/
     P4->OUT = 0x06;
     P3->OUT |= BIT3;  // Set E High
     delay_us(0);
     P3->OUT &= ~BIT3; // E LOW
     delay_us(37);








/**************************************************/
 }
 /**********************************************************/
