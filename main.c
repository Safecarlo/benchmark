#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N_MAX 1000000
#define SAMPLE 10

typedef float float2 __attribute__((ext_vector_type(2)));
typedef float float4 __attribute__((ext_vector_type(4)));
#if __AVX__
typedef float float8 __attribute__((ext_vector_type(8)));
#endif

#define define_run_op_float(op, name)                                          \
  double run_##name##_float(double x, double y)                                \
  {                                                                            \
    /* */                                                                      \
    float a = (float)x;                                                        \
    float b = (float)y;                                                        \
    float c = 0.0;                                                             \
                                                                               \
    /* */                                                                      \
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
        elapsed = (double)(after.tv_nsec - before.tv_nsec);                    \
                                                                               \
      }                                                                        \
    while (elapsed < 0.0);                                                     \
                                                                               \
    /* elapsed time in seconds */                                              \
    double elapsed_sec = elapsed / 10.0e9;                                     \
                                                                               \
    /* Compute gflops */                                                       \
    double gflops = (N_MAX / 1000) / elapsed_sec;                              \
                                                                               \
    return gflops;                                                             \
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
        elapsed = (double)(after.tv_nsec - before.tv_nsec);                    \
                                                                               \
      }                                                                        \
    while (elapsed < 0.0);                                                     \
                                                                               \
    /* elapsed time in seconds */                                              \
    double elapsed_sec = elapsed / 10.0e9;                                     \
                                                                               \
    /* Compute gflops */                                                       \
    double gflops = (N_MAX / 1000) / elapsed_sec;                              \
                                                                               \
    return gflops;                                                             \
  }

define_run_op_floatX(2, +, add);
define_run_op_floatX(2, -, sub);
define_run_op_floatX(2, *, mul);
define_run_op_floatX(2, /, div);

define_run_op_floatX(4, +, add);
define_run_op_floatX(4, -, sub);
define_run_op_floatX(4, *, mul);
define_run_op_floatX(4, /, div);

#if __AVX__
define_run_op_floatX(8, +, add);
define_run_op_floatX(8, -, sub);
define_run_op_floatX(8, *, mul);
define_run_op_floatX(8, /, div);
#endif

//
void sort(double *a, unsigned n)
{
  //
  for (unsigned i = 0; i < n; i++)
    for (unsigned j = i + 1; j < n; j++)
      if (a[i] > a[j])
        {
          double tmp = a[i];

          a[i] = a[j];
          a[j] = tmp;
        }
}

//
double mean(double *a, unsigned n)
{
  //
  double m = 0.0;

  //
  for (unsigned i = 0; i < n; i++)
    m += a[i];

  //
  return m / (double)n;
}

//
double stddev(double *a, unsigned n)
{
  //
  double d = 0.0;
  double m = mean(a, n);
  
  //
  for (unsigned i = 0; i < n; i++)
    d += (a[i] - m) * (a[i] - m);

  //
  d /= (double)(n - 1);
  
  //
  return sqrt(d);
}

#if __AVX__
#define define_speedup(name)                                                   \
  void speedup_##name(x, y)                                                    \
  {                                                                            \
    double baseline[SAMPLE];                                                   \
    double gflops_2x[SAMPLE];                                                  \
    double gflops_4x[SAMPLE];                                                  \
    double gflops_8x[SAMPLE];                                                  \
                                                                               \
    for (int i = 0; i < SAMPLE; i++)                                           \
      {                                                                        \
        baseline[i] = run_##name##_float(x, y);                                \
        gflops_2x[i] = run_##name##_float2(x, y);                              \
        gflops_4x[i] = run_##name##_float4(x, y);                              \
        gflops_8x[i] = run_##name##_float8(x, y);                              \
      }                                                                        \
                                                                               \
    sort(baseline, SAMPLE);                                                    \
    sort(gflops_2x, SAMPLE);                                                   \
    sort(gflops_4x, SAMPLE);                                                   \
    sort(gflops_8x, SAMPLE);                                                   \
                                                                               \
    double mean_baseline = mean(baseline, SAMPLE);                             \
    double mean_gflops_2x = mean(gflops_2x, SAMPLE);                           \
    double mean_gflops_4x = mean(gflops_4x, SAMPLE);                           \
    double mean_gflops_8x = mean(gflops_8x, SAMPLE);                           \
                                                                               \
    double stddev_baseline = stddev(baseline, SAMPLE);                         \
    double stddev_gflops_2x = stddev(gflops_2x, SAMPLE);                       \
    double stddev_gflops_4x = stddev(gflops_4x, SAMPLE);                       \
    double stddev_gflops_8x = stddev(gflops_8x, SAMPLE);                       \
                                                                               \
    double stddevp_baseline = (stddev_baseline * 100) / mean_baseline;         \
    double stddevp_gflops_2x = (stddev_gflops_2x * 100) / mean_gflops_2x;      \
    double stddevp_gflops_4x = (stddev_gflops_4x * 100) / mean_gflops_4x;      \
    double stddevp_gflops_8x = (stddev_gflops_8x * 100) / mean_gflops_8x;      \
                                                                               \
    fprintf(stderr, "%s%s; %f; %f; %f%%\n", #name, "_float", mean_baseline,    \
            1.0, stddevp_baseline);                                            \
    fprintf(stderr, "%s%s; %f; %f; %f%%\n", #name, "_float2", mean_gflops_2x,  \
            mean_gflops_2x / mean_baseline, stddevp_gflops_2x);                \
    fprintf(stderr, "%s%s; %f; %f; %f%%\n", #name, "_float4", mean_gflops_4x,  \
            mean_gflops_4x / mean_baseline, stddevp_gflops_4x);                \
    fprintf(stderr, "%s%s; %f; %f; %f%%\n", #name, "_float8", mean_gflops_8x,  \
            mean_gflops_8x / mean_baseline, stddevp_gflops_8x);                \
  }
#else
#define define_speedup(name)                                                   \
  void speedup_##name(x, y)                                                    \
  {                                                                            \
    double baseline[SAMPLE];                                                   \
    double gflops_2x[SAMPLE];                                                  \
    double gflops_4x[SAMPLE];                                                  \
                                                                               \
    for (int i = 0; i < SAMPLE; i++)                                           \
      {                                                                        \
        baseline[i] = run_##name##_float(x, y);                                \
        gflops_2x[i] = run_##name##_float2(x, y);                              \
        gflops_4x[i] = run_##name##_float4(x, y);                              \
      }                                                                        \
                                                                               \
    double mean_baseline = mean(baseline, SAMPLE);                             \
    double mean_gflops_2x = mean(gflops_2x, SAMPLE);                           \
    double mean_gflops_4x = mean(gflops_4x, SAMPLE);                           \
                                                                               \
    double stddev_baseline = stddev(baseline, SAMPLE);                         \
    double stddev_gflops_2x = stddev(gflops_2x, SAMPLE);                       \
    double stddev_gflops_4x = stddev(gflops_4x, SAMPLE);                       \
                                                                               \
    double stddevp_baseline = (stddev_baseline * 100) / mean_baseline;         \
    double stddevp_gflops_2x = (stddev_gflops_2x * 100) / mean_gflops_2x;      \
    double stddevp_gflops_4x = (stddev_gflops_4x * 100) / mean_gflops_4x;      \
                                                                               \
    fprintf(stderr, "%s%s; %f; %f; %f%%\n", #name, "_float", mean_baseline,    \
            1.0, stddevp_baseline);                                            \
    fprintf(stderr, "%s%s; %f; %f; %f%%\n", #name, "_float2", mean_gflops_2x,  \
            mean_gflops_2x / mean_baseline, stddevp_gflops_2x);                \
    fprintf(stderr, "%s%s; %f; %f; %f%%\n", #name, "_float4", mean_gflops_4x,  \
            mean_gflops_4x / mean_baseline, stddevp_gflops_4x);                \
    fprintf(stderr, "%s%s; %f; %f %f%%\n", #name, "_float8", 0.0, 0.0, 0.0);   \
  }
#endif

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
  speedup_div(x, 1.0);

  return 0;
}
