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

void Reverse(PPNODE First)
{
    PNODE Previous, Next, Current;

    Previous = NULL;
    Next = NULL;
    Current = *First;

    while(Current != NULL)
    {
        Next = Current->next;
        Current->next = Previous;
        Previous = Current;

        Current = Next;
    }
    *First = Previous;
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

    printf("Orignal linked list:\n");
    Display(Head);

    Reverse(&Head);

    printf("\nAfter reversing:\n");
    Display(Head);

    return 0;
}
