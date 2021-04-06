#include <stdio.h>

#include "rdtsc.h"

#define N_MAX 1000

typedef double double2 __attribute__((ext_vector_type(2)));
typedef double double4 __attribute__((ext_vector_type(4)));

void run_addition(void)
{
  double a = 1.0;
  double b = 1.0;
  double c = 0.0;

  double start, end, final = 0;

  for (int i = 0; i < N_MAX; i++)
    {
      start = rdtsc();
      {
        c = a + b;
      }
      end = rdtsc();
      
      if (start < end)
        final += end - start;
    }

  fprintf(stderr, "addition;  double; %f\n", final);
}

void run_addition_2x(void)
{
  double2 a = 1.0;
  double2 b = 1.0;
  double2 c = 0.0;

  double start, end, final = 0;

  for (int i = 0; i < N_MAX / 2; i++)
    {
      start = rdtsc();
      {
        c = a + b;
      }
      end = rdtsc();
      
      if (start < end)
        final += end - start;
    }

  fprintf(stderr, "addition; double2; %f\n", final);
}

void run_addition_4x(void)
{
  double2 a = 1.0;
  double2 b = 1.0;
  double2 c = 0.0;

  double start, end, final = 0;

  for (int i = 0; i < N_MAX / 4; i++)
    {
      start = rdtsc();
      {
        c = a + b;
      }
      end = rdtsc();
      
      if (start < end)
        final += end - start;
    }

  fprintf(stderr, "addition; double4; %f\n", final);
}

int main(int argc, char **argv)
{
  run_addition_4x();
  run_addition_2x();
  run_addition();
  
  return 0;
}
