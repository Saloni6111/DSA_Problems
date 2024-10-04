#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)    // Ensures memory packing to 1-byte boundaries

struct node
{
    int iData;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// Display the elements of the circular linked list
void Display(PNODE First, PNODE Last)
{
    printf("Elements in Linked list are:\n");

    if((First == NULL) && (Last == NULL))  // Empty list case
    {
        printf("NULL\n");
        return;
    }

    do
    {
        printf("| %d | -> ",First->iData);
        First = First->next;

    } while (First != Last->next);      // Continue until we reach the first node again
    printf("\n");
}

// Count the number of nodes in the circular linked list
int CountNodes(PNODE First, PNODE Last)
{
    int iCount = 0;

    do
    {
        iCount  = iCount + 1;
        First = First->next;

    } while (First != Last->next);
    
    return iCount;
}

// Insert a node at the beginning of the circular linked list
void InsertFirst(PPNODE First, PPNODE Last , int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->iData = iNo;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))     // First node case
    {
        *First = *Last = newn;  
        (*Last)->next = *First;  
    }
    else
    {
        newn->next = *First;        // Insert new node at the beginning
        *First = newn;
        (*Last)->next = *First;     // Update last node to point to the new first node
    }
}

// Insert a node at the end of the circular linked list
void InsertLast(PPNODE First, PPNODE Last, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->iData = iNo;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))     // First node case
    {
        *First =*Last = newn;
        (*Last)->next = *First;
    }
    else
    {
        (*Last)->next = newn;   // Insert new node at the end
        *Last = newn;
        (*Last)->next = *First; // Update the last node's next pointer to maintain circularity
    }
}

// Insert a node at a specific position
void InsertAtPos(PPNODE First, PPNODE Last, int iNo, int iPos)
{
    int iCount = CountNodes(*First,*Last);  // Count current nodes

    if((iPos < 1) || (iPos > iCount + 1))   // Invalid position check
    {
        printf("Invalid Position...\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(First,Last,iNo);    // Insert at the first position
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(First,Last,iNo);     // Insert at the last position
    }
    else    // Insert in the middle
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));
        newn->iData = iNo;
        newn->next = NULL;

        PNODE Temp = *First;
        int iCnt = 0;

        for (iCnt = 1; iCnt < (iPos-1); iCnt++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;   
    }
}

// Delete the first node in the circular linked list
void DeleteFirst(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL)) //check for empty list
    {
        return;
    }

    else if(*First == *Last)    //if list contains single node
    {
        free(*First);   
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        // PNODE Temp = *First;

        // *First = Temp->next;
        // free (Temp);
        // (*Last)->next = *First;

        *First = (*First)->next;    // Update the first pointer
        free((*Last)->next);        // Free the old first node
        (*Last)->next = *First;     // Maintain circularity
    }
}

// Delete the last node in the circular linked list
void DeleteLast(PPNODE First,PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL))
    {
        return;
    }

    if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        PNODE Temp = *First;

        while (Temp->next != *Last)
        {
            Temp = Temp->next;   
        }

        free(*Last);
        *Last = Temp;
        (*Last)->next = *First;
        
    }
}

// Delete a node at a specific position
void DeleteAtPosition(PPNODE First, PPNODE Last, int iPos)
{
    int iCount = CountNodes(*First,*Last);

    if((iPos < 1) || (iPos > iCount + 1))
    {
        printf("Invalid position...\n");
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst(First,Last);
    }
    else if (iPos == iCount)
    {
        DeleteLast(First,Last);
    }
    else
    {
        PNODE Temp1 = *First;
        PNODE Temp2 = NULL;
        int iCnt = 0;

        for ( iCnt = 1; iCnt < iPos-1; iCnt++)      // Traverse to the node before deletion
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
    PNODE Tail  = NULL;
    int iRet = 0;

    InsertFirst(&Head, &Tail,51);
    InsertFirst(&Head, &Tail,21);
    InsertFirst(&Head, &Tail,11);

    Display(Head,Tail);
    iRet = CountNodes(Head,Tail);

    printf("Number of node in linked list are: %d\n", iRet);

    InsertLast(&Head, &Tail,111);
    InsertLast(&Head, &Tail,121);
    InsertLast(&Head, &Tail,151);

    Display(Head,Tail);
    iRet = CountNodes(Head,Tail);

    printf("Number of node in linked list are: %d\n", iRet);

    InsertAtPos(&Head, &Tail,111,3);

    Display(Head,Tail);
    iRet = CountNodes(Head,Tail);

    printf("Number of node in linked list are: %d\n", iRet);

    DeleteAtPosition(&Head, &Tail,3);

    Display(Head,Tail);
    iRet = CountNodes(Head,Tail);

    printf("Number of node in linked list are: %d\n", iRet);

    DeleteFirst(&Head, &Tail);

    Display(Head,Tail);
    iRet = CountNodes(Head,Tail);

    printf("Number of node in linked list are: %d\n", iRet);

    DeleteLast(&Head, &Tail);

    Display(Head,Tail);
    iRet = CountNodes(Head,Tail);

    printf("Number of node in linked list are: %d\n", iRet);

    return 0;
}