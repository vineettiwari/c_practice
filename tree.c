// tree.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// self-referential structure
struct treeNode
{ 
   struct treeNode *pLeft;  // pointer to left node
   int data;
   struct treeNode *pRight; // pointer to right node
};

typedef struct treeNode TreeNode;

// function prototypes
void insertNode( TreeNode **pTree, int value );
void printTree( TreeNode *pTree );


int main( void )
{ 
   int counter;
   int value;
   TreeNode *pRoot = NULL; 

   srand( (unsigned) time( NULL ) ); 	

   printf( "The numbers being inserted into the tree are:\n" );

   // insert random values between 0 and 24 in the tree
   for ( counter = 0; counter < 20; counter++ )
   { 
      value = rand() % 25;
      printf( "%3d", value );
      insertNode( &pRoot, value );
   }
 
   // print tree elements to console
   printf( "\n\nThe tree elements are:\n" );
   printTree( pRoot );
  
   printf("\n\n");

   return 0;
}


void insertNode( TreeNode **pTree, int value )
{    
   if ( *pTree == NULL ) // tree is empty
   {   
      *pTree = (TreeNode*) malloc( sizeof( TreeNode ) );

      if ( *pTree != NULL ) // malloc succeeded
      { 
         ( *pTree )->data = value;
         ( *pTree )->pLeft = NULL;
         ( *pTree )->pRight = NULL;
      }
      else
      {
         printf( "%d not inserted. No memory available.\n", value );
      }
   }
   else // tree is not empty
   { 
     
      if ( value < ( *pTree )->data ) // value is less - insert left
      {
         insertNode( &( ( *pTree )->pLeft ), value );
      }
      else if ( value > ( *pTree )->data ) // value is greater - insert right
      {
         insertNode( &( ( *pTree )->pRight ), value );
      }
      else // duplicate value - ignore
      {
         printf( "dup" );
      }
   }
}

// print tree elements to console
void printTree( TreeNode *pTree )
{ 
   if ( pTree != NULL )
   { 
      printTree( pTree->pLeft );
      printf( "%3d", pTree->data );
      printTree( pTree->pRight );
   }
}

