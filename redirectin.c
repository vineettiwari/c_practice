// redirectin.c

#define BUFFER_SIZE 1000

#include <stdio.h>

int main( void )
{ 
    char data[BUFFER_SIZE + 1]; // add 1 for null terminater
    
    fgets(data, BUFFER_SIZE, stdin);
    
    while (!feof(stdin))
    {
        printf("Input: %s", data);
        fgets(data, BUFFER_SIZE, stdin);
    }

    return 0;
}
