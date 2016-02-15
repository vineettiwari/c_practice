// bitwise1.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void displayBits(unsigned);

int main(void)
{ 
	unsigned value; // value from user
   
    // prompt user and read value
    printf( "Enter an integer: " );
    scanf( "%u", &value ); 
   
    // display value before shifting
    printf( "\n%u before right shifting 4 bits is:\n", value );
    displayBits( value );

    // display value after shifting right
    printf( "\n%u after right shifting 4 bits is:\n", value );
    displayBits( value >> 4 );

    // display value after shifting left
    printf( "\n%u after left shifting 4 bits is:\n", value );
    displayBits( value << 4 );

    printf( "\n" );

    return 0;
}

// display bits of an unsigned integer value
void displayBits(unsigned value)
{ 
    unsigned count; 
    // declare displayMask and left shift 31 bits
    unsigned displayMask = 1 << 31;

    printf("%12u = ", value);

    // loop through bits
    for (count = 1; count <= 32; count++)
    { 
		putchar(value & displayMask ? '1' : '0');
     	displayMask >>= 1; // shift mask right by 1

        // insert space every 8 bits (1 byte)
	    if (count % 8 == 0) 
	    {
			putchar(' ');
        }
    } 

    putchar('\n');
} 