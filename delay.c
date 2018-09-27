/*
 * delay.c
 *
 *  Created on: Sep 25, 2018
 *      Author: samma
 */
#include "delay.h"
#include "msp.h"

void setDCO(int FREQ){  // using the DCO to set different frequencies of the master clock
    // unlock the clock
    CS->KEY = CS_KEY_VAL; // unlock CS registers
    CS->CTL0 = 0;  // clear register CTL0

    if(FREQ == FREQ_1_5_MHZ){
        CS->CTL0 = CS_CTL0_DCORSEL_0;
    }
    else if(FREQ == FREQ_3_MHZ){
        CS->CTL0 = CS_CTL0_DCORSEL_1;
    }
    else if(FREQ == FREQ_6_MHZ){
        CS->CTL0 = CS_CTL0_DCORSEL_2;
    }
    else if(FREQ  == FREQ_12_MHZ){
        CS->CTL0 = CS_CTL0_DCORSEL_3;
    }
    else if(FREQ == FREQ_24_MHZ){
        CS->CTL0 = CS_CTL0_DCORSEL_4;
    }
    else if(FREQ == FREQ_48_MHZ){
        // Code Give in Technical Note 3 on CLOCK Systems
        // VS1 power system needs to be adjusted to meet power
        // demand of 48 MHZ

        /* Transition to VCORE Level 1: AM0_LDO --> AM1_LDO */
        while ((PCM->CTL1 & PCM_CTL1_PMR_BUSY));
         PCM->CTL0 = PCM_CTL0_KEY_VAL | PCM_CTL0_AMR_1;
        while ((PCM->CTL1 & PCM_CTL1_PMR_BUSY));

        FLCTL->BANK0_RDCTL = (FLCTL->BANK0_RDCTL &
         ~(FLCTL_BANK0_RDCTL_WAIT_MASK)) | FLCTL_BANK0_RDCTL_WAIT_1;
        FLCTL->BANK1_RDCTL = (FLCTL->BANK0_RDCTL &
         ~(FLCTL_BANK1_RDCTL_WAIT_MASK)) | FLCTL_BANK1_RDCTL_WAIT_1;

        // Set the DCO for 48 MHZ
        CS->CTL0 = CS_CTL0_DCORSEL_5;
        /* Select MCLK = DCO, no divider */
        CS->CTL1 = CS->CTL1 & ~(CS_CTL1_SELM_MASK | CS_CTL1_DIVM_MASK) |
        CS_CTL1_SELM_3;

    }

     // Pin function number 59 MCLK

    //set the DCO for all other frequencies

        CS->CTL1 |= CS_CTL1_SELM_3;

    //lock cs registers
    CS->KEY = 0;

}

void




