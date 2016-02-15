// pointers.c
#include <stdio.h>

int main(void)
{
	int count = 100;

	int *pCount = &count; // holds address of count

	printf("Value:   %d\nAddress: %p\n\n"
		   , count
		   , &count);

	*pCount = 150; // assigning new value to dereferenced pointer

	printf("Value:   %d\nAddress: %p\n\n"
		   , count
		   , &count);

	printf("Value:   %d\nAddress: %p\n\n"
		   , *pCount
		   , pCount);


	return 0;
}