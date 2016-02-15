// strings3.c
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>

int main(void)
{
	int result;

	char stringOne[50] = "hello";
	char stringTwo[50] = "hello";

	printf("stringOne length: %u\n", strlen(stringOne));
	printf("stringTwo length: %u\n\n", strlen(stringTwo));

	result = strcmp(stringOne, stringTwo);

	if( result > 0 )
    {
       printf("stringOne is greater then stringTwo\n");
    }
    else if( result < 0 )
    {
       printf("stringOne is less then stringTwo\n");
    }
    else
    {
       printf("stringOne is equal to stringTwo\n");
    }

	strcat(stringOne, stringTwo);
//	strncat(stringOne, stringTwo, 4); 
	printf("\n%s\n\n", stringOne);


	return 0;
}