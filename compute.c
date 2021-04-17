#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  if (argc != 5)
    return 1;

  int n = atoi(argv[2]);
  double a = strtod(argv[3], NULL);
  double b = strtod(argv[4], NULL);

  fprintf(stderr, "%s_float%d; %f\n", argv[1], n, a / b);
  
  return 0;
}
