// union.c
#include <stdio.h>

union number 
{               
   int wholeNumber;                    
   double fractionalNumber;                 
};    

int main(void)
{ 
    union number value;
   
    value.wholeNumber = 100; // put an integer into the union
    printf( "%s\n%s\n\n%s     %d\n%s  %f\n\n\n",
       "Put a value in the integer member", 
       "and print both members.",
       "int:", value.wholeNumber, 
       "double:", value.fractionalNumber );

   
    value.fractionalNumber = 136.6; // put a double into the same union
    printf( "%s\n%s\n\n%s     %d\n%s  %f\n",
       "Put a value in the floating member",
       "and print both members.",
       "int:", value.wholeNumber, 
       "double:", value.fractionalNumber );


    printf("\nAddress of union:  %p", &value);
    printf("\nAddress of wholeNumber: %p", &value.wholeNumber);
    printf("\nAddress of fractionalNumber: %p\n", &value.fractionalNumber);

    printf("\nSize of union:  %u\n", sizeof(value));

    return 0;
} 