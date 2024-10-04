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

// Bubble sort function to sort the linked list
void BubbleSort(PPNODE First)
{
    int i, j, iCnt;
    PNODE Temp = NULL;
    PNODE Current = NULL;
    int tempData;

    iCnt = CountNodes(*First);

    // Perform the Bubble Sort
    for(i = 0; i < iCnt - 1; i++)
    {
        Current = *First;
        for(j = 0; j < iCnt - i - 1; j++)
        {
            if(Current->iData > Current->next->iData) // Swap if elements are in wrong order
            {
                // Swap the data
                tempData = Current->iData;
                Current->iData = Current->next->iData;
                Current->next->iData = tempData;
            }
            Current = Current->next;
        }
    }
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

    BubbleSort(&Head);

    printf("\nAfter Sorting:\n");
    Display(Head);

    return 0;
}
