#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  if (argc != 4)
    return 1;

  int n = atoi(argv[1]);
  double a = strtod(argv[2], NULL);
  double b = strtod(argv[3], NULL);

  fprintf(stderr, "add_float%d; %f\n", n, a / b);
  
  return 0;
}
