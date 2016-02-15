// bitwise3.c
#include <stdio.h>

void displayBits(unsigned);

int main(void)
{ 
	unsigned value = 255;
   
    printf( "\n%u before any bit manipulations:\n", value );
    displayBits(value);
     
    printf("\n%u after turning off bit #5 (value &= ~(1 << 5)):\n", value);
	displayBits(value);
	printf("               -----------------------------------\n");
	displayBits(1 << 5);
	displayBits(~(1 << 5));
	printf("               -----------------------------------\n");
    displayBits(value &= ~(1 << 5));

    printf("\n%u after turning on bit #5 (value |= 1 << 5):\n", value);
	displayBits(value);
	displayBits(1 << 5);
	printf("               -----------------------------------\n");
	displayBits(value |= 1 << 5);

    printf( "\n%u after toggling bit #5: (value ^= 1 << 5)\n", value );
	displayBits(value);
	displayBits(1 << 5);
	printf("               -----------------------------------\n");
	displayBits(value ^= 1 << 5);

    printf( "\n%u after toggling bit #5: (value ^= 1 << 5)\n", value );
	displayBits(value);
	displayBits(1 << 5);
	printf("               -----------------------------------\n");
    displayBits(value ^= 1 << 5);

    printf("\n");

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