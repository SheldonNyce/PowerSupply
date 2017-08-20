/*
 * File:   Main.c
 * Author: andrew
 *
 * Created on 17 August 2017, 1:45 PM
 */

#include <stdio.h>
#include <p33FJ128MC802.h>
#include "xc.h"

void PWM_Init(void)
{
//    TRISE = 0x00; // make sure PWM pins are set to be outputs
//    PORTE = 0x00; // clear the outputs 
 
    PTCONbits.PTOPS = 0; // PWM timer post-scale
    PTCONbits.PTCKPS = 3; // PWM timer pre-scale
    PTCONbits.PTMOD = 0;
 
    PTMR = 0; // PWM counter value, start at 0
 
    PTPER = 65535; // PWM Time base period
 
    PWMCON1bits.PMOD3 = 1; // PWM in complimentary mode
    PWMCON1bits.PMOD2 = 1; // PWM in complimentary mode
    PWMCON1bits.PMOD1 = 1; // PWM in complimentary mode
    PWMCON1bits.PEN3H = 0; // PWM High pin is enabled
    PWMCON1bits.PEN3L = 0; // PWM Low pin enabled (direction control later?)
    PWMCON1bits.PEN2H = 0; // PWM High pin is enabled
    PWMCON1bits.PEN2L = 0; // PWM Low pin enabled (direction control later?)
    PWMCON1bits.PEN1H = 0; // PWM High pin is enabled
    PWMCON1bits.PEN1L = 1; // PWM Low pin enabled (direction control later?)
 
    //PWMCON2 = 0x0000; // PWM update info
 
    DTCON1bits.DTAPS = 0;  //DeadTime pre-scaler
    DTCON1bits.DTA = 0;   //DeadTime value for 4 us. 
 
    //FLTACON = 0x0000; // Fault A Control
 
    //OVDCON = 0x0000; // Override control info
 
    // Duty Cycle has a max value of 2xPeriod since output  
    // can change on rising or falling edge of Tcy
    PDC1 = 32767; // PWM#1 Duty Cycle register (11-bit)
    PDC2 = 19999; // PWM#2 Duty Cycle register (11-bit)
    PDC3 = 19999; // PWM#3 Duty Cycle register (11-bit)

 //   PLLFBDbits.PLLDIV = 511;
    
    PTCONbits.PTEN = 1; // Enable PWM Timer base!
}

int main(void)
{ 
  PWM_Init();
  
  for (;;)
  {
  }
  return 0;
}
