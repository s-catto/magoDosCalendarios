#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <math.h>
#include <time.h>

#include "tempo.h"

double timestamp(void)
{
  struct timespec tp;
  clock_gettime(CLOCK_MONOTONIC_RAW, &tp);
  return((double)(tp.tv_sec*1.0e3 + tp.tv_nsec*1.0e-6));
}

