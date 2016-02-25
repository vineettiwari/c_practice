/*
 *	COMP 2717 Assgn 03
 *	reverseBits.c
 *	Purpose: To reverse binary value using bitwise operations
 *
 *	@author Vineet Tiwari
 *	@version 1.0 1/29/16
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 32
#define MIN_BITS 8

// Function prototypes
unsigned ReverseBits(unsigned, unsigned);
int GetWidth(unsigned);
void PrintBits(unsigned, unsigned);

int main()
{
	unsigned value = 0,
	reversedValue = 0,
	width = 0;

	// Get user input
	printf("\nEnter Integer: ");
	scanf("%u", &value);

	// Get the reversed value
	reversedValue = ReverseBits(value, MAX_BITS);

	// Get column width for output
	width = GetWidth(reversedValue);

	// Print decimal and binary value
	printf("\n%*u = ", width, value);
	PrintBits(value, MAX_BITS);

	// Print reversed decimal and binary value
	printf("\n%*u = ", width, reversedValue);
	PrintBits(reversedValue, MAX_BITS);
	
	printf("\n");
	return EXIT_SUCCESS;
}

// Function to reverse the binary value
unsigned ReverseBits(unsigned value, unsigned numBits)
{
 	unsigned  index = 0,
	reversedValue = 0,
	bitMask = 1 << (numBits - 1);

	for (; index < numBits; index++) {
		// If this bit in the value is ON(1)
		if(value & (1 << index))
		// Store it in reversedValue the opposite end
		reversedValue |= (bitMask >> index);
	}
	return reversedValue;
}

// Function to get the column width
int GetWidth(unsigned value)
{
	int width = 0;

	// Count the number if digits in the value
	while (value) {
		value /= 10;
		width++;
	}
	return width;
}

// Function to display the binary value
void PrintBits(unsigned value, unsigned numBits)
{ 
	unsigned count = 1,
	bitMask = 1 << (numBits - 1);

	// Print all the bits in the value
	for (; count <= numBits; count++) { 
		putchar(value & bitMask ? '1' : '0');
		bitMask >>= 1;

		// Put a space after 8 bits
		if (count % MIN_BITS == 0) 
			putchar(' ');
	}
	putchar('\n');
}

