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
	double	account_balance, last_payment_amount;
};

/* function prototypes */

void trim_comma(char *str_value); 
bool parse_line(char *line, struct account *customer_account);
void write_file(FILE *ftext_ptr,
		FILE *fbinary_ptr, struct account *customer_account);
void read_file(FILE *fbinary_ptr, struct account *customer_account);

int main()
{
	FILE		*ftext_ptr = NULL;
	FILE		*fbinary_ptr = NULL;
	struct account	customer_account;
	
	write_file(ftext_ptr, fbinary_ptr, &customer_account);
	
	read_file(fbinary_ptr, &customer_account);
	
	printf("\nFile copied successfully!\n\n");
	return EXIT_SUCCESS;
}

void trim_comma(char *str_value)
{
	int length = strlen(str_value);
	
	if (str_value[length - 1] == ',')
		str_value[length - 1] = '\0';
}

bool parse_line(char *line, struct account *customer_account)
{
	
	size_t success = 0;
	char 	temp_accnum[BUFF_SIZE], temp_fname[BUFF_SIZE],
		temp_lname[BUFF_SIZE], temp_accbal[BUFF_SIZE],
		temp_lpay[BUFF_SIZE];
	
	success = sscanf(line, "%s%s%s%s%s", temp_accnum, 
			temp_fname, temp_lname, temp_accbal, temp_lpay);
	
	trim_comma(temp_accnum);
	trim_comma(temp_fname);
	trim_comma(temp_lname);
	trim_comma(temp_accbal);
	trim_comma(temp_lpay);

	success += sscanf(temp_fname,  "%s", customer_account->first_name);
	success += sscanf(temp_lname,  "%s", customer_account->last_name);
	success += sscanf(temp_accnum, "%d",
		&(customer_account->account_number));
	success += sscanf(temp_accbal, "%lf",
		&(customer_account->account_balance));
	success += sscanf(temp_lpay, "%lf",
		&(customer_account->last_payment_amount));
		
	return (success == 10);
}

void write_file(FILE *ftext_ptr,
		FILE *fbinary_ptr, struct account *customer_account)
{
	char line[LINE_SIZE];
	
	/* read in text mode */
	ftext_ptr = fopen("account.csv", "r");
	/* write in binary mode */
	fbinary_ptr = fopen("account.dat", "wb");
	
	if (!ftext_ptr || !fbinary_ptr) {
		fprintf(stderr,
			"\nError: Failed to open one of the files.\n");
		return;
	}
	
	putchar('\n');
	while (fgets(line, sizeof(line), ftext_ptr)) {
		if (parse_line(line, customer_account)) {
			if (fwrite(customer_account,
				sizeof(struct account), 1, fbinary_ptr) != 1) {
				fprintf(stderr,
					"\nError - Unable to save to disk\n");
				return;
			} /* else {
				fprintf(stderr,
					"\nWarning: Misformed line\n");
			} */
		}
	}
	
	if ((fclose(ftext_ptr) != 0) || (fclose(fbinary_ptr) != 0))
		fprintf(stderr, "\nError: Failed to "
			"close one of the files.\n");	
}

void read_file(FILE *fbinary_ptr, struct account *customer_account)
{
	fbinary_ptr = fopen("account.dat", "rb");
	if (!fbinary_ptr) {
		fprintf(stderr, "\nError: Unable to "
			"open file - account.dat\n");
		return;
	}	
	
	while (fread(customer_account,
			sizeof(struct account), 1, fbinary_ptr) == 1) {
		printf("%d %s %s %.2lf %.2lf\n",
				customer_account->account_number,
				customer_account->first_name,
				customer_account->last_name,
				customer_account->account_balance,
				customer_account->last_payment_amount);
	}
	
	if (fclose(fbinary_ptr) != 0)
		fprintf(stderr, "\nError: Unable to "
			"close file - account.dat\n");
}



