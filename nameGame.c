/**
    COMP 2717 Asn 2
    nameGame.c
    Purpose: Print out the users name in different
    arrangments.

    @author Vineet Tiwari
    @version 1.0 1/22/16
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFF_SIZE    64
#define C_RESET      "\e[0m"
#define C_RED        "\e[31m"
#define C_YELLOW     "\e[33m"
#define U_LINE	     "\e[4m"
#define C_BLUE       "\e[34m"
#define C_CYAN       "\e[36m"
#define CLEAR_SCREEN "\e[2J\e[1;1H"

//Forward Declaration.
char *namePermutation(char *, char *, char *, int);
void namePrinter();

//This is the single entry point to the program.
int main()
{
	namePrinter();

	return(EXIT_SUCCESS);
}

//Returns the concatenated string.
char *namePermutation(char *firstName, char *lastName, char *output, int selector)
{
	char tempArray[BUFF_SIZE];

	switch(selector)
	{
		case 1:
			strcpy(output, firstName);
			strcat(output, " ");
			strcat(output, lastName);
			break;

		case 2:
			strcpy(output, lastName);
			strcat(output, ", ");
			strcat(output, firstName);
			break;

		case 3:
			strcpy(tempArray, firstName);
			tempArray[1] = '\0';

			strcpy(output, lastName);
			strcat(output, ", ");
			strcat(output, tempArray);
			break;

		case 4:
			strcpy(output, firstName);
			strcat(output, ".");
			strcat(output, lastName);
			break;

		case 5:
			strcpy(tempArray, firstName);
			tempArray[1] = '\0';

			strcpy(output, tempArray);
			strcat(output, lastName);
			break;

		case 6:
			strcpy(tempArray, lastName);
			tempArray[1] = '\0';

			strcpy(output, tempArray);
			strcat(output, firstName);
			break;

		case 7:
			strcpy(tempArray, lastName);
			tempArray[0] = tolower(tempArray[0]);

			strcpy(output, firstName);
			output[0] = tolower(output[0]);

			strcat(output, ".");
			strcat(output, tempArray);
			strcat(output, "@mydomain.com");
			break;

		case 8:
			strcpy(tempArray, lastName);
			tempArray[0] = tolower(tempArray[0]);

			strcpy(output, firstName);
			output[0] = tolower(output[0]);
			output[1] = '\0';

			strcat(output, ".");
			strcat(output, tempArray);
			strcat(output, "@mydomain.com");
			break;

		default:
			printf("%s\n", "Invalid input.");
	}

	return output;
}

//Scans user input and prints the concatenated string.
void namePrinter()
{
	char firstName[BUFF_SIZE];
	char lastName[BUFF_SIZE];
	char output[BUFF_SIZE];
	size_t length, count;

	printf(CLEAR_SCREEN);
	fflush(stdout);
	printf(C_RED"%s "C_RESET, "Enter first name:");
	scanf("%s", firstName);
	fflush(stdin);

	printf(C_RED"%s "C_RESET, "Enter last name :");
	scanf("%s", lastName);
	fflush(stdin);

	printf("\n");

	for(count = 1; count <= 8; count++)
	{
		namePermutation(firstName, lastName, output, count);
		length = strlen(output);
		printf(C_RESET C_BLUE"%.2zu "U_LINE C_YELLOW"%s\n", length, output);
	}

	printf(C_RESET"\n");
}
