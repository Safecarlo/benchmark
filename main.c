#include <stdio.h>

#include "rdtsc.h"

#define N_MAX 10000

typedef float float2 __attribute__((ext_vector_type(2)));
typedef float float4 __attribute__((ext_vector_type(4)));
typedef float float8 __attribute__((ext_vector_type(8)));

void run_addition(void)
{
  float a = 1.0;
  float b = 1.0;
  float c = 0.0;

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
      else
        i--;
    }

  fprintf(stderr, "addition;  float; %f\n", final);
}

void run_addition_2x(void)
{
  float2 a = 1.0;
  float2 b = 1.0;
  float2 c = 0.0;

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
      else
        i--;
    }

  fprintf(stderr, "addition; float2; %f\n", final);
}

void run_addition_4x(void)
{
  float4 a = 1.0;
  float4 b = 1.0;
  float4 c = 0.0;

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
      else
        i--;
    }

  fprintf(stderr, "addition; float4; %f\n", final);
}

void run_addition_8x(void)
{
  float8 a = 1.0;
  float8 b = 1.0;
  float8 c = 0.0;

  double start, end, final = 0;

  for (int i = 0; i < N_MAX / 8; i++)
    {
      start = rdtsc();
      {
        c = a + b;
      }
      end = rdtsc();
      
      if (start < end)
        final += end - start;
      else
        i--;
    }

  fprintf(stderr, "addition; float8; %f\n", final);
}

int main(int argc, char **argv)
{
  run_addition();
  run_addition_2x();
  run_addition_4x();
  run_addition_8x();  
  return 0;
}
