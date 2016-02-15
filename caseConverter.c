#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *toUpperCase(char *);
char *toLowerCase(char *);

int main()
{
	char input[100];

	printf("%s ", "Enter a character:");

	scanf("%s", input);

	if(input[0] >= 'a' && input[0] <= 'z')
	{
		printf("%s\n", toUpperCase(input));

	} else if(input[0] >= 'A' && input[0] <= 'Z')
	{
		printf("%s\n", toLowerCase(input));
	}

	return(EXIT_SUCCESS);
}

char *toUpperCase(char *input)
{
	int count = 0;

	for( ; count < strlen(input); count++)
	{
		input[count] &= 95 //Dec: 95 ==> Bin: 0101 1111
	}                    //input[count]  &  0101 1111

	return input;
}

char *toLowerCase(char *input)
{
	int count = 0;

	for( ; count < strlen(input); count++)
	{
		input[count] |= 32 //Dec: 32 ==> Bin: 0010 0000
	}                    //input[count]  &  0010 1111

	return input;
}
