// bitwise4.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void displayBits(unsigned);

int main(void)
{ 
	unsigned value;
	unsigned mask = 1;
	int counter;

	printf("Enter a number between 0 and 255: ");
	scanf("%u", &value);

    displayBits(value);
	printf("\n\n");

	for (counter = 0; counter < 8; counter++)
	{
		printf("         Bit %d is %s\n", counter, value & mask ? "on" : "off");
		mask <<= 1;
	}
     
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