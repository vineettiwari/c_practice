// Purpose: To practice and test code.
// Current: To understand nested functions and function pointers.

#include <stdio.h>
#include <stdlib.h>

int total;

int Square(int x)
{
	return (x * x);
}

int SquareOfSum(int a, int b)
{
  return Square(a + b);
}

int main()
{
  int (*pSquareOfSum)(int, int);
  pSquareOfSum = SquareOfSum;

  total = pSquareOfSum(2, 3);

  printf("\n(2 + 5)^2 = ");
  printf("%d\n", total);

  printf("\n");
  return EXIT_SUCCESS;
}