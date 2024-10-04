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

void SelectionSort(PPNODE First)
{
    PNODE Temp1 = *First;
    PNODE Temp2 = NULL;
    PNODE Min = NULL;
    int tempData;

    while (Temp1 != NULL)
    {
        Min = Temp1;  // Assume the current node is the minimum
        Temp2 = Temp1->next;

        // Traverse the remaining nodes to find the smallest value
        while (Temp2 != NULL)
        {
            if (Temp2->iData < Min->iData)
            {
                Min = Temp2;  // Update the node containing the minimum value
            }
            Temp2 = Temp2->next;
        }

        // Swap the data of the current node with the node containing the minimum value
        if (Min != Temp1)
        {
            tempData = Temp1->iData;
            Temp1->iData = Min->iData;
            Min->iData = tempData;
        }

        Temp1 = Temp1->next;
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

    SelectionSort(&Head);

    printf("\nAfter Sorting:\n");
    Display(Head);

    return 0;
}
