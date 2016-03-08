// cmdlineargs.c
#include <stdio.h>

int main( int argc, char *argv[] )
{ 
    int count;

    printf("Arg count: %d\n", argc);

    for (count = 0; count < argc; count++)
    {
        printf("argv[%d]: %s\n", count, argv[count]);
    }
    
    return 0;
}