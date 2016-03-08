// randomedit.c
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

int enterChoice( void );
void textFile( FILE *readPtr );
void updateRecord( FILE *fPtr );
void newRecord( FILE *fPtr );
void deleteRecord( FILE *fPtr );

int main( void )
{ 
   FILE *cfPtr;
   int choice; 

   // fopen opens the file; exits if file cannot be opened
   if ( ( cfPtr = fopen( "credit.dat", "rb+" ) ) == NULL )
   {
      printf( "File could not be opened.\n" );
   }
   else
   { 
       while ( ( choice = enterChoice() ) != 5 )
       { 
         switch ( choice )
         { 
            case 1:
               textFile( cfPtr );
               break;

            case 2:
               updateRecord( cfPtr );
               break;

            case 3:
               newRecord( cfPtr );
               break;

            case 4:
               deleteRecord( cfPtr );
               break;
         
            default:
               printf( "Incorrect choice\n" );
               break;      
         } 
      }

      fclose( cfPtr ); // fclose closes the file
   }
 
   return 0;

}


void textFile( FILE *readPtr )
{ 
   FILE *writePtr;

   // create clientData with default information
   ClientData client = { 0, "", "", 0.0 };

   // fopen opens the file; exits if file cannot be opened
   if ( ( writePtr = fopen( "accounts.txt", "w" ) ) == NULL )
   {
      printf( "File could not be opened.\n" );
   }
   else
   { 
      rewind( readPtr ); // sets pointer to beginning of file
      fprintf( writePtr, "%-6s%-16s%-11s%10s\n", 
         "Acct", "Last Name", "First Name","Balance" );

      // copy all records from random-access file into text file
      while ( !feof( readPtr ) )
      { 
         fread( &client, sizeof( ClientData ), 1, readPtr );

         // write single record to text file
         if ( client.acctNum != 0 )
         {
            fprintf( writePtr, "%-6d%-16s%-11s%10.2f\n"
                    , client.acctNum
                    , client.lastName
                    , client.firstName
                    , client.balance );
         }

      } 

      fclose( writePtr ); // fclose closes the file
   }

}


void updateRecord( FILE *fPtr )
{ 
   int account;        
   double transaction; 

   // create clientData with no information
   ClientData client = { 0, "", "", 0.0 };

   // obtain number of account to update
   printf( "Enter account to update ( 1 - 100 ): " );
   scanf( "%d", &account );
   while (getchar() != '\n');

   // move file pointer to correct record in file
   fseek( fPtr, ( account - 1 ) * sizeof( ClientData ), 
      SEEK_SET );

   // read record from file
   fread( &client, sizeof( ClientData ), 1, fPtr );

   // display error if account does not exist
   if ( client.acctNum == 0 )
   {
      printf( "Account #%d does not exist.\n", account );
   }
   else 
   {
      printf( "%-6d%-16s%-11s%10.2f\n\n"
               , client.acctNum
               , client.lastName
               , client.firstName
               , client.balance );
      
      // request transaction amount from user
      printf( "Enter charge ( + ) or payment ( - ): " );
      scanf( "%lf", &transaction );
      while (getchar() != '\n');
      client.balance += transaction;
      
      printf( "%-6d%-16s%-11s%10.2f\n\n"
               , client.acctNum
               , client.lastName
               , client.firstName
               , client.balance );
      
      // move file pointer to correct record in file
      fseek( fPtr, ( account - 1 ) * sizeof( ClientData ), 
         SEEK_SET );

      // write updated record over old record in file
      fwrite( &client, sizeof( ClientData ), 1, fPtr );
   }

}


void deleteRecord( FILE *fPtr )
{ 

   ClientData client;
   ClientData blankClient = { 0, "", "", 0 };
   
   int accountNum;

   // obtain number of account to delete
   printf( "Enter account number to delete ( 1 - 100 ): " );
   scanf( "%d", &accountNum );
   while (getchar() != '\n');

   // move file pointer to correct record in file
   fseek( fPtr, ( accountNum - 1 ) * sizeof( ClientData ), 
      SEEK_SET );

   // read record from file
   fread( &client, sizeof( ClientData ), 1, fPtr );

   // display error if record does not exist 
   if ( client.acctNum == 0 )
   {
      printf( "Account %d does not exist.\n", accountNum );
   }
   else 
   {
      // move file pointer to correct record in file
      fseek( fPtr, ( accountNum - 1 ) * sizeof( ClientData ), 
         SEEK_SET );

      // replace existing record with blank record
      fwrite( &blankClient, 
         sizeof( ClientData ), 1, fPtr );
   }

}


void newRecord( FILE *fPtr )
{ 
   // create clientData with default data
   ClientData client = { 0, "", "", 0.0 };

   int accountNum;

   // obtain number of account to create
   printf( "Enter new account number ( 1 - 100 ): " );
   scanf( "%d", &accountNum );
   while (getchar() != '\n');

   // move file pointer to correct record in file
   fseek( fPtr, ( accountNum - 1 ) * sizeof( ClientData ), 
      SEEK_SET );

   // read record from file
   fread( &client, sizeof( ClientData ), 1, fPtr );

   // display error if account already exists
   if ( client.acctNum != 0 )
   {
      printf( "Account #%d already contains data.\n",
              client.acctNum );
   }
   else
   {
      // user enters last name, first name and balance */
      printf( "Enter lastname firstname balance (separated by spaces)\n? " );
      scanf( "%s%s%lf"
              , &client.lastName
              , &client.firstName
              , &client.balance );

      while (getchar() != '\n');
      client.acctNum = accountNum;
      
      // move file pointer to correct record in file
      fseek( fPtr, ( client.acctNum - 1 ) * sizeof( ClientData ), SEEK_SET );

      // insert record in file
      fwrite( &client, sizeof( ClientData ), 1, fPtr );
   }

}


int enterChoice( void )
{ 
   int menuChoice;

   printf( "\nEnter your choice\n"
      "1 - store a formatted text file of accounts called\n"
      "    \"accounts.txt\" for printing\n"
      "2 - update an account\n"
      "3 - add a new account\n"
      "4 - delete an account\n"
      "5 - end program\n? " );

   scanf( "%d", &menuChoice );
   while (getchar() != '\n');
   return menuChoice;

}