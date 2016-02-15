// bitwise2.c
#include <stdio.h>

void displayBits(unsigned);

int main(void)
{ 
    unsigned amountOne; 
    unsigned amountTwo;
    unsigned mask;   
    unsigned setBits;

    // demonstrate bitwise AND (&)
    amountOne = 65535;
    mask = 1;
    printf("The result of combining the following\n");
    displayBits(amountOne);
    displayBits(mask);
    printf("\nusing the bitwise AND operator & is\n");
    displayBits(amountOne & mask);

    // demonstrate bitwise inclusive OR (|)
    amountOne = 15;
    setBits = 241;
    printf("\n\nThe result of combining the following\n");
    displayBits(amountOne);
    displayBits(setBits);
    printf("\nusing the bitwise inclusive OR operator | is\n");
    displayBits(amountOne | setBits);

    // demonstrate bitwise exclusive OR (^)
    amountOne = 139;
    amountTwo = 199;
    printf( "\n\nThe result of combining the following\n" );
    displayBits(amountOne);
    displayBits(amountTwo);
    printf("\nusing the bitwise exclusive OR operator ^ is\n");
    displayBits(amountOne ^ amountTwo);

    // demonstrate bitwise complement (~)
    amountOne = 21845;
    printf("\nThe one's complement of\n");
    displayBits(amountOne);
    printf("is\n");
    displayBits(~amountOne);
 
    printf("\n\n");

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