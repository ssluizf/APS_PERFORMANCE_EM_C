#include <stdio.h>
#include <stdlib.h>
#include "eatLine.h"

int eatLine(FILE *fp)
{
  for (;;)
  {
    int ch = getc(fp);
    if (ch == '\n' || ch < 0)
      return ch;
  }
}