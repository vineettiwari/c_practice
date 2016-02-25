/*
 * Purpose: To practice and test code.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	time_t biggest = 0x7FFFFFFF;
	printf("\nbiggest = %s \n", asctime(gmtime(&biggest)));
	return EXIT_SUCCESS;
}
