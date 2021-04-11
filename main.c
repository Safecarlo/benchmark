#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rdtsc.h"

#define N_MAX 10000

typedef float float2 __attribute__((ext_vector_type(2)));
typedef float float4 __attribute__((ext_vector_type(4)));
typedef float float8 __attribute__((ext_vector_type(8)));

double run_add_float(double x, double y)
{
  //
  float a = (float)x;
  float b = (float)y;
  float c = 0.0;

  //
  double total_time = 0.0;
  double elapsed = 0.0;
  struct timespec before, after;

  //
  double number_of_ite = N_MAX;

  //
  do
    {
      //
      clock_gettime(CLOCK_MONOTONIC_RAW, &before);
      {
        for (int i = 0; i < number_of_ite; i++)
          {
            c = a + b;
          }
      }
      clock_gettime(CLOCK_MONOTONIC_RAW, &after);

      //
      elapsed = after.tv_nsec - before.tv_nsec;

    }
  while (elapsed < 0.0);

  //
  total_time = elapsed;

  // Mean
  double mean_time = total_time / N_MAX;

  // Nanosecond to second
  double mean_time_sec = mean_time / 1.0e9;

  // Compute size
  double total_size = 3 * sizeof(float) * number_of_ite;
  double total_size_gib = total_size / (1024 * 1024 * 1024);

  // Compute gibs
  double gibs = total_size_gib / mean_time_sec;

  // Print bandwidth
  fprintf(stderr, "add_float; %f\n", gibs);

  return gibs;
}

double run_add_float2(double x, double y)
{
  //
  float2 a = (float)x;
  float2 b = (float)y;
  float2 c = 0.0;

  //
  double total_time = 0.0;
  double elapsed = 0.0;
  struct timespec before, after;

  //
  double number_of_ite = N_MAX / 2;

  //
  do
    {
      //
      clock_gettime(CLOCK_MONOTONIC_RAW, &before);
      {
        for (int i = 0; i < number_of_ite; i++)
          {
            c = a + b;
          }
      }
      clock_gettime(CLOCK_MONOTONIC_RAW, &after);

      //
      elapsed = after.tv_nsec - before.tv_nsec;

    }
  while (elapsed < 0.0);

  //
  total_time = elapsed;

  // Mean
  double mean_time = total_time / N_MAX;

  // Nanosecond to second
  double mean_time_sec = mean_time / 1.0e9;

  // Compute size
  double total_size = 3 * sizeof(float2) * number_of_ite;
  double total_size_gib = total_size / (1024 * 1024 * 1024);

  // Compute gibs
  double gibs = total_size_gib / mean_time_sec;

  // Print bandwidth
  fprintf(stderr, "add_float2; %f\n", gibs);

  return gibs;
}

double run_add_float4(double x, double y)
{
  //
  float4 a = (float)x;
  float4 b = (float)y;
  float4 c = 0.0;

  //
  double total_time = 0.0;
  double elapsed = 0.0;
  struct timespec before, after;

  //
  double number_of_ite = N_MAX / 4;

  //
  do
    {
      //
      clock_gettime(CLOCK_MONOTONIC_RAW, &before);
      {
        for (int i = 0; i < number_of_ite; i++)
          {
            c = a + b;
          }
      }
      clock_gettime(CLOCK_MONOTONIC_RAW, &after);

      //
      elapsed = after.tv_nsec - before.tv_nsec;

    }
  while (elapsed < 0.0);

  //
  total_time = elapsed;

  // Mean
  double mean_time = total_time / N_MAX;

  // Nanosecond to second
  double mean_time_sec = mean_time / 1.0e9;

  // Compute size
  double total_size = 3 * sizeof(float4) * number_of_ite;
  double total_size_gib = total_size / (1024 * 1024 * 1024);

  // Compute gibs
  double gibs = total_size_gib / mean_time_sec;

  // Print bandwidth
  fprintf(stderr, "add_float4; %f\n", gibs);

  return gibs;
}

double run_add_float8(double x, double y)
{
  //
  float8 a = (float)x;
  float8 b = (float)y;
  float8 c = 0.0;

  //
  double total_time = 0.0;
  double elapsed = 0.0;
  struct timespec before, after;

  //
  double number_of_ite = N_MAX / 8;

  //
  do
    {
      //
      clock_gettime(CLOCK_MONOTONIC_RAW, &before);
      {
        for (int i = 0; i < number_of_ite; i++)
          {
            c = a + b;
          }
      }
      clock_gettime(CLOCK_MONOTONIC_RAW, &after);

      //
      elapsed = after.tv_nsec - before.tv_nsec;

    }
  while (elapsed < 0.0);

  //
  total_time = elapsed;

  // Mean
  double mean_time = total_time / N_MAX;

  // Nanosecond to second
  double mean_time_sec = mean_time / 1.0e9;

  // Compute size
  double total_size = 3 * sizeof(float8) * number_of_ite;
  double total_size_gib = total_size / (1024 * 1024 * 1024);

  // Compute gibs
  double gibs = total_size_gib / mean_time_sec;

  // Print bandwidth
  fprintf(stderr, "add_float8; %f\n", gibs);

  return gibs;
}

int main(int argc, char **argv)
{
  if (argc != 3)
    return 1;

  double x = strtod(argv[1], NULL);
  double y = strtod(argv[2], NULL);

  double baseline = run_add_float(x, y);
  double gibs_2x = run_add_float2(x, y);
  double gibs_4x = run_add_float4(x, y);
  double gibs_8x = run_add_float8(x, y);

  fprintf(stderr, "speedup_2x; %f\n", gibs_2x / baseline);
  fprintf(stderr, "speedup_4x; %f\n", gibs_4x / baseline);
  fprintf(stderr, "speedup_8x; %f\n", gibs_8x / baseline);

  return 0;
}
