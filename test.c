#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
  return a + b;
}

int main()
{
  int c;
  int (*pAdd)(int, int);
  pAdd = add;

  c = pAdd(2, 3);

  printf("The valuse stored in i: %d\n", c);

  return EXIT_SUCCESS;
}