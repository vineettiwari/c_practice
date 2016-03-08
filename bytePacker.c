// bytePacker.c

// Student Name: Vineet Tiwari

/*
COMP2717 Midterm Question #2

Criteria                            Possible  Actual
====================================================
Produces the correct results               4     

Implements a high quality algorithm        4       

Formats output correctly                   1       

Follows the assigned coding standard       1       

----------------------------------------------------
Total:                                    10       ?

Instructions

Complete the main() function and create a packCharacters() function.

The packCharacters() function will have an array containing 4 chars as 
its only parameter. The function must pack the 4 chars into a single 
unsigned int. The first char in the array should be put in the left 
most byte of the unsigned int; the second char in the array should be 
put in the second left most byte of the unsigned int; and so on. 
The function will return the unsigned int containing the 4 chars.  
HINT: You will need to use bitwise operators to program this function.

The main()function will ask the user to input 4 characters. Your main() 
program should store the 4 characters in an array. The displayBits() 
function should be used to show the bit representation of each character. 
The program will then invoke the packCharacters() function. Then invoke 
the displayBits() function with the result returned by your packCharacters() 
function to prove that the function packed the 4 chars into the unsigned 
int successfully. 

Enter your name in the space provided above.

ZIP your modified .c file along with the .c file from Q1
Submit your ZIP file to Midterm under Exams in the D2L Dropbox

DO NOT MODIFY ANY OF THE EXISTING CODE 
SIMPLY ADD THE REQUIRED CODE TO COMPLETE
ALL EXISTING CODE MUST BE USED

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX 4
#define MAX_BITS 32

// function prototypes
void displayBits(unsigned, unsigned);
unsigned packCharacters(char[MAX_INDEX]);

int main()
{
	unsigned temp;					// used to display the bits in a char
	unsigned packedBits;		// to contain result of packing bits
	char input[MAX_INDEX];	// Array to contain the 4 input chars
	// complete main function code
	for(int i = 0; i < MAX_INDEX; i++)
	{
		printf("\nEnter a character: ");
		input[i] = getchar();
		while(getchar() != '\n');
		temp = input[i];
		printf("\n");
		displayBits(temp, MAX_BITS);
	}
	packedBits = packCharacters(input);
	printf("\n");
	displayBits(packedBits, MAX_BITS);

	printf("\n");
	return EXIT_SUCCESS;
}

// display bits of an unsigned integral value
void displayBits(unsigned value, unsigned numBits)
{ 
	unsigned count, displayMask = 1 << (numBits - 1);
	printf("%10u = ", value);
	for (count = 1; count <= numBits; count++)
	{ 
		putchar(value & displayMask ? '1' : '0');
		displayMask >>= 1;
		if(count % (MAX_INDEX * 2) == 0) 
		{
			putchar(' ');
		}
	} 
	putchar('\n');
} 

// create packCharacters function here
unsigned packCharacters(char input[MAX_INDEX])
{
	// Unsigned int to store result of the packed bits 
	unsigned packedBits = 0;
	int i, j;
	// Bitwise operations to pack the bits
	for(i = 0, j = MAX_INDEX - 1; i < MAX_INDEX; i++, j--)
	{
		packedBits |= (input[i] << (MAX_INDEX * j * 2));
	}
	printf("\n%18s\n", "Result:");
	return packedBits;
}

