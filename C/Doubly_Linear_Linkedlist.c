#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
struct node
{
    int iData;           // Data field
    struct node *prev;    // Pointer to the previous node
    struct node *next;    // Pointer to the next node
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// Count number of nodes in the list
int CountNodes(PNODE First)
{
    int iCount = 0;
    while(First != NULL)
    {
        iCount = iCount + 1;
        First = First->next;
    }
    return iCount;
}

// Display the linked list
void Display(PNODE First)
{
    printf("Elements in Linked list are:\n");
    printf("NULL <=> ");

    while(First != NULL)
    {
        printf("| %d | <=> ", First->iData);
        First = First->next;
    }
    printf("NULL\n");
}

// Insert a node at the beginning
void InsertFirst(PPNODE First, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));  // Allocate memory for new node
    newn->iData = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn;
    }
}

// Insert a node at the end
void InsertLast(PPNODE First, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->iData = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        PNODE Temp = *First;

        while(Temp->next != NULL)  // Traverse to the last node
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
        newn->prev = Temp;
    }
}

// Insert a node at a specific position
void InsertAtPosition(PPNODE First, int iNo, int iPos)
{
    PNODE newn =(PNODE)malloc(sizeof(NODE));
    newn->iData = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    int iCount = CountNodes(*First);

    if((iPos < 1) || (iPos > iCount + 1))  // Invalid position check
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(First, iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(First,iNo);
    }
    else
    {
        PNODE Temp = *First;
        for(int iCnt = 1; iCnt < (iPos-1); iCnt++)
        {
            Temp = Temp->next;  // Traverse to the node before the target position
        }
        newn->next = Temp->next;
        Temp->next->prev = newn;
        Temp->next = newn;
        newn->prev = Temp;
    }
}

// Delete the first node
void DeleteFirst(PPNODE First)
{
    if(*First == NULL)  // If the list is empty
    {
        return;
    }
    else if((*First)->next == NULL)  // If there is only one node
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        *First = (*First)->next;
        free((*First)->prev);
        (*First)->prev = NULL;
    }
}

// Delete the last node
void DeleteLast(PPNODE First)
{
    PNODE Temp = *First;

    if(*First == NULL)  // If the list is empty
    {
        return;
    }
    else if((*First)->next == NULL)  // If there is only one node
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        while(Temp->next->next != NULL)  // Traverse to the second-last node
        {
            Temp = Temp->next;
        }
        free(Temp->next);
        Temp->next = NULL;
    }
}

// Delete a node at a specific position
void DeleteAtPosition(PPNODE First, int iPos)
{
    int iCount = CountNodes(*First);

    if((iPos < 1) || (iPos > iCount))  // Invalid position check
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(First);
    }
    else if(iPos == iCount)
    {
        DeleteLast(First);
    }
    else
    {
        PNODE Temp1 = *First;
        for(int iCnt = 1;iCnt < (iPos-1); iCnt++)  // Traverse to the node before the target
        {
            Temp1 = Temp1->next;
        }
        PNODE Temp2 = Temp1->next;
        Temp1->next = Temp2->next;
        Temp2->next->prev = Temp1;
        free(Temp2);
    }
}

int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head, 51);
    InsertFirst(&Head, 21);
    InsertFirst(&Head, 11);

    Display(Head);
    iRet = CountNodes(Head);

    printf("Number of node in linked list are: %d\n", iRet);
    printf("\n\n");

    InsertLast(&Head, 151);
    InsertLast(&Head, 121);
    InsertLast(&Head,111);

    Display(Head);
    iRet = CountNodes(Head);

    printf("Number of node in linked list are: %d\n", iRet);
    printf("\n\n");

    InsertAtPosition(&Head,111,3);

    Display(Head);
    iRet = CountNodes(Head);

    printf("Number of node in linked list are: %d\n", iRet);
    printf("\n\n");

    DeleteFirst(&Head);

    Display(Head);
    iRet = CountNodes(Head);

    printf("Number of node in linked list are: %d\n", iRet);
    printf("\n\n");

    DeleteLast(&Head);

    Display(Head);
    iRet = CountNodes(Head);

    printf("Number of node in linked list are: %d\n", iRet);
    printf("\n\n");

    DeleteAtPosition(&Head,3);

    Display(Head);
    iRet = CountNodes(Head);

    printf("Number of node in linked list are: %d\n", iRet);
    printf("\n\n");

    return 0;
}
    