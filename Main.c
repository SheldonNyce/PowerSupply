/* MAGLEV MAIN FILE
 * File:   main.c
 * Author: Ben
 *
 * Created on 20 September 2015, 2:05 PM
 */
#define FCY 20000000UL
#include <stdio.h>
#include <stdlib.h>
#include <libpic30.h>
#include <xc.h>
#include <dsp.h>
#include <p33FJ128MC802.h>
#include "ConfigBits.h"

// GLOBAL VARIABLES

int main()
{
  AD1PCFGL = 0xffff; // set all pins to digital except AN0 and AN1 
 
  LATA = 0;
  TRISA = 0;
  PORTA = 0;

  LATB = 0;
  TRISB = 0;
  PORTB = 0;

  unsigned int A;
  unsigned int B;
  unsigned int relay;
  int delay;
  int delay2;

  for (;;)
  {  
    A = PORTB;
//    B = PORTBbits.RB1;
    for (delay = 0; delay < 0xffff; delay++)
    {
      for (delay2 = 0; delay2 < 0xf; delay2++)
      {
        Nop();
      }
    }
//    relay = !A & B;
    if (A)
    {
      PORTA = 0;
    }
    else
    {
      PORTA = 0xffff;
    }
  }

  return 0;
}

