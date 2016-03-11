/*
 *	Name:		create.c
 *	Author:		Vineet Tiwari
 *	Created on:	March 05, 2016
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFF_SIZE 16
#define LINE_SIZE 256

struct account {
	int	account_number;
	char	first_name[BUFF_SIZE], last_name[BUFF_SIZE];
	float	account_balance, last_payment_amount;
};

bool parse_row(char *row, struct account *customer_account)
{
	bool didRead = false;
	
	return didRead;
}

int main()
{
	FILE *ftext_ptr, *fbinary_ptr;
	char line[LINE_SIZE];
	
	ftext_ptr = fopen("account.csv", "r");		/* read text mode */
	if (!ftext_ptr) {
		fprintf(stderr,
			"\nError: Unable to open file - account.csv\n");
		exit(EXIT_FAILURE);
	}

	fbinary_ptr = fopen("account.dat", "wb");	/* write and read */
	if (!fbinary_ptr) {				/* binary mode	  */
		fprintf(stderr, "\nError: Unable to "
			"create/open file - account.dat\n");
		exit(EXIT_FAILURE);
	}

	while () {  /* TODO */

	}


	if (fclose(ftext_ptr) != 0) {
		fprintf(stderr, "\nError: Unable to "
			"close file - account.csv\n");
		exit(EXIT_FAILURE);
	}
	
	if (fclose(fbinary_ptr) != 0) {
		fprintf(stderr, "\nError: Unable to "
			"close file - account.dat\n");
		exit(EXIT_FAILURE);
	}
	
	printf("\nFile copied successfully!\n\n");
	return EXIT_SUCCESS;
}




