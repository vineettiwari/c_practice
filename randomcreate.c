// randomcreate.c
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
   int counter;

   // create clientData with default data
   ClientData blankClient = { 0, "", "", 0.0 };
   
   FILE *cfPtr;

   printf("Struct size: %d\n", sizeof( ClientData ));

   // fopen opens the file; exits if file cannot be opened
   if ( ( cfPtr = fopen( "credit.dat", "wb" ) ) == NULL )
   {
      printf( "File could not be opened.\n" );
   }
   else
   { 
      // output 100 blank records to file
      for ( counter = 0; counter < 100; counter++ )
      {
         fwrite( &blankClient, sizeof( ClientData ), 1, cfPtr );
      }

      printf( "Data file created.\n" );
      fclose ( cfPtr );
   }

   return 0;
}