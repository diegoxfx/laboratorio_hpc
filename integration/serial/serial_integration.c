#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
  double sqrt_x = sqrt(x);
  return sqrt(1 + pow(sqrt_x - 1/sqrt_x, 2)/2);
}

double integrate(float a, float b, long interval_length) {
  double dx = (double)(b - a) / interval_length;
  double sum = 0;
  double x;
  for(long i = 0; i < interval_length; i++) {
    x = a + i*dx;
    sum += dx*f(x);
  }
  return sum;
}

int main(int argc, char* argv[])
{
  int a = 1, b = 4;
  long length;
  if (argc == 2) {
    length = atol(argv[1]);
  }
  else {
    fprintf(stderr, "usage: serial interval_lenght\n");
    exit(1);
  }
  
  double result = integrate(a, b, length);
  printf("result: %f\n", result);
  return 0;
}
