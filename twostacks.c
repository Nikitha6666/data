//5.Write a program in c to implement two stacks in one array A[1 .. N] in such a way that neither stack overflows unless the total number of elements in both stacks together is N.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent two stacks in a single array
struct TwoStacks {
    int arr[MAX_SIZE];
    int top1;
    int top2;
};

// Function to initialize the two stacks
void initialize(struct TwoStacks *ts) {
    ts->top1 = -1;  // Initialize top of the first stack
    ts->top2 = MAX_SIZE;  // Initialize top of the second stack
}

// Function to push an element onto the first stack
void push1(struct TwoStacks *ts, int data) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[++ts->top1] = data;
    } else {
        printf("Stack 1 overflow.\n");
    }
}

// Function to push an element onto the second stack
void push2(struct TwoStacks *ts, int data) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--ts->top2] = data;
    } else {
        printf("Stack 2 overflow.\n");
    }
}

// Function to pop an element from the first stack
int pop1(struct TwoStacks *ts) {
    if (ts->top1 >= 0) {
        return ts->arr[ts->top1--];
    } else {
        printf("Stack 1 underflow.\n");
        return -1;  // Return a sentinel value
    }
}

// Function to pop an element from the second stack
int pop2(struct TwoStacks *ts) {
    if (ts->top2 < MAX_SIZE) {
        return ts->arr[ts->top2++];
    } else {
        printf("Stack 2 underflow.\n");
        return -1;  // Return a sentinel value
    }
}

// Function to display the elements of the first stack
void displayStack1(struct TwoStacks *ts) {
    printf("Stack 1: ");
    for (int i = 0; i <= ts->top1; i++) {
        printf("%d ", ts->arr[i]);
    }
    printf("\n");
}

// Function to display the elements of the second stack
void displayStack2(struct TwoStacks *ts) {
    printf("Stack 2: ");
    for (int i = MAX_SIZE - 1; i >= ts->top2; i--) {
        printf("%d ", ts->arr[i]);
    }
    printf("\n");
}

int main() {
    struct TwoStacks ts;
    initialize(&ts);
`
    push1(&ts, 1);
    push1(&ts, 2);
    push1(&ts, 3);

    push2(&ts, 4);
    push2(&ts, 5);
    push2(&ts, 6);

    displayStack1(&ts);
    displayStack2(&ts);

    int popped1 = pop1(&ts);
    if (popped1 != -1) {
        printf("Popped from Stack 1: %d\n", popped1);
    }

    int popped2 = pop2(&ts);
    if (popped2 != -1) {
        printf("Popped from Stack 2: %d\n", popped2);
    }

    displayStack1(&ts);
    displayStack2(&ts);

    return 0;
}
