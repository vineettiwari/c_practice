// dma2.c
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] )
{ 
    int *numbers;

    numbers = (int*) calloc(10, sizeof(int)); // elements, element size

    numbers[4] = 100;
    numbers[8] = 200;

    printf("Address: %p\nElement   0: %d\nElement   4: %d\nElement   8: %d\n\n"
                             , numbers
                             , numbers[0]
                             , numbers[4]
                             , numbers[8]);

    
    numbers = (int*) realloc(numbers, 80); // array ptr, size in bytes
    
    numbers[15] = 300;
    
    printf("Address: %p\nElement   0: %d\nElement   4: %d\nElement   8: %d\nElement  15: %d\n\n"
                             , numbers
                             , numbers[0]
                             , numbers[4]
                             , numbers[8]
                             , numbers[15]);	

    
    numbers = (int*) realloc(numbers, 40); // array ptr, size in bytes
    
    
    printf("Address: %p\nElement   0: %d\nElement   4: %d\nElement   8: %d\nElement  15: %d\n\n"
                             , numbers
                             , numbers[0]
                             , numbers[4]
                             , numbers[8]
                             , numbers[15]);	
                             
    numbers = (int*) realloc(numbers, 8000); // array ptr, size in bytes
    
    numbers[500] = 2200;
    
    printf("Address: %p\nElement   0: %d\nElement   4: %d\nElement   8: %d\nElement  15: %d\nElement 500: %d\n"
                             , numbers
                             , numbers[0]
                             , numbers[4]
                             , numbers[8]
                             , numbers[15]
                             , numbers[500]);

    free(numbers); // dynamically allocated, so must be freed

    return 0;
}
