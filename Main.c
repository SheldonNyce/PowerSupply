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

  for (;;)
  {
    A = PORTBbits.RB2; // Pin 6
    B = PORTBbits.RB3; // Pin 7

    Nop();
    relay = !A & B;

    if (relay)
    {
      PORTA = 0xffff;
    }
    else
    {
      PORTA = 0;
    }
  }

  return 0;
}

