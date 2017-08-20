/*
 * File:   Main.c
 * Author: andrew
 *
 * Created on 17 August 2017, 1:45 PM
 */


#include <stdio.h>
#include "xc.h"

int main(void)
{
  int x = 0;

  int i;
  int j = 0;

  for (i = 0; i < 100; i++)
  {
    j = j + i;
  }

  printf("%i", j);
  return 0;
}

