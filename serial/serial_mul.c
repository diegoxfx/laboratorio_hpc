#include <stdio.h>
#include <stdlib.h>

void create_matrices(float *a, float *b, float *c, int len) {
  for (int i = 0; i < len; i++) {
    a[i] = (float) rand() / (float) RAND_MAX;
    b[i] = (float) rand() / (float) RAND_MAX;
    c[i] = 0.0;
  }
}

void multiply(float* a, float* b, float* c, int size) {
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j ++)
      for (int k = 0; k < size; k++)
	c[i*size+j] += (a[i*size+k] * b[k*size+j]);
}

void print(float *a, int size) {
  printf("[");
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      printf(" %f", a[i*size + j]);
    }
    printf("\n");
  }
  printf("]\n"); 
}

int main(int argc, char* argv[])
{

  float *a, *b, *c;
  int size, len;
  if (argc == 2) {
    size = atoi(argv[1]);
    len = size*size;
  }
  else {
    fprintf(stderr, "usage: serial size\n");
    exit(1);
  }

  a = (float*)malloc(sizeof(float)*len);
  b = (float*)malloc(sizeof(float)*len);
  c = (float*)malloc(sizeof(float)*len);
  
  if (!(a && b && c)) {
    fprintf(stderr, "%s: out of memory!\n", argv[0]);
    free(a); free(b); free(c);
    exit(2);
  }
  
  create_matrices(a, b, c, len);
  multiply(a, b, c, size);

  printf("A:\n");
  print(a, size);
  printf("B:\n");
  print(b, size);
  printf("C:\n");
  print(c, size);
  free(a); free(b); free(c);
  return 0;
}
