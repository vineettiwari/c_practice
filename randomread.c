// randomread.c
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
   if ( ( cfPtr = fopen( "credit.dat", "rb" ) ) == NULL )
   {
      printf( "File could not be opened.\n" );
   }
   else
   { 
      printf( "%-6s%-16s%-11s%10s\n%s\n", "Acct", "Last Name",
         "First Name", "Balance", "-------------------------------------------" );

      // read all records from file (until eof)
      while ( !feof( cfPtr ) )
      { 
         fread( &client, sizeof( ClientData ), 1, cfPtr );

         // display record
         if ( client.acctNum != 0 )
         {
            printf( "%-6d%-16s%-11s%10.2f\n"
                    , client.acctNum
                    , client.lastName
                    , client.firstName
                    , client.balance );
         }

      }

      fclose( cfPtr ); // fclose closes the file
   }

   return 0;
}