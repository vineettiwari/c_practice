// strtok.c
#define BUFFER_SIZE 70

#include <stdio.h>
#include <string.h>

int main( void )
{
	char *pToken = NULL;
	char csvLine[BUFFER_SIZE] = "element1,  element2, element3,element4, element5, element6";
	int counter;

	printf("\n%p  %s\n\n", csvLine, csvLine);

	for(counter = 0; counter < BUFFER_SIZE; counter++)
	{
		printf("%p\t%c\t%d\n", &csvLine[counter], csvLine[counter],csvLine[counter]);
	}

	printf("\n");
	
	pToken = strtok(csvLine, ", ");

	while(pToken != NULL)
	{
		printf("%p  '%s'\n", pToken, pToken);
		pToken = strtok(NULL, ", ");
	}

	printf("\n%p  %s\n\n", csvLine, csvLine);

	for(counter = 0; counter < BUFFER_SIZE; counter++)
	{
		printf("%p\t%c\t%d\n", &csvLine[counter], csvLine[counter], csvLine[counter]);
	}

	return 0;
}
