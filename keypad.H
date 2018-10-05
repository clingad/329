/*
 * keypad.H
 *
 *  Created on: Oct 3, 2018
 *      Author: samma
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "msp.h"
//ROWs
#define ROW1 BIT4 //p2.4
#define ROW2 BIT5 //p2.5
#define ROW3 BIT6 //p2.6
#define ROW4 BIT7 //p2.7
// COL
#define COL1 BIT5 //P6.5
#define COL2 BIT6 //P6.6
#define COL3 BIT7 //P6.7
#define INVALID 0xFF

#define BIT_CHECK(var,pos) ((var) & (1<<(pos)))
// Initialize ports in the keys
void initKeypad();
uint8_t keypad_getkey();




#endif /* KEYPAD_H_ */
