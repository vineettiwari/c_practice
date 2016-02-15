// scanf.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Name and age Function
void showInfo(char *firstName, char *lastName, int age)
{
	printf("\nReceipt\n");
	printf("%-14s %-14s %6s\n%s\n", "First Name", "Last Name", "Age", "------------------------------------");
	printf("%-14s %-14s %6d\n", firstName, lastName, age);
}

//Main Function
int main()
{
	char firstName[18];
	char lastName[18];
	int age;

	printf("Enter First Name  : ");
	scanf("%s", firstName);
	fseek(stdin,0,SEEK_END);

	printf("Enter Last Name   : ");
	scanf("%s", lastName);
	fseek(stdin,0,SEEK_END);

	printf("Enter age         : ");
	int ageScanCount = scanf("%d", &age);
	fseek(stdin, 0, SEEK_END);

	if(isalpha(*firstName) && isalpha(*lastName) && ageScanCount == 1)
	{
		showInfo(firstName, lastName, age);
	}
	else
	{
		puts("Invalid input.");
	}

	return(0);
}


// #define _CRT_SECURE_NO_WARNINGS // squelches scanf warning

// #include <stdio.h>

// int main(void)
// {
// 	char firstName[50];
// 	char lastName[50];
// 	int age;

// 	// printf("First Name: ");
// 	// scanf("%s", firstName);

// 	// printf("Last Name : ");
// 	// scanf("%s", lastName);

// 	// printf("Age       : ");
// 	// scanf("%d", &age);

// 	// printf("\n%s %s entered an age of %d.\n\n\n", firstName, lastName, age);


// 	printf("First Name: ");
// 	scanf("%s", firstName);
// 	fflush(stdin);
// 	//fseek(stdin, 0, SEEK_END);
// 	//while (getchar() != '\n');


// 	printf("Last Name : ");
// 	scanf("%s", lastName);
// 	fflush(stdin);

// 	printf("Age       : ");
// 	int scan_count = scanf("%d", &age);
// 	printf("%d\n", scan_count);
// 	fseek(stdin, 0, SEEK_END);
// 	while (getchar() != '\n');
// 	// fflush(stdin);

// 	printf("\n%s %s entered an age of %d.\n\n\n", firstName, lastName, age);

// 	return 0;
// }