/* 
 * Name:	addaword.c
 * Purpose:	uses fprintf(), fscanf(), and rewind()
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main()
{
	FILE *fp;
	char words[MAX];
	
	if (!(fp = fopen("wordy.txt", "a+"))) {
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	
	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");
	
	while ((fscanf(stdin, "%s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%s ", words);
	fprintf(fp, "\n");
		
	puts("File contents:");
	rewind(fp); /* go back to beginning of file */
	
	while (fscanf(fp, "%s", words) == 1)
		puts(words);
	
	puts("Done!");
		
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");
		
	return EXIT_SUCCESS;
}




