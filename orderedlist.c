// orderedlist.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// self-referential structure
struct listNode
{            
   char data;
   struct listNode *pNext; // pointer to next node
};  

typedef struct listNode ListNode;

// function prototypes
void insertNode( ListNode **pHead, char value );
char deleteNode( ListNode **pHead, char value );
int isEmpty( ListNode *pHead );
void printList( ListNode *pHead );
void displayMenu( void );

int main( void )
{ 
   ListNode *pHead = NULL;
   int choice;
   char item;

   displayMenu();
   printf( "? " );
   scanf( "%d", &choice );
   while (getchar() != '\n');
  
   while ( choice != 3)
   { 
      switch ( choice )
      { 
         case 1:
            printf( "Enter a character: " );
            scanf( "%c", &item );
            while (getchar() != '\n');

            insertNode( &pHead, item );
            printList( pHead );
            break;

         case 2:

            if ( !isEmpty( pHead ) ) 
            { 
               printf( "Enter character to be deleted: " );
               scanf( "\n%c", &item );
               while (getchar() != '\n');

               if ( deleteNode( &pHead, item ) )
               {
                  printf( "%c deleted.\n", item );
                  printList( pHead );
               }
               else
               {
                  printf( "%c not found.\n\n", item );
               }
            } 
            else
            {
               printf( "List is empty.\n\n" );
            } 

            break;

         default:
            printf( "Invalid choice.\n\n" );
            displayMenu();
            break;
      
      }

      printf( "? " );
      scanf( "%d", &choice );
      while (getchar() != '\n');
   }

   return 0;
}


void displayMenu( void )
{ 
   printf( "Enter your selection:\n"
      "   1) insert an element into the list.\n"
      "   2) delete an element from the list.\n"
      "   3) exit\n" );
}

// insert a new value into the list in sorted order
void insertNode( ListNode **pHead, char value )
{ 
   ListNode *pNew;      
   ListNode *pPrevious;
   ListNode *pCurrent;

   pNew = malloc( sizeof( ListNode ) ); // create new node

   // pNew = (ListNode*) malloc( sizeof( ListNode ) );

   if ( pNew != NULL ) 
   {
      // initialize struct data
      pNew->data = value; 
      pNew->pNext = NULL; 

      pPrevious = NULL;
      pCurrent = *pHead;

      // loop to find the correct insertion point
      while ( pCurrent != NULL && value > pCurrent->data )
      { 
         pPrevious = pCurrent;        
         pCurrent = pCurrent->pNext;  
      }

      if ( pPrevious == NULL )
      { 
         // insert node at head
         pNew->pNext = *pHead;
         *pHead = pNew;
      } 
      else
      {
         // insert node
         pPrevious->pNext = pNew;
         pNew->pNext = pCurrent;
      } 
   } 
   else 
   {
      printf( "%c not inserted. No memory available.\n", value );
   }
}

// delete node containing the selected value
char deleteNode( ListNode **pHead, char value )
{ 
   ListNode *pPrevious; 
   ListNode *pCurrent;  
   ListNode *pTemp; 

   pCurrent = *pHead;

   if ( value == ( *pHead )->data ) // first node in list to be deleted
   { 
      pTemp = *pHead; // attach a pointer to element to be removed
      *pHead = ( *pHead )->pNext; // de-thread the node
      free( pTemp ); // release this memory and set it free!
      return value;
   }
   else
   { 
      // move to second node
      pPrevious = *pHead;
      pCurrent = ( *pHead )->pNext;

      // loop to find the correct deletion point
      while ( pCurrent != NULL && pCurrent->data != value )
      { 
         pPrevious = pCurrent;         // traverse through
         pCurrent = pCurrent->pNext;   //  each node  
      }

      // delete node at pCurrent (if not NULL - element value not found)
      if ( pCurrent != NULL )
      { 
         pTemp = pCurrent; // attach a pointer to element to be removed
         pPrevious->pNext = pCurrent->pNext; // de-thread the node
         free( pTemp ); // release this memory and set it free!
         return value;
      }     
   }

   return '\0';
}


int isEmpty( ListNode *pHead )
{ 
   return pHead == NULL;
}


void printList( ListNode *pCurrent )
{ 
   if ( pCurrent == NULL )
   {
      printf( "List is empty.\n\n" );
   }
   else
   { 
      printf( "List contents:\n" );

      while ( pCurrent != NULL )
      { 
         printf( "%c --> ", pCurrent->data );
         pCurrent = pCurrent->pNext; // move to next element  
      }

      printf( "NULL\n\n" );
   }
}
