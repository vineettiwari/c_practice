#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

size_t myStrlen(char *user_input)
{
	size_t index, count;

	index = count = 0;

	while(user_input[index] != '\0')
	{
		index++;
		count++;
	}

	return count;
}

int main()
{
	char user_input[BUFFER_SIZE];
	size_t len;

	printf("%s ", "Enter a string:");
	fgets(user_input, BUFFER_SIZE, stdin);

	len = myStrlen(user_input);

	user_input[len - 1] = '\0';
	len = myStrlen(user_input);

	puts(user_input);
	printf("String length: %zu\n", len);

	return(0);
}
