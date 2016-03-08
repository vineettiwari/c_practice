// seqcreate.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main( void )
{ 
   int account;   
   char name[ 30 ];
   double balance; 

   FILE *cfPtr;

   // fopen opens file. Exit program if unable to create file 
   if ( ( cfPtr = fopen( "clients.txt", "w" ) ) == NULL )
   {
      printf( "File could not be opened\n" );
   }
   else
   { 
      printf( "Enter the account number, name and balance. (separated by spaces)\n" );
      printf( "Enter EOF to end input. (Crtl-Z)\n" );
      printf( "? " );

      scanf( "%d%s%lf", &account, name, &balance );
	  fflush(stdin);

      // write account, name and balance into file with fprintf
      while ( !feof( stdin ) )
      { 
         fprintf( cfPtr, "%d %s %.2f\n", account, name, balance );
         printf( "? " );
         scanf( "%d%s%lf", &account, name, &balance );
		 fflush(stdin);
      }
      
      fclose( cfPtr );
   }
   return 0; 
}