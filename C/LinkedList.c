#include <stdio.h>
#include <stdlib.h>

//Defination of a Linked List using pointers
struct Node {
    int data;
    struct Node *next;
};


//Creates a Node and allocates into Heap memory 
struct Node *createNode(int data){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node ));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traverse(struct Node *head){
    printf("\n");
    struct Node* current = head;
    while (current != NULL)
    {
        printf("%d\n" , current->data);
        current = current->next;
    }
    
}
// Function to insert a node at the end of the linked list
//Taking Double Pointer so as to change the head if required
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;


    //if head is NULL
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to insert a node after a given previous node
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}



// Function to delete the first occurrence of a given key in the linked list
void deleteAtMiddle(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted, keeping track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the list
    if (temp == NULL) return;

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}


// Function to delete the last node of the linked list
void deleteAtEnd(struct Node** head_ref) {
    if (*head_ref == NULL) return;

    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If there is only one node in the list
    if (temp->next == NULL) {
        free(temp);
        *head_ref = NULL;
        return;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Unlink the last node
    prev->next = NULL;
    free(temp);
}


int main(){
    struct Node* head = malloc(sizeof(struct Node)) ;
    head->data = 1;
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    printf("Linked List after insertion: ");
    traverse(head);

    // Delete node with data 3
    deleteAtMiddle(&head, 3);
    printf("Linked List after deleting node with data 3: ");
    traverse(head);

    // Delete at end
    deleteAtEnd(&head);
    printf("Linked List after deleting at end: ");
    traverse(head);

    return 0;
}