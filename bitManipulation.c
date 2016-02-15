/**
    COMP 2717 Assgn 03
    bitManipulation.c
    Purpose: Reverse the binary value of an Unsigned Int and print
    the Int of the reversed value.

    @author Vineet Tiwari
    @version 1.0 1/29/16
*/

#include <stdio.h>
#include <stdlib.h>

#define NO_OF_BITS 31


// Forward Declaration
unsigned reverseBits(unsigned);
int getColumnWidth(unsigned);
void printBits(unsigned);

// Value structure for storing user input
// and the reverd value of that input.
typedef struct
{
	unsigned initial,
		reversed;
}Value;

int main()
{
	// For C89 compatability
	Value *value = malloc(sizeof(Value));
	int columnWidth;

	printf("\nEnter an int value: ");

	// Get user input from stdin.
	scanf("%u", &value->initial);

	// Get the reversed value of user input.
	value->reversed = reverseBits(value->initial);

	// Get the length of the reversed Value
	// to getermin the output column width.
	columnWidth = getColumnWidth(value->reversed);

	// Display user input and its binary value.
	printf("%-*u = ", columnWidth, value->initial);
	printBits(value->initial);

	// Display the revrsed binary value and its
	// corosponding int value.
	printf("%-*u = ", columnWidth, value->reversed);
	printBits(value->reversed);

	free(value);
	
	printf("\n");
	return(EXIT_SUCCESS);
}

// Function to reverse the binary value of
// of the user input.
unsigned reverseBits(unsigned value)
{
    unsigned reverseValue = 0, bitIndex, tempValue;

    for (bitIndex = 0; bitIndex <= NO_OF_BITS; bitIndex++)
    {
        tempValue = (value & (1 << bitIndex));

        if(tempValue)
            reverseValue |= (1 << ((NO_OF_BITS) - bitIndex));
    }

    return reverseValue;
}

// Function to get the number of digits in the
// resulting int value.
int getColumnWidth(unsigned value)
{
	int columnWidth = 0;

	while(value)
	{
		value /= 10;
		columnWidth++;
	}

	return columnWidth;
}

// Function to print binary value from Unsigned Int.
void printBits(unsigned value)
{
  int bitIndex;

  for(bitIndex = NO_OF_BITS; bitIndex >= 0; bitIndex--)
  {
  	printf("%u", ((value >> bitIndex) & 1));

  	if(bitIndex % 8 == 0)
  		putchar(' ');
  }

 	printf("\n");
}
