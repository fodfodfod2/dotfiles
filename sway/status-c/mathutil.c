#include "mathutil.h"

double fmin(double a, double b) {
  return a > b ? b : a;
}

double fmax(double a, double b) {
  return a > b ? a : b;
}
double fclamp(double val, double min, double max) {
  return fmin(fmax(val, min), max);
}

int imin(int a, int b) {
  return a > b ? b : a;
}

int imax(int a, int b) {
  return a > b ? a : b;
}
int iclamp(int val, int min, int max) {
  return fmin(fmax(val, min), max);
}
