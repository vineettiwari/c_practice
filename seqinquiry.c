// seqinquiry.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void )
{ 
   int request; 
   int account; 
   double balance;
   char name[ 30 ];
   FILE *cfPtr;    

   // fopen opens the file; exits program if file cannot be opened 
   if ( ( cfPtr = fopen( "clients.txt", "r" ) ) == NULL )
   {
      printf( "File could not be opened\n" );
   }
   else
   {
      printf( "Enter request\n"
		 " 1 - List all accounts\n"
         " 2 - List accounts with zero balances\n"
         " 3 - List accounts with credit balances\n"
         " 4 - List accounts with debit balances\n"
         " 5 - End program\n? " );

      scanf( "%d", &request );
	  while (getchar() != '\n');

      while ( request != 5 ) 
      { 
         // read account, name and balance from file
         fscanf( cfPtr, "%d%s%lf", &account, name, &balance );

         switch ( request )
         { 
			case 1:
				printf("\nAll Accounts:\n");
				printf("%-10s%-13s%7s\n%s\n", "Number", "Name", "Balance", "------------------------------");
				// read file contents (until eof) */
				while (!feof(cfPtr))
				{
					printf("%-10d%-13s%7.2f\n", account, name, balance);

					// read account, name and balance from file 
					fscanf(cfPtr, "%d%s%lf", &account, name, &balance);
				}

				break;

            case 2:
               printf( "\nAccounts with zero balances:\n" );
			   printf("%-10s%-13s%7s\n%s\n", "Number", "Name", "Balance", "------------------------------");

               // read file contents (until eof) */
               while ( !feof( cfPtr ) )
               { 
                   if ( balance == 0 )
                   {
                     printf( "%-10d%-13s%7.2f\n", account, name, balance );
                   }

                  // read account, name and balance from file 
                  fscanf( cfPtr, "%d%s%lf", &account, name, &balance );
               }

               break;

            case 3:
               printf( "\nAccounts with credit balances:\n" );
			   printf("%-10s%-13s%7s\n%s\n", "Number", "Name", "Balance", "------------------------------");

               // read file contents (until eof)
               while ( !feof( cfPtr ) )
               { 
                  if ( balance < 0 )
                  {
                     printf( "%-10d%-13s%7.2f\n", 
                        account, name, balance );
                  }

                  // read account, name and balance from file
                  fscanf( cfPtr, "%d%s%lf", &account, name, &balance );
               }

               break;

            case 4:
               printf( "\nAccounts with debit balances:\n" );
			   printf("%-10s%-13s%7s\n%s\n", "Number", "Name", "Balance", "------------------------------");

               // read file contents (until eof) 
               while ( !feof( cfPtr ) )
               { 
                  if ( balance > 0 )
                  {
                     printf( "%-10d%-13s%7.2f\n", account, name, balance );
                  }

                  // read account, name and balance from file
                  fscanf( cfPtr, "%d%s%lf", &account, name, &balance );
               }
               break; 

			default:
			{
				printf("Incorrect menu choice\n");
			}
         }  

         rewind( cfPtr ); // return cfPtr to beginning of file

         printf( "\n? " );
         scanf( "%d", &request );
		 while (getchar() != '\n');
      }

      fclose( cfPtr ); // fclose closes the file
   }

   return 0;
}