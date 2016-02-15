// printfB.c
#include <stdio.h>


int main(void)
{
	int value1 = 100;
	int value2 = 200;

	printf("%d\t%p\n%d\t%p\n\n", value1, &value1, value2, &value2);

	return 0;
}