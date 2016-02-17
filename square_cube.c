/*
COMP2717 Assignment Criteria        Possible  Actual
====================================================
Produces the correct results               3       3
 Yes

Implements a high quality algorithm        4       2
 far too complex for a simple project
 unnecessary data structures
 increment the loop by 2 and avoid the MOD

Formats output correctly                   2       2
 Yes

Follows the assigned coding standard       1       1
 Yes

----------------------------------------------------
Total:                                    10       8
*/

/*
	Assignment One - Square&Cube Number Table
	Auther - Vineet Tiwari
	Copyright 2016
*/

#include <stdio.h>                        /* Incliding C Libraries    */
#include <math.h>
#include <ctype.h>

typedef struct                            /* Structure to hold user   */  
{                                         /* input(upper limit).      */
	int value,
	scanCount;
} UpperLimit;

typedef struct                            /* Structure to hold values */
{                                         /* for producing the table. */
	unsigned value, sum;

	unsigned long squared,
	 cubed, squaredSum,
	 cubedSum;
} Number;

Number setToZero();                       /* Forward declaration      */

UpperLimit getUpperLimit();

Number runCalculationOn();

void printSeparator(void);

void printSquareCubeTable(UpperLimit upperLimit,
 Number number);

int main()                                /* Main Function(Software   */
{                                         /* Scope).                  */
	UpperLimit upperLimit;

	Number number;

	number = setToZero();

	upperLimit = getUpperLimit();

	printSquareCubeTable(upperLimit, number);

	return(0);
}

Number setToZero()                        /* Initializing Number      */
{                                         /* Structure                */
	Number number;
	number.value = 0;
	number.squared = 0;
	number.cubed = 0;
	number.sum = 0;
	number.squaredSum = 0;
	number.cubedSum = 0;

	return number;
}

UpperLimit getUpperLimit()                /* Function for printing    */
{                                         /* Welcome Message & taking */
	UpperLimit upperLimit;                  /* user input.              */

	printf("\nWelcome to Square&Cube Table Generator!\n");

	do {
		printf("The input value must be less than 1000!\n");

		printf("Enter upper limit: ");

		upperLimit.scanCount = scanf("%d", &upperLimit.value);

	} while(upperLimit.value > 1000);

	return upperLimit;
}

Number runCalculationOn(Number *number)    /* Function for calculating */
{                                          /* the values for the table.*/
	number->sum += number->value;

	number->squared = pow(number->value, 2);
	number->squaredSum += number->squared;

	number->cubed = pow(number->value, 3);
	number->cubedSum += number->cubed;

	return *number;
}

void printSeparator(void)                   /* Function for printing    */
{                                           /* the row separator.       */
	printf("%s\n",
		"--------------------------------------------");
}

void printSquareCubeTable(UpperLimit upperLimit,
	Number number)                            /* Function for placing the */
{                                           /* valuse appropriately,    */
	printf("\n%10s %s\n",                     /* then printing the table. */
		"", "Square&Cube Table");

	printf("\n%16s %13s %13s\n",
		"Number",
		"Squar",
		"Cube");

	printSeparator();

	for (; number.value < (upperLimit.value + 1) ; ++number.value)
	{
		if (number.value % 2 == 0) /// increment the loop by 2 and avoid the MOD operation
		{
			number = runCalculationOn(&number);

			printf("%16u %13lu %13lu\n",
				number.value, 
				number.squared, 
				number.cubed);
			}
		}

		printSeparator();

		printf("%-7s %8u %13lu %13lu\n\n",
			"Total:",
		  number.sum, 
		  number.squaredSum, 
		  number.cubedSum);
}
