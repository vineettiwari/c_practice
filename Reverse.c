/* reverse.c -- displays a file in reverse order */ 

#include <stdio.h>
#include <stdlib.h>

#define CNTL_Z '\032'
#define SLEN 81

int main()
{
	char file[SLEN], ch;
	FILE *in, *out;
	long count, last;
	
	puts("Enter the name of the file to be processed:");
	scanf("%s", file);
	
	/* open file in read-only mode */
	if (!(in = fopen(file,"rb"))) {
		printf("reverse can't open %s\n", file);
		exit(EXIT_FAILURE);
	}
	
	/* open file in write and read mode */
	if (!(out = fopen("reverse.txt", "wb+"))) {
		printf("reverse can't open %s\n", "reverse.txt");
		exit(EXIT_FAILURE);
	}
	
	fseek(in, 0L, SEEK_END); /* go to end of file */ 
	last = ftell(in);
	
	for (count = 1L; count <= last; count++) {
		fseek(in, -count, SEEK_END); /* go backward */
		ch = getc(in);

		if (ch != CNTL_Z && ch != '\r') /* MS-DOS files */
			putchar(ch);
			putc(ch, out);
	}
	
	fclose(in);
	fclose(out);
	
	fprintf(stdout, "\n\n");
	return EXIT_SUCCESS;
}




