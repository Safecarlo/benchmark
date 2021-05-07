#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  if (argc != 5)
    return 1;

  int n = atoi(argv[2]);
  double a = strtod(argv[3], NULL);
  double b = strtod(argv[4], NULL);

  if (a == 0.0 || b == 0.0)
    {
      fprintf(stderr, "%s_float%d; 0.0\n", argv[1], n);
    }
  else
    {
      fprintf(stderr, "%s_float%d; %f\n", argv[1], n, a / b);
    }
  
  return 0;
}
