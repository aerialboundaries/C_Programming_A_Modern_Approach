// Calculate abs sec
#include <stdio.h>

#include "timecalc.h"

int abs_sec(int n) { return (n < 0 ? -n : n); }

char *time(int s) {
  int h, m;
  static char a[20];
  h = s / 60;
  m = s % 60;
  if (h < 12) {
    if (h == 0)
      h = 12;
    sprintf(a, "%2d:%.2d a.m.", h, m);
  } else if (h == 12) {
    sprintf(a, "%2d:%.2d p.m.", h, m);
  } else {
    sprintf(a, "%2d:%.2d p.m.", h - 12, m);
  }
  return a;
}
