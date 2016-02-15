// dma.c
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
	char firstName[30];
	char lastName[30];
	int age;
};

typedef struct person Customer;


int main(void)
{
	Customer *pCustomer = NULL;
	
	Customer customer = { "Cosmo", "Kramer", 59 };

	printf("%s %s\n%d\n\n", customer.firstName
		                  , customer.lastName
				          , customer.age);

	
	// allocate enough memory to store a person struct
	pCustomer = (Customer *) malloc(sizeof(Customer));

	printf("Address after malloc: %p\n", pCustomer);

	strcpy(pCustomer->firstName, "George");
	strcpy(pCustomer->lastName, "Costanza");
	pCustomer->age = 54;

	printf("\n%s %s\n%d\n\n", pCustomer->firstName
		                    , pCustomer->lastName
						    , pCustomer->age);

	// always release allocated memory
	free(pCustomer);
	
	printf("Address after free: %p\n", pCustomer); // dangling pointer

	pCustomer = NULL; // set to null so it won't cause any trouble

	printf("Address after set to NULL: %p\n", pCustomer);

	return 0;
}

