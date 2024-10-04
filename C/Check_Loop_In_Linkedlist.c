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
bool LoopCheck(PNODE First)
{
    PNODE Student = First;
    PNODE Teacher = First;
    bool flag = false;

    while((Teacher != NULL) && (Teacher->next != NULL))
    {
        Student = Student -> next;
        Teacher = Teacher->next->next;

        if(Student == Teacher)
        {
            flag = true;
            break;
        }
    }

    return flag;
}

int main()
{
    PNODE Head = NULL;
    bool bRet = 0;

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

    Display(Head);

    bRet = LoopCheck(Head);

    if(bRet == true)
    {
        printf("There is loop\n");
    }
    else
    {
        printf("There is no loop\n");
    }
    
    return 0;
}
