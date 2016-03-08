// ReadFile.c

#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 25
 
int main()
{
   char ch, file_name[BUFF_SIZE];
   FILE *fp;

   printf("Enter the name of file you wish to see\n");
   scanf("%s", file_name);
   while (getchar() != '\n')
   	continue;

   fp = fopen(file_name, "r"); // read mode
   
   if (fp == NULL) {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   printf("\nThe contents of %s file are :\n\n", file_name);

   while((ch = fgetc(fp)) != EOF)
      printf("%c",ch);

   fclose(fp);

   printf("\n\n");
   return EXIT_SUCCESS;  
}
