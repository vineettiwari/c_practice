// linkedListSet.c

// Student Name: Vineet Tiwari

/*
COMP2717 Midterm Question #1

Criteria                            Possible  Actual
====================================================
Produces the correct results               4 

Implements a high quality algorithm        4  

Formats output correctly                   1  

Follows the assigned coding standard       1  

----------------------------------------------------
Total:                                    10       ?

Instructions

Add a new menu option to “delete duplicate elements in the list” and
implement changes required to support this new menu option. The work
of this menu option should be put in the following function:

int deleteDuplicates( ListNode *pStart );

The function should return the number of duplicates entries found
(which should be identical to the number of duplicates deleted).
The function should print a message each time a duplicate entry
is found, displaying the duplicate that was found (and is about to be deleted).

Enter your name in the space provided above.

DO NOT MODIFY ANY OF THE EXISTING CODE (Except the Menu Code)
SIMPLY ADD THE REQUIRED CODE TO COMPLETE

*/

#include <stdio.h>
#include <stdlib.h>

// self-referential structure
struct listNode
{            
  char data;
  struct listNode *pNext; // pointer to next node
};  

// function prototypes
void insertNode(struct listNode **, char);
char deleteNode(struct listNode **, char);
int  isEmpty(struct listNode *);
void printList(struct listNode *);
void displayMenu();
int  deleteDuplicates(struct listNode *);

int main()
{ 
  struct listNode *startPtr = NULL;
  int choice;
  char item;

  displayMenu();
  printf("? ");
  scanf("%d", &choice);
  while(getchar() != '\n');
  
  while(choice != 4)
  {   
    switch(choice)
    { 
      case 1:
        printf("Enter a character: ");
        scanf("%c", &item);
        while(getchar() != '\n');
        insertNode(&startPtr, item);
        printList(startPtr);
        break;

      case 2:
        if(!isEmpty(startPtr)) 
        { 
          printf("Enter character to be deleted: ");
          scanf("\n%c", &item);
          while (getchar() != '\n');
          if(deleteNode(&startPtr, item))
          {
            printf("%c deleted.\n", item);
            printList(startPtr);
          }
          else
          {
            printf("%c not found.\n\n", item);
          }
        } 
        else
        {
          printf("List is empty.\n\n");
        } 
        break;

      case 3:
        if(!isEmpty(startPtr)) 
        {
          printf("\nTotal duplicates deleted: %d\n\n", 
            deleteDuplicates(startPtr));
          printList(startPtr);
        }
        break;

      default:
        printf("Invalid choice.\n\n");
        break;
    }

    displayMenu();
    printf("? ");
    scanf("%d", &choice);
    while(getchar() != '\n');
  }

  return EXIT_SUCCESS;
}


void displayMenu(void)
{ 
  printf("Enter your choice:\n"
    "   1 to insert an element into the list.\n"
    "   2 to delete an element from the list.\n"
    "   3 to delete all the duplicate element from the list.\n"
    "   4 to end.\n");
}

// insert a new value into the list in sorted order
void insertNode(struct listNode **pStart, char value)
{ 
  struct listNode *pNew;      
  struct listNode *pPrevious;
  struct listNode *pCurrent;

  pNew = (struct listNode *)malloc(sizeof(struct listNode)); // create new node

  if(!pNew) 
  {
    printf("%c not inserted. No memory available.\n", value);
    return;
  }

  // initialize struct data
  pNew->data = value; 
  pNew->pNext = NULL; 

  pPrevious = NULL;
  pCurrent = *pStart;

  // loop to find the correct insertion point
  while(pCurrent && value > pCurrent->data)
  { 
    pPrevious = pCurrent;        
    pCurrent = pCurrent->pNext;  
  }

  if (!pPrevious)
  { 
    // insert node at head
    pNew->pNext = *pStart;
    *pStart = pNew;
  } 
  else
  {
    // insert node
    pPrevious->pNext = pNew;
    pNew->pNext = pCurrent;
  } 
}

// delete note containing the selected value
char deleteNode(struct listNode **pStart, char value)
{ 
  struct listNode *pPrevious; 
  struct listNode *pCurrent;  
  struct listNode *pTemp;   

  if (value == (*pStart)->data) // first node in list to be deleted
  { 
    pTemp = *pStart; // attach a pointer to element to be removed
    *pStart = (*pStart)->pNext; // de-thread the node
    free(pTemp); // release this memory and set it free!
    return value;
  }
  else
  { 
    // move to second node
    pPrevious = *pStart;
    pCurrent  = (*pStart)->pNext;

    // loop to find the correct deletion point
    while (pCurrent && pCurrent->data != value)
    { 
      pPrevious = pCurrent;         // traverse through
      pCurrent  = pCurrent->pNext;   //  each node  
    }

    // delete node at pCurrent (if not NULL - element value not found)
    if(pCurrent)
    { 
      pTemp = pCurrent; // attach a pointer to element to be removed
      pPrevious->pNext = pCurrent->pNext; // de-thread the node
      free(pTemp); // release this memory and set it free!

      return value;
    }     
  }

  return '\0';
}


int isEmpty(struct listNode *pStart)
{ 
  return !pStart;
}


void printList(struct listNode *pCurrent)
{ 
  if(!pCurrent)
  {
    printf("List is empty.\n\n");
  }
  else
  { 
    printf("List contents:\n");

    while(pCurrent)
    { 
      printf("%c --> ", pCurrent->data);
      pCurrent = pCurrent->pNext; // move to next element  
    }

    printf("NULL\n\n");
  }
}

int deleteDuplicates(struct listNode* head)
{
  // Pointer to traverse the linked list
  struct listNode* current = head;

  // Variable to record total number of duplicates
  int count = 0;
 
  // Pointer to store the next pointer of a node to be deleted
  struct listNode* next_node; 
   
  // Do nothing if the list is empty
  if (!current) 
    exit(EXIT_FAILURE); 
 
  // Traverse the list till last node
  while (current->pNext) 
  {
    // Compare current node with pNext node 
    if (current->data == current->pNext->data) 
    {              
      printf("\nDuplicate: %c\n", current->pNext->data);

      next_node = current->pNext->pNext;
      free(current->pNext);
      current->pNext = next_node;
      
      count++;  
    }
    else // Advance if no deletion
    {
      current = current->pNext; 
    }
  }
  return count;
}

