#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rdtsc.h"

#define N_MAX 10000

typedef float float2 __attribute__((ext_vector_type(2)));
typedef float float4 __attribute__((ext_vector_type(4)));
typedef float float8 __attribute__((ext_vector_type(8)));

#define define_run_op_float(op, name)                                          \
  double run_##name##_float(double x, double y)                                \
  {                                                                            \
    /* */                                                                      \
    float a = (float)x;                                                        \
    float b = (float)y;                                                        \
    float c = 0.0;                                                             \
                                                                               \
    /* */                                                                      \
    double total_time = 0.0;                                                   \
    double elapsed = 0.0;                                                      \
    struct timespec before, after;                                             \
                                                                               \
    /* */                                                                      \
    double number_of_ite = N_MAX;                                              \
                                                                               \
    /* */                                                                      \
    do                                                                         \
      {                                                                        \
        /* */                                                                  \
        clock_gettime(CLOCK_MONOTONIC_RAW, &before);                           \
        {                                                                      \
          for (int i = 0; i < number_of_ite; i++)                              \
            {                                                                  \
              c = a op b;                                                      \
            }                                                                  \
        }                                                                      \
        clock_gettime(CLOCK_MONOTONIC_RAW, &after);                            \
                                                                               \
        /* */                                                                  \
        elapsed = after.tv_nsec - before.tv_nsec;                              \
                                                                               \
      }                                                                        \
    while (elapsed < 0.0);                                                     \
                                                                               \
    /* */                                                                      \
    total_time = elapsed;                                                      \
                                                                               \
    /* Mean */                                                                 \
    double mean_time = total_time / N_MAX;                                     \
                                                                               \
    /* Nanosecond to second */                                                 \
    double mean_time_sec = mean_time / 1.0e9;                                  \
                                                                               \
    /* Compute size */                                                         \
    double total_size = 3 * sizeof(float) * number_of_ite;                     \
    double total_size_gib = total_size / (1024 * 1024 * 1024);                 \
                                                                               \
    /* Compute gibs */                                                         \
    double gibs = total_size_gib / mean_time_sec;                              \
                                                                               \
    /* Print bandwidth */                                                      \
    fprintf(stderr, "%s_float; %f\n", #name, gibs);                            \
                                                                               \
    return gibs;                                                               \
  }

define_run_op_float(+, add);
define_run_op_float(-, sub);
define_run_op_float(*, mul);
define_run_op_float(/, div);

#define define_run_op_floatX(size, op, name)                                   \
  double run_##name##_float##size(double x, double y)                          \
  {                                                                            \
    /* */                                                                      \
    float##size a = (float)x;                                                  \
    float##size b = (float)y;                                                  \
    float##size c = 0.0;                                                       \
                                                                               \
    /* */                                                                      \
    double total_time = 0.0;                                                   \
    double elapsed = 0.0;                                                      \
    struct timespec before, after;                                             \
                                                                               \
    /* */                                                                      \
    double number_of_ite = N_MAX / size;                                       \
                                                                               \
    /* */                                                                      \
    do                                                                         \
      {                                                                        \
        /* */                                                                  \
        clock_gettime(CLOCK_MONOTONIC_RAW, &before);                           \
        {                                                                      \
          for (int i = 0; i < number_of_ite; i++)                              \
            {                                                                  \
              c = a op b;                                                      \
            }                                                                  \
        }                                                                      \
        clock_gettime(CLOCK_MONOTONIC_RAW, &after);                            \
                                                                               \
        /* */                                                                  \
        elapsed = after.tv_nsec - before.tv_nsec;                              \
                                                                               \
      }                                                                        \
    while (elapsed < 0.0);                                                     \
                                                                               \
    /* */                                                                      \
    total_time = elapsed;                                                      \
                                                                               \
    /* Mean */                                                                 \
    double mean_time = total_time / N_MAX;                                     \
                                                                               \
    /* Nanosecond to second */                                                 \
    double mean_time_sec = mean_time / 1.0e9;                                  \
                                                                               \
    /* Compute size */                                                         \
    double total_size = 3 * sizeof(float##size) * number_of_ite;               \
    double total_size_gib = total_size / (1024 * 1024 * 1024);                 \
                                                                               \
    /* Compute gibs */                                                         \
    double gibs = total_size_gib / mean_time_sec;                              \
                                                                               \
    /* Print bandwidth */                                                      \
    fprintf(stderr, "%s_float%d; %f\n", #name, size, gibs);                    \
                                                                               \
    return gibs;                                                               \
  }

define_run_op_floatX(2, +, add);
define_run_op_floatX(4, +, add);
define_run_op_floatX(8, +, add);

define_run_op_floatX(2, -, sub);
define_run_op_floatX(4, -, sub);
define_run_op_floatX(8, -, sub);

define_run_op_floatX(2, *, mul);
define_run_op_floatX(4, *, mul);
define_run_op_floatX(8, *, mul);

define_run_op_floatX(2, /, div);
define_run_op_floatX(4, /, div);
define_run_op_floatX(8, /, div);

#define define_speedup(name)                                            \
  void speedup_##name(x, y)                                             \
  {                                                                     \
    double baseline = run_##name##_float(x, y);                         \
    double gibs_2x = run_##name##_float2(x, y);                         \
    double gibs_4x = run_##name##_float4(x, y);                         \
    double gibs_8x = run_##name##_float8(x, y);                         \
                                                                        \
    fprintf(stderr, "%s_float2; %f\n", #name, gibs_2x / baseline);      \
    fprintf(stderr, "%s_float4; %f\n", #name, gibs_4x / baseline);      \
    fprintf(stderr, "%s_float8; %f\n", #name, gibs_8x / baseline);      \
  }

define_speedup(add);
define_speedup(sub);
define_speedup(mul);
define_speedup(div);

int main(int argc, char **argv)
{
  if (argc != 3)
    return 1;

  double x = strtod(argv[1], NULL);
  double y = strtod(argv[2], NULL);

  speedup_add(x, y);
  speedup_sub(x, y);
  speedup_mul(x, y);
  speedup_div(x, y);

  return 0;
}
