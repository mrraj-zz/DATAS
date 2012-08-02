/* test_outreg.c */

#include <stdio.h>

void main(void)
{
  long i;

  for (i=0xabcd; i<0xbfff; i+= 0x1111) {
    outreg( i );
  }
}
