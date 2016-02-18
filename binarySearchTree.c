/*
	==================================================================================
	Name				: binarySearchTree.c
	Author			: Vineet Tiwari
	Version			:	1.0
	Description	: Understand and practice implementing BST data structure.
	==================================================================================
*/


#include <stdio.h>
#include <stdlib.h>


// Self referencing struct
struct BstNode
{
	int 							data;
	struct BstNode 		*left,
										*right;
};


// Function protopypes
struct BstNode *GetNewNode(int);
void Insert(struct BstNode **, int);
void Print(struct BstNode **);


int main()
{
	// Create empty Tree
	struct BstNode *root = NULL;

	Insert(&root, 15);
	Insert(&root, 10);
	Insert(&root, 20);

	printf("\n");
	Print(&root);
	printf("\n\n");
	return EXIT_SUCCESS;
}


struct BstNode *GetNewNode(int data)
{
	// Creat new node in Heap and chek if NULL
	struct BstNode *newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
	if(!newNode)
	{
		fprintf(stderr, "Error: Attempt to Allocate Memory Failed\n");
		exit(EXIT_FAILURE);
	}

	// Set data and pointer values for the new node
	newNode->data = data;
	newNode->left = newNode->right = NULL;

	return newNode;
}


void Insert(struct BstNode **root, int data)
{
	// If tree is empty set new node as root node
	if(!*root)
	{
		*root = GetNewNode(data);
	}
	else 
	{
		// Check if data is greate or less than root node's data
		// and node the right or left of the tree respectively
		if(data < (*root)->data)
		{
			Insert(&((*root)->left), data);
		}
		else if(data > (*root)->data)
		{
			Insert(&((*root)->right), data);
		}
		else
		{
			// If data already exists in tree
			// then don't insert it again
			printf(" copy");
		}
	}
}



void Print(struct BstNode **root)
{
	if(*root)
	{
		Print(&((*root)->left));
		printf("%3d ", (*root)->data);
		Print(&((*root)->right));
	}
}



