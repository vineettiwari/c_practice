// stack.c
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>

// self-referential structure
struct stackNode
{  
   char data;
   struct stackNode *pNext;
};

typedef struct stackNode StackNode;

// function prototypes
void push( StackNode **pTop, char value );
char pop( StackNode **pTop );
int isEmpty( StackNode *pTop );
void printStack( StackNode *pCurrent );
void displayMenu( void );

int main( void )
{ 
   StackNode *pStack = NULL;
   int choice;
   char value;
 
   displayMenu();
   printf( "? " );
   scanf( "%d", &choice );
   while (getchar() != '\n');

   while ( choice != 3 )
   { 
      switch ( choice )
	  { 
         case 1: // push a value onto the stack      
            printf( "Enter a character: " );
            scanf( "%c", &value );
            while(getchar() != '\n');
            push( &pStack, value );
            printStack( pStack );
            break;

         case 2: // pops value off of the stack      

            if ( !isEmpty( pStack ) )
			   {
               printf( "The popped value is %c.\n", pop( &pStack ) );
            }

            printStack( pStack );
            break;

         default:
            printf( "Invalid choice.\n\n" );
            break;
      }

      displayMenu();
      printf( "? " );
      scanf( "%d", &choice );
      while (getchar() != '\n');
   } 
   return 0;
}

void displayMenu( void )
{ 
   printf( "Enter choice:\n"
	   "1) push a character on the stack\n"
	   "2) pop a character off the stack\n"
      "3) end program\n" );
}

// Insert a node at the stack top
void push( StackNode **pTop, char value )
{ 
   StackNode *pNew;

   pNew = (StackNode*) malloc( sizeof( StackNode ) );

   if ( pNew != NULL )
   {   
      pNew->data = value;
      pNew->pNext = *pTop; // insert at top of stack
      *pTop = pNew;
   }
   else
   {
      printf( "%c not pushed. No memory available.\n", value );
   }
} 

// Remove a node from the stack top
char pop( StackNode **pTop )
{ 
   StackNode *pTemp;
   char popValue;

   pTemp = *pTop; // attach a pointer to element to be removed
   popValue = ( *pTop )->data; 
   *pTop = ( *pTop )->pNext; // remove at top of stack
   free( pTemp ); // release this memory and set it free!

   return popValue;
}

// output stack contents to the console
void printStack( StackNode *pCurrent )
{ 
   if ( pCurrent == NULL )
   {
      printf( "The stack is empty.\n\n" );
   }
   else
   { 
      printf( "The stack is:\n" );

      while ( pCurrent != NULL )
	  { 
         printf( "%c --> ", pCurrent->data );
         pCurrent = pCurrent->pNext; // move to next element
      }
      printf( "NULL\n\n" );
   } 
}

int isEmpty( StackNode *pTop )
{ 
   return pTop == NULL;
} 
