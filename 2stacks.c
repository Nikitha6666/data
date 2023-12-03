#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Structure to represent a stack
struct Stack {
    struct StackNode* top;
};

// Function to create a new stack node
struct StackNode* createStackNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a stack
struct Stack* initializeStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if a stack is empty
int isStackEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1; // indicating an error, assuming -1 is not a valid data value
    }

    struct StackNode* temp = stack->top;
    int data = temp->data;

    stack->top = temp->next;
    free(temp);

    return data;
}

// Function to enqueue an element into the queue
void enqueue(struct Stack* stack1, struct Stack* stack2, int data) {
    // Push all elements from stack1 to stack2
    while (!isStackEmpty(stack1)) {
        push(stack2, pop(stack1));
    }

    // Push the new element onto stack1
    push(stack1, data);

    // Push back all elements from stack2 to stack1
    while (!isStackEmpty(stack2)) {
        push(stack1, pop(stack2));
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Stack* stack1) {
    return pop(stack1);
}

int main() {
    // Create two stacks to represent the queue
    struct Stack* stack1 = initializeStack();
    struct Stack* stack2 = initializeStack();

    // Enqueue elements into the queue
    enqueue(stack1, stack2, 10);
    enqueue(stack1, stack2, 20);
    enqueue(stack1, stack2, 30);

    // Dequeue elements from the queue
    printf("Dequeued: %d\n", dequeue(stack1));
    printf("Dequeued: %d\n", dequeue(stack1));
    printf("Dequeued: %d\n", dequeue(stack1));

    return 0;
}
