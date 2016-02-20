/*
	==================================================================================
	Name				: bst.c
	Author			: Vineet Tiwari
	Version			:	1.0
	Description	: To understand BST(Binary Search Tree) data structure.
	==================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Self referencing struct
struct BstNode
{
	int data;
	struct BstNode 	*left,
									*right;
};

// Function protopypes
struct BstNode *GetNewNode(int);
void Insert(struct BstNode **, int);
bool Search(struct BstNode *, int);
void Print(struct BstNode *);
int FindMin(struct BstNode *);
int FindMax(struct BstNode *);
int FindHeight(struct BstNode *);

int main()
{
	// Create empty Tree
	struct BstNode *root = NULL;
	int input;

	Insert(&root, 15);
	Insert(&root, 10);
	Insert(&root, 20);
	Insert(&root, 12);
	Insert(&root, 25);
	Insert(&root, 8);
	Insert(&root, 12);

	do
	{
		printf("\n%s ", "Enter an integer:");
		scanf("%d", &input);
		while(getchar() != '\n');
		if(input >= 0)
		{
			if(Search(root, input) == true)
				printf("\n%s\n", "Found :)");
			else
				printf("\n%s\n", "Not Found :(");
		}
	} while(input >= 0);

	printf("\nTree Content:\n\n");
	Print(root);

	printf("\n\nMinimum: %d", FindMin(root));
	printf("\nMaximum: %d", FindMax(root));

	// int height  = FindHeight(root);

	printf("\n\nHeight: %d", FindHeight(root));

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
	else if(data < (*root)->data)				// Check if data is greate or 
	{																		// less than root node's data and node the 
		Insert(&((*root)->left), data);		// right or left of the tree respectively
	}
	else
	{
		Insert(&((*root)->right), data);	
	}
}

bool Search(struct BstNode *root, int data)
{
	if(!root)
		return false;
	else if(data == root->data)
		return true;
	else if(data < root->data)
		return	Search(root->left, data);
	else
		return Search(root->right, data);
}

void Print(struct BstNode *root)
{
	if(root)
	{
		Print(root->left);
		printf("%-3d ", root->data);
		Print(root->right);
	}
}

int FindMin(struct BstNode *root)
{
	if(!root)
	{
		fprintf(stderr, "Error: Tree is empty\n");
		exit(EXIT_FAILURE);
	}

	struct BstNode *current = root;

	while(current->left)
	{
		current = current->left;
	}

	return current->data;
}

int FindMax(struct BstNode *root)
{
	if(!root)
	{
		fprintf(stderr, "Error: Tree is empty\n");
		exit(EXIT_FAILURE);
	}

	struct BstNode *current = root;
	
	while(current->right)
	{
		current = current->right;
	}

	return current->data;
}

// int FindHeight(struct BstNode *root)
// {
// 	if(!root)
// 		return -1;
// 	return 
// 	return FindMax(FindHeight(root->left), FindHeight(root->right)) + 1;
// }