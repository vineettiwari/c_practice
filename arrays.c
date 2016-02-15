// arrays.c
#include <stdio.h>

int main(void)
{
	int count, elementCount, *pOne, *pTwo;
	int numbers[] = { 10, 20, 30, 40, 50 };
	
	printf("Address array:     %p\nAddress Element 0: %p\nAddress Element 1: %p\nAddress Element 2: %p\n\n"
		  , numbers
		  , &numbers[0]
	      , &numbers[1]
		  , &numbers[2]);
	
	elementCount = sizeof(numbers) / sizeof(int);

	printf("Array size:    %d\nElement size:  %d\nElement count: %d\n\n"
		  , sizeof(numbers)
		  , sizeof(int)
		  , elementCount);

	pOne = numbers;

	pTwo = pOne;

	for (count = 0; count < elementCount; count++)
	{
		printf("%d  ", numbers[count]);
	}

	printf("\n\n");


	while (*pTwo != 40)
	{
		pTwo++;
	}

	printf("pOne ->      %d\npTwo ->      %d\npTwo - 2 ->  %d\npTwo - pOne: %d\n\n"
		  , *pOne
		  , *pTwo
		  , *(pTwo - 2)
		  , pTwo - pOne);


	return 0;
}