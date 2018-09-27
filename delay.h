/*
 * delay.h
 *
 *  Created on: Sep 25, 2018
 *      Author: samma
 */

#ifndef DELAY_H_
#define DELAY_H_

#define FREQ_MHZ 1000000
#define FREQ_1_5_MHZ 5000000
#define FREQ_3_MHZ 3000000
#define FREQ_6_MHZ 6000000
#define FREQ_12_MHZ 12000000
#define FREQ_24_MHZ 24000000
#define FREQ_48_MHZ 48000000

void setDCO(int FREQ);
void delay_us(int us,int freq);

#endif /* DELAY_H_ */
