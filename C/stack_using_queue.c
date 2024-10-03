#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

// Stack structure definition
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Push an element onto the stack
void push(struct Stack* s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = data;
}

// Pop an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}

// Peek the top element of the stack
int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->arr[s->top];
}

// Queue structure using two stacks
struct Queue {
    struct Stack s1, s2;  // Two stacks for enqueue and dequeue
};

// Initialize the queue
void initQueue(struct Queue* q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

// Enqueue operation
void enqueue(struct Queue* q, int data) {
    // Push the data into the first stack
    push(&q->s1, data);
    printf("Enqueued %d\n", data);
}

// Dequeue operation
int dequeue(struct Queue* q) {
    // If the second stack is empty, transfer elements from the first stack
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    // Pop the top element from the second stack
    if (!isEmpty(&q->s2)) {
        int data = pop(&q->s2);
        printf("Dequeued %d\n", data);
        return data;
    } else {
        printf("Queue is empty\n");
        exit(1);
    }
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    dequeue(&q);
    dequeue(&q);

    enqueue(&q, 40);
    
    dequeue(&q);
    dequeue(&q);

    return 0;
}
