#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)     
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// Display the circular doubly linked list
void Display(PNODE First, PNODE Last)
{
    if(First == NULL && Last == NULL) // Check if the list is empty
    {
        printf("Linked list is empty\n");
        return;
    }

    printf("Elements of Linked list are : \n");
    do
    {
        printf("| %d |<=> ", First->data);
        First = First->next;
    } while(First != Last->next);

    printf("\n");
}

// Count number of nodes in the list
int CountNodes(PNODE First, PNODE Last)
{
    int iCnt = 0;

    if(First == NULL && Last == NULL) // If list is empty
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        First = First->next;
    } while(First != Last->next);

    return iCnt;
}

// Insert node at the beginning
void InsertFirst(PPNODE First, PPNODE Last, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE)); // Allocate memory for new node

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((*First == NULL) && (*Last == NULL)) // If list is empty
    {
        *First = newn;
        *Last = newn;
    }
    else    // If list contains one or more nodes
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn; 
    }

    (*First)->prev = *Last; // Adjust circular links
    (*Last)->next = *First;
}

// Insert node at the end
void InsertLast(PPNODE First, PPNODE Last, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE)); // Allocate memory for new node

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((*First == NULL) && (*Last == NULL)) // If list is empty
    {
        *First = newn;
        *Last = newn;
    }
    else    // If list contains one or more nodes
    {
        (*Last)->next = newn;
        newn->prev = *Last;
        *Last = newn;
    }

    (*First)->prev = *Last; // Adjust circular links
    (*Last)->next = *First;
}

// Insert node at a specific position
void InsertAtPosition(PPNODE First, PPNODE Last, int iNo, int iPos)
{
    int iCount = CountNodes(*First, *Last);
    PNODE Temp = *First;

    if((iPos < 1) || (iPos > iCount + 1)) // Invalid position check
    {
        printf("Invalid position...\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(First, Last, iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(First, Last, iNo);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE)); // Allocate memory for new node

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++) // Traverse to the position
        {
            Temp = Temp->next;
        }
        
        newn->next = Temp->next;
        Temp->next->prev = newn;
        newn->prev = Temp;
        Temp->next = newn;
    }
}

// Delete the first node
void DeleteFirst(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL)) // If list is empty
    {
        return;
    }
    else if(*First == *Last) // If list has only one node
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else // If list has more than one node
    {
        *First = (*First)->next;
        free((*First)->prev);
      
        (*First)->prev = *Last; // Adjust circular links
        (*Last)->next = *First;
    }
}

// Delete the last node
void DeleteLast(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL)) // If list is empty
    {
        return;
    }
    else if(*First == *Last) // If list has only one node
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else // If list has more than one node
    {
        *Last = (*Last)->prev;
        free((*First)->prev); // Free the last node
        (*First)->prev = *Last; // Adjust circular links
        (*Last)->next = *First;
    }
}

// Delete a node at a specific position
void DeleteAtPosition(PPNODE First, PPNODE Last, int iPos)
{
    int iCount = CountNodes(*First, *Last);
    PNODE Temp = *First;

    if((iPos < 1) || (iPos > iCount)) // Invalid position check
    {
        printf("Invalid position...\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(First, Last);
    }
    else if(iPos == iCount)
    {
        DeleteLast(First, Last);
    }
    else
    {
        for(int iCnt = 1; iCnt < iPos - 1; iCnt++) // Traverse to the position
        {
            Temp = Temp->next;
        }
        
        Temp->next = Temp->next->next;
        free(Temp->next->prev);
        Temp->next->prev = Temp;
    }
}

int main()
{
    PNODE Head = NULL;
    PNODE Tail  = NULL;
    int iRet = 0;

    InsertFirst(&Head, &Tail, 51);
    InsertFirst(&Head, &Tail, 21);
    InsertFirst(&Head, &Tail, 11);

    Display(Head, Tail);
    iRet = CountNodes(Head, Tail);
    printf("Number of nodes in linked list are: %d\n", iRet);

    InsertLast(&Head, &Tail, 111);
    InsertLast(&Head, &Tail, 121);
    InsertLast(&Head, &Tail, 151);

    Display(Head, Tail);
    iRet = CountNodes(Head, Tail);
    printf("Number of nodes in linked list are: %d\n", iRet);

    InsertAtPosition(&Head, &Tail, 111, 3);

    Display(Head, Tail);
    iRet = CountNodes(Head, Tail);
    printf("Number of nodes in linked list are: %d\n", iRet);

    DeleteAtPosition(&Head, &Tail, 3);

    Display(Head, Tail);
    iRet = CountNodes(Head, Tail);
    printf("Number of nodes in linked list are: %d\n", iRet);

    DeleteFirst(&Head, &Tail);

    Display(Head, Tail);
    iRet = CountNodes(Head, Tail);
    printf("Number of nodes in linked list are: %d\n", iRet);

    DeleteLast(&Head, &Tail);

    Display(Head, Tail);
    iRet = CountNodes(Head, Tail);
    printf("Number of nodes in linked list are: %d\n", iRet);

    return 0;
}
