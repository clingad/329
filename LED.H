/*
 * LED.H
 *
 *  Created on: Sep 30, 2018
 *      Author: samma
 */

#ifndef LED_H_
#define LED_H_

#define BIT_CHECK(var,pos) ((var) & (1<<(pos)))
void sendOut(char i);
void command(char i);
void write(char i);
void Nybble();
void init();

#endif /* LED_H_ */
