// seqread.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main( void )
{ 
   int account;  
   char name[ 30 ];
   double balance;

   FILE *cfPtr; 

   // fopen opens file; exits program if file cannot be opened 
   if ( ( cfPtr = fopen( "clients.txt", "r" ) ) == NULL ) 
   {
      printf( "File could not be opened\n" );
   } 
   else
   {
	   printf("List of accounts:\n");
       printf( "%-10s%-13s%s\n%s\n", "Number", "Name", "Balance", "------------------------------" );
       fscanf( cfPtr, "%d%s%lf", &account, name, &balance );

       // while not end of file
       while ( !feof( cfPtr ) )
       { 
          printf( "%-10d%-13s%7.2f\n", account, name, balance );
          fscanf( cfPtr, "%d%s%lf", &account, name, &balance );
       }
 
       fclose( cfPtr ); // fclose closes the file
   }

   return 0;

}