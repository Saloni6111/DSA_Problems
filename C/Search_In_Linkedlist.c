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

// Function to get the pointer to a node at a specific index in the list
PNODE GetNodeAt(PNODE First, int iPos)
{
    for (int iCnt = 0; iCnt < iPos; iCnt++)
    {
        First = First->next;
    }
    return First;
}

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//     Function Name: Binary Search                                     //
//     Parameters: PNODE First: pointer to the first node of list       //
//                 int Key: Element to search in linked list            //
//     Return:  int : returns -1 if the list is empty or element        //
//                     is not found. else return index position of node //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

int BinarySearch(PNODE First, int iKey)
{
    int iStart = 0;
    int iEnd = CountNodes(First) - 1;
    int iMid;

    while (iStart <= iEnd)
    {
        iMid = (iStart + iEnd) / 2;

        PNODE MidNode = GetNodeAt(First, iMid); // Get the middle node
        
        if (MidNode->iData == iKey)
        {
            return iMid; // Element found, return index
        }
        else if (iKey < MidNode->iData)
        {
            iEnd = iMid - 1; // Search in left half
        }
        else
        {
            iStart = iMid + 1; // Search in right half
        }
    }

    return -1; // Element not found
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//     Function Name: Linear Search                                     //
//     Parameters: PNODE First: pointer to the first node of list       //
//                 int Key: Element to search in linked list            //
//     Return:  int : returns -1 if the list is empty or element        //
//                     is not found. else return index position of node //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

int LinearSearch(PNODE First, int iKey)
{
    int iCnt = -1;
    bool Flag = false;

    while(First != NULL)
    {
        iCnt++;
        
        if(First->iData == iKey)
        {
            Flag = true;
            break;
        }
        First = First->next;
    }

    return iCnt;
}

//////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    // Inserting elements in sorted order
    InsertLast(&Head, 111);
    InsertLast(&Head, 116);
    InsertLast(&Head, 121);
    InsertLast(&Head, 131);
    InsertLast(&Head, 141);
    InsertLast(&Head, 151);
    InsertLast(&Head, 161);
    InsertLast(&Head, 171);
    InsertLast(&Head, 181);

    Display(Head);

    iRet = BinarySearch(Head, 191);

    if(iRet == -1)
    {
        printf("Key not found!!!\n");
    }
    else
    {
        printf("Element found at Index: %d\n", iRet);
    }

    iRet = LinearSearch(Head, 151);

    if(iRet == -1)
    {
        printf("Key not found!!!\n");
    }
    else
    {
        printf("Element found at Index: %d\n", iRet);
    }

    return 0;
}
