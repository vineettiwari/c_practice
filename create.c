/*
 *	Name:		create.c
 *	Author:		Vineet Tiwari
 *	Created on:	March 05, 2016
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFF_SIZE 20
#define LINE_SIZE 256

struct account {
	int	account_number;
	char	first_name[BUFF_SIZE], last_name[BUFF_SIZE];
	float	account_balance, last_payment_amount;
};

float converter(char *str_value)
{
	int  i, len, result = 0;
	len = strlen(str_value);

	for (i = 0; i < len; i++) {
		result = result * 10 + ( str_value[i] - '0' );
	}
	
	return result;
}

void trim_comma(char *str_value)
{
	int length = strlen(str_value);
	
	if (str_value[length - 1] == ',')
		str_value[length - 1] = '\0';
} 

bool parse_line(char *line, struct account *customer_account)
{
	bool didRead = false;
	int i = 0, success = 0;
	char 	temp_accnum[BUFF_SIZE], temp_fname[BUFF_SIZE],
		temp_lname[BUFF_SIZE], temp_accbal[BUFF_SIZE],
		temp_lpay[BUFF_SIZE];
	
	while (i < sizeof(line)) {
		success = sscanf(line, "%s %s %s %s %s", temp_accnum, 
			temp_fname, temp_lname, temp_accbal, temp_lpay);
		i++;
	}
	
	trim_comma(temp_accnum);
	trim_comma(temp_fname);
	trim_comma(temp_lname);
	trim_comma(temp_accbal);
	trim_comma(temp_lpay);
	
	customer_account->account_number = (int)converter(temp_accnum);
	customer_account->account_balance = converter(temp_accbal);
	customer_account->last_payment_amount = converter(temp_lpay);
	
	printf("%d %s %s %f %f\n",
	customer_account->account_number, temp_fname, temp_lname,
	customer_account->account_balance,
	customer_account->last_payment_amount);
	
	if (success == 5)
		didRead = true;
		
	return didRead;
}

int main()
{
	FILE *ftext_ptr, *fbinary_ptr;
	char line[LINE_SIZE];
	struct account customer_account;
	
	/* read in text mode */
	ftext_ptr = fopen("account.csv", "r");
	if (!ftext_ptr) {
		fprintf(stderr,
			"\nError: Unable to open file - account.csv\n");
		exit(EXIT_FAILURE);
	}
	
	/* write in binary mode */
	fbinary_ptr = fopen("account.dat", "wb");
	if (!fbinary_ptr) {
		fprintf(stderr, "\nError: Unable to "
			"create/open file - account.dat\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), ftext_ptr)) {  /* TODO */
		parse_line(line, &customer_account);
	}

	if (fclose(ftext_ptr) != 0)
		fprintf(stderr, "\nError: Unable to "
			"close file - account.csv\n");
	
	if (fclose(fbinary_ptr) != 0)
		fprintf(stderr, "\nError: Unable to "
			"close file - account.dat\n");
	
	printf("\nFile copied successfully!\n\n");
	return EXIT_SUCCESS;
}




