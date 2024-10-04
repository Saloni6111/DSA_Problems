#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma pack(1)

struct node
{
    int iData;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE First)
{
    printf("Elements in Linked list are:\n");

    while(First != NULL)
    {
        printf("| %d | -> ", First->iData);
        First = First->next;
    }
    printf("NULL\n");
}

void InsertLast(PPNODE First, int iNo)
{
    PNODE Temp = *First;
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->iData = iNo;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
}

// Function to count the number of nodes in the linked list
int CountNodes(PNODE First)
{
    int iCnt = 0;
    while (First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
}

// Helper function to insert a node in the sorted part of the list
void SortedInsert(PPNODE Sorted, PNODE newNode)
{
    PNODE current;

    // Special case for the head end
    if (*Sorted == NULL || (*Sorted)->iData >= newNode->iData)
    {
        newNode->next = *Sorted;
        *Sorted = newNode;
    }
    else
    {
        // Locate the node before the point of insertion
        current = *Sorted;
        while (current->next != NULL && current->next->iData < newNode->iData)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to perform insertion sort on the linked list
void InsertionSort(PPNODE First)
{
    PNODE sorted = NULL;
    PNODE current = *First;
    PNODE next;

    // Traverse the given linked list and insert every node to the sorted list
    while (current != NULL)
    {
        next = current->next;
        SortedInsert(&sorted, current);  // Insert the current node into sorted list
        current = next;
    }

    // Update First to point to the sorted list
    *First = sorted;
}


int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    // Inserting elements in sorted order
    InsertLast(&Head, 121);
    InsertLast(&Head, 131);
    InsertLast(&Head, 181);
    InsertLast(&Head, 116);
    InsertLast(&Head, 141);
    InsertLast(&Head, 171);
    InsertLast(&Head, 151);
    InsertLast(&Head, 161);
    InsertLast(&Head, 111);

    printf("Before Sorting:\n");
    Display(Head);

    SelectionSort(&Head);

    printf("\nAfter Sorting:\n");
    Display(Head);

    return 0;
}
