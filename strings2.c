// strings2.c
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>

int main(void)
{
    char *nameOne; 
    char nameTwo[11];

    char *pName = nameTwo;

    nameOne = "Moe Howard";

    strcpy(pName, "Larry Fine");
    //strncpy(nameTwo, "Larry Fine", 5);
    

    printf("%s\n%s\n%u\n%u\n"
           , pName
           , nameTwo
           , strlen(nameOne)
           , sizeof(nameOne));

    printf("\n\n%d %d\n"
           , strcmp(nameOne, nameTwo)
           , strcmp(nameTwo, nameOne));

    return 0;
}