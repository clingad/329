/*
 * keypad.C
 *
 *  Created on: Oct 3, 2018
 *      Author: samma
 */


//p6.5  Col 1 pin 1
//p6.6  Col 2 pin 3
//p6.7  Col 3 pin 5
//p2.4  row 1 pin 2
//p2.5  row 2 pin 4
//p2.6  row 3 pin 6
//p2.7  row 4 pin 7

#include "keypad.h"
#include "delay.h"
void initKeypad(){

   //GPIO
    // set ROWS as input
    P2->DIR &= ~(ROW1 | ROW2 | ROW3 | ROW4); // input

    // set COL as outputs
    P6->DIR  |= (COL1| COL2 | COL3);

    // Resistor Enable for lows
    P2->REN |= (ROW1| ROW2 | ROW3 | ROW4);
    // Pull down for the rows
    P2->OUT &= ~(ROW1 | ROW2 | ROW3 | ROW4); // input



}

uint8_t keypad_getkey(){
        int col = 0; // check each column
        int row = 0;
        int key = 0;
        // put all the COLS high then delay to make sure
        // that they actually went high
        P6->OUT |= (COL1|COL2|COL3);
        delay_us(0);
        // BIT MASK
        row = P2->IN & (ROW1|ROW2|ROW3|ROW4);
        // check to see if any of the inputs in row is 1
        if(row == 0){
            return 0xFF;
        }
        // if one of the bits is high then
        // find the column
        else{

                for(col = 0; col < 3; col++){
                    // turn them all off
                    P6->OUT &= ~(COL1|COL2|COL3);
                    // now we need to test each column
                    // by turning each one on
                    P6->OUT |= (COL1 << col);
                    delay_us(0);
                    // check all the rows at that certain column
                    row = P2->IN & (ROW1|ROW2|ROW3|ROW4);

                    // if it is on then stop the for loop
                    if(row != 0){
                        break;
                    }
                }
                // Turn off all columns
                P6->OUT &= ~(COL1|COL2|COL3);

                if(col == 3){ //input missed
                    return INVALID;
                }
                // reassign each row value in order
                // to calculate the key
                if(row == 16){
                    row = 1;
                }
                if(row == 32){
                    row = 2;
                }
                 if(row == 64){
                     row = 3;
                }
                 if(row == 128){
                     row = 4;
                 }


            // use the row and column to calculate the key
            if(col == 0){
                key = (row*3-2) + '0';
            }
            if(col == 1){
                key = (row*3-1) + '0';
            }
            if(col == 2){
                key = (row*3) + '0';
            }
            if(key == (11 + '0')){
                key = '0';
            }
            if(key == (12 + '0')){
                key = '#';
            }
            if(key == (10 + '0')){
                key = '*';
            }

        }

      return key;
}
