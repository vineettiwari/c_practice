// queue.c
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

// self-referential structure
struct queueNode
{   
   char data;
   struct queueNode *pNext;  // pointer to next node
};

typedef struct queueNode QueueNode;

// function prototypes
void printQueue( QueueNode *pCurrent );
int isEmpty( QueueNode *pHead );
char dequeue( QueueNode **pHead, QueueNode **pTail );
void enqueue( QueueNode **pHead, QueueNode **pTail, char value );
void displayMenu( void );


int main(void)
{ 
   QueueNode *pHead = NULL;
   QueueNode *pTail = NULL;
   int choice;
   char value;

   displayMenu();
   printf( "? " );
   scanf( "%d", &choice );
   while (getchar() != '\n');
 
   while ( choice != 3 )
   { 
      switch( choice )
      { 
          case 1:
    
            printf( "Enter a character: " );
            scanf( "\n%c", &value );
			while (getchar() != '\n');
            enqueue( &pHead, &pTail, value );
            printQueue( pHead );
            break;

          case 2:

            if ( !isEmpty( pHead ) )
            { 
               value = dequeue( &pHead, &pTail );
               printf( "%c has been dequeued.\n", value );
            }

            printQueue( pHead );
            break;

         default:

            printf( "Invalid Choice.\n\n" );
            displayMenu();
            break;
      }

      choice = 0;
      printf( "? " );
      scanf( "%d", &choice );
	  while (getchar() != '\n');
   }

   return 0;
}


void displayMenu( void )
{ 
   printf ( "Enter your Choice:\n"
           "   1) add an item to the queue\n"
           "   2) remove an item from the queue\n"
           "   3) end program\n" );
}

// insert a node at queue tail
void enqueue( QueueNode **pHead, QueueNode **pTail, 
              char value )
{ 
   QueueNode *pNew;

   pNew = (QueueNode*) malloc( sizeof( QueueNode ) );

   if ( pNew != NULL ) 
   {
      pNew->data = value;
      pNew->pNext = NULL;
   
      if ( isEmpty( *pHead ) )  // queue empty - insert at head
      {
         *pHead = pNew;
      }
      else                      // queue not empty - insert at tail
      {
         ( *pTail )->pNext = pNew;
      }

      *pTail = pNew;
   }
   else
   {
      printf( "%c not enqueued. No memory available.\n", value );
   }
} 

// remove node from queue head
char dequeue( QueueNode **pHead, QueueNode **pTail )
{ 
   char value;
   QueueNode *pTemp;

   value = ( *pHead )->data;
   pTemp = *pHead;
   *pHead = ( *pHead )->pNext;

   if ( *pHead == NULL ) // queue is empty
   {
      *pTail = NULL;
   }

   free( pTemp );        // release this memory and set it free!

   return value;
}


int isEmpty( QueueNode *pHead )
{ 
   return pHead == NULL;
}

// print the queue 
void printQueue( QueueNode *pCurrent )
{ 
   if ( pCurrent == NULL )
   {
      printf( "Queue is empty.\n\n" );
   }
   else
   { 
      printf( "The queue is:\n" );

      while ( pCurrent != NULL )
      { 
         printf( "%c --> ", pCurrent->data );
         pCurrent = pCurrent->pNext;
      }

      printf( "NULL\n\n" );
   }
}
