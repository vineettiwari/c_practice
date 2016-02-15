#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct inventory
{
	char   	partName[30];
	double 	price;
	int    	partNumber,
				 	stockLevel,
				 	reorderLevel;
}Inventory;

typedef union data
{
	char   	charValue;
	int    	intValue;
	double 	doubleValue;
}Data;

typedef struct address
{
	char 	streetAddress[30],
				city[16],
				privence[4],
				postal[8];
}Address;

typedef struct student
{
	char 		firstName[16],
					lastName[16];
	Address studentAddress;
}Student;

Student *Student_create(char *firstName, char *lastName, Address *studentAddress)
{
	Student *newStudent = malloc(sizeof(Student));
	assert(newStudent != NULL);

	strcpy(newStudent->firstName, firstName);
	strcpy(newStudent->lastName, lastName);

	strcpy(newStudent->studentAddress.streetAddress, studentAddress->streetAddress);

	return newStudent;
}

int main()
{
	Address *studentAddress = malloc(sizeof(Address));

	strcpy(studentAddress->streetAddress, "223 7837, 120A Street");

	Student *vineet = Student_create("Vineet", "Tiwari", studentAddress);

	printf("\n%11s %-10s\n%11s %-10s\n%11s %-22s\n\n","First Name:", vineet->firstName, "Last Name:", vineet->lastName, "Address:", vineet->studentAddress.streetAddress);
  
  return(EXIT_SUCCESS);
}
