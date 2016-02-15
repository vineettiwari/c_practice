#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 100

int vowelCounter(char *);
int vowelFinder(char);

int main()
{
	char userInput[BUFFER_SIZE];
	int index, vowelCount;
	vowelCount = 0;

	printf("\n%s ", "Enter your string:");
	fgets(userInput, BUFFER_SIZE, stdin);

	vowelCount = vowelCounter(userInput);

	printf("\nVowel count: %-.2d\n\n", vowelCount);

	return(0);
}

int vowelCounter(char *userInput)
{
	int index, vowelCount;
	vowelCount = 0;

	for(index = 0; userInput[index] != '\0'; index++)
	{
		if(vowelFinder(userInput[index]) == 0)
		{
			vowelCount++;
		}
	}

	return vowelCount;
}

int vowelFinder(char character)
{
	switch(tolower(character))
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return 0;
		default:
			return 1;
	}
}
