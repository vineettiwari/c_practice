// strings1.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buffer[100] = "This is a test, only a test";

	printf("%s\n", buffer);
	buffer[14] = '\0';
	
	printf("%s\n", buffer);
	buffer[14] = ':';
	
	printf("%s\n\n", buffer);

	return 0;
}