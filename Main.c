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
  AD1PCFGL = 0x0; // set all pins to digital except AN0 and AN1 
  TRISB = 0;
  TRISA = 0;
  LATB = 0;
  LATA = 0;
  PORTB = 0;
  PORTA = 0;

  unsigned int x = 0;
  unsigned int y = 0;

  for (;;)
  {
    PORTA = 0xffff;
    PORTB = 0xffff;

    for (x = 0; x < 0xfff; x++)
    {
      y = y * 2;
    }

    PORTA = 0x0000;
    PORTB = 0x0000;

    for (x = 0; x < 0xfff; x++)
    {
      y = y * 2;
    }
  }

  return 0;
}

