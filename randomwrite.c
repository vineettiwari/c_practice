// randomwrite.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct clientData
{ 
   int acctNum;    
   char lastName[ 15 ];
   char firstName[ 10 ];
   double balance;
};

typedef struct clientData ClientData;
 
int main( void ) 
{ 
   FILE *cfPtr; 

   // create clientData with default data 
   ClientData client = { 0, "", "", 0.0 };

   // fopen opens the file; exits if file cannot be opened
   if ( ( cfPtr = fopen( "credit.dat", "rb+" ) ) == NULL )
   {
      printf( "File could not be opened.\n" );
   }
   else 
   { 
      // have user specify account number
      printf( "Enter account number"
         " ( 1 to 100, 0 to end input )\n? " );
      scanf( "%d", &client.acctNum );
	  while (getchar() != '\n');

      while ( client.acctNum != 0 )
      { 
         // user enters last name, first name and balance 
         printf( "Enter lastname firstname balance (separated by spaces)\n? " );
        
         // set record lastName, firstName and balance value
         fscanf( stdin, "%s%s%lf"
                  , client.lastName
                  , client.firstName
                  , &client.balance );

         // seek position in file to user-specified record 
         fseek( cfPtr, ( client.acctNum - 1 ) * 
            sizeof( struct clientData ), SEEK_SET );

         // write user-specified information to file
         fwrite( &client, sizeof( struct clientData ), 1, cfPtr );

         // enable user to input another account number 
         printf( "Enter account number\n? "
                 " ( 1 to 100, 0 to end input )\n? " );
         scanf ( "%d", &client.acctNum );
		 while (getchar() != '\n');
      }

      fclose( cfPtr ); // fclose closes the file
   }

   return 0; 
}