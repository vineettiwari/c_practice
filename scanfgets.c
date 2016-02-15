// scanfgets.c
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>

int main(void)
{
    char wordOne[100];
    char wordTwo[100];
   // char input[10];
    
    scanf("%s", wordOne);
    while (getchar() != '\n');
    
    scanf("%s", wordTwo);
    while (getchar() != '\n');

  //  printf("Enter some text: ");

    //gets(input);

  //	fgets(input, 10, stdin);

    printf("%s\n%s\n", wordOne, wordTwo);

//	printf("You entered: %s\n", input);


    return 0;
}