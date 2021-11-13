#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
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