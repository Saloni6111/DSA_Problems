#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)     // Ensures memory packing to 1-byte boundaries

struct node
{
    int iData;          // Data part of node
    struct node *next;  // Pointer to next node
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// Count the number of nodes in the linked list
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

// Display all elements in the linked list
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

// Insert a node at the beginning of the list
void InsertFirst(PPNODE First, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    if(newn == NULL)
    {
        printf("Unable to allocate memory!!!\n");
        return;
    }

    newn->iData = iNo;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }
}

// Insert a node at the end of the list
void InsertLast(PPNODE First, int iNo)
{
    PNODE Temp = *First;
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    if(newn == NULL)
    {
        printf("Unable to allocate memory!!!\n");
        return;
    }

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

// Insert a node at a specific position
void InsertAtPosition(PPNODE First, int iNo, int iPos)
{
    PNODE newn =(PNODE)malloc(sizeof(NODE));

    if(newn == NULL)
    {
        printf("Unable to allocate memory!!!\n");
        return;
    }
    
    newn->iData = iNo;
    newn->next = NULL;

    int iCount = CountNodes(*First);

    printf("%d", iCount);

    if((iPos < 1) || (iPos > iCount + 1))
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
        int iCnt = 0;

        for(iCnt = 1; iCnt < (iPos-1); iCnt++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
    }

}

// Delete the first node in the list
void DeleteFirst(PPNODE First)
{
    PNODE Temp = *First;
    if(*First == NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        (*First) = (*First)->next;
        free(Temp);
    }
}

// Delete the last node in the list
void DeleteLast(PPNODE First)
{
    PNODE Temp = *First;

    if(*First == NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        while(Temp->next->next != NULL)
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

    if((iPos < 1) || (iPos > iCount))
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
        int iCnt = 0;
        PNODE Temp1 = *First;
        PNODE Temp2 = NULL;

        for(iCnt = 1;iCnt < (iPos-1); iCnt++)
        {
            Temp1 = Temp1->next;
        }
        Temp2 = Temp1->next;
        Temp1->next = Temp2->next;
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

    InsertAtPosition(&Head,555,5);

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
