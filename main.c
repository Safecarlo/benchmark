#include <stdio.h>
#include <time.h>

#include "rdtsc.h"

#define N_MAX 10000

typedef float float2 __attribute__((ext_vector_type(2)));
typedef float float4 __attribute__((ext_vector_type(4)));
typedef float float8 __attribute__((ext_vector_type(8)));

void run_add_float_normal(void)
{
  //
  float a = 1.0;
  float b = 1.0;
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

  // Compote size
  double total_size = 3 * sizeof(float) * number_of_ite;
  double total_size_gib = total_size / (1024 * 1024 * 1024);

  // Compute gibs
  double gibs = total_size_gib / mean_time_sec;

  // Print bandwidth
  fprintf(stderr, "add_float; %f\n", gibs);
}

void run_add_float2_normal(void)
{
  //
  float2 a = 1.0;
  float2 b = 1.0;
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

  // Compote size
  double total_size = 3 * sizeof(float2) * number_of_ite;
  double total_size_gib = total_size / (1024 * 1024 * 1024);

  // Compute gibs
  double gibs = total_size_gib / mean_time_sec;

  // Print bandwidth
  fprintf(stderr, "add_float2; %f\n", gibs);
}

void run_add_float4_normal(void)
{
  //
  float4 a = 1.0;
  float4 b = 1.0;
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

  // Compote size
  double total_size = 3 * sizeof(float4) * number_of_ite;
  double total_size_gib = total_size / (1024 * 1024 * 1024);

  // Compute gibs
  double gibs = total_size_gib / mean_time_sec;

  // Print bandwidth
  fprintf(stderr, "add_float4; %f\n", gibs);
}

void run_add_float8_normal(void)
{
  //
  float8 a = 1.0;
  float8 b = 1.0;
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

  // Compote size
  double total_size = 3 * sizeof(float8) * number_of_ite;
  double total_size_gib = total_size / (1024 * 1024 * 1024);

  // Compute gibs
  double gibs = total_size_gib / mean_time_sec;

  // Print bandwidth
  fprintf(stderr, "add_float8; %f\n", gibs);
}

void run_add_float_denormal(void)
{
  //
  float a = 0x1.0p-130;
  float b = 0x1.0p-130;
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

  // Compote size
  double total_size = 3 * sizeof(float) * number_of_ite;
  double total_size_gib = total_size / (1024 * 1024 * 1024);

  // Compute gibs
  double gibs = total_size_gib / mean_time_sec;

  // Print bandwidth
  fprintf(stderr, "add_float; %f\n", gibs);
}

void run_add_float2_denormal(void)
{
  //
  float2 a = 0x1.0p-130;
  float2 b = 0x1.0p-130;
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

  // Compote size
  double total_size = 3 * sizeof(float2) * number_of_ite;
  double total_size_gib = total_size / (1024 * 1024 * 1024);

  // Compute gibs
  double gibs = total_size_gib / mean_time_sec;

  // Print bandwidth
  fprintf(stderr, "add_float2; %f\n", gibs);
}

void run_add_float4_denormal(void)
{
  //
  float4 a = 0x1.0p-130;
  float4 b = 0x1.0p-130;
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

  // Compote size
  double total_size = 3 * sizeof(float4) * number_of_ite;
  double total_size_gib = total_size / (1024 * 1024 * 1024);

  // Compute gibs
  double gibs = total_size_gib / mean_time_sec;

  // Print bandwidth
  fprintf(stderr, "add_float4; %f\n", gibs);
}

void run_add_float8_denormal(void)
{
  //
  float8 a = 0x1.0p-130;
  float8 b = 0x1.0p-130;
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

  // Compote size
  double total_size = 3 * sizeof(float8) * number_of_ite;
  double total_size_gib = total_size / (1024 * 1024 * 1024);

  // Compute gibs
  double gibs = total_size_gib / mean_time_sec;

  // Print bandwidth
  fprintf(stderr, "add_float8; %f\n", gibs);
}

int main(int argc, char **argv)
{
  if (argc != 2)
    return 1;

  if (argv[1][0] == 'n')
    {
      run_add_float_normal();
      run_add_float2_normal();
      run_add_float4_normal();
      run_add_float8_normal();
    }
  else
    {
      run_add_float_denormal();
      run_add_float2_denormal();
      run_add_float4_denormal();
      run_add_float8_denormal();
    }
  
  return 0;
}
