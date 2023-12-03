#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Structure to represent a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new queue node
struct QueueNode* createQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a queue
struct Queue* initializeQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if a queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue a data into a queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createQueueNode(data);

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a data from a queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1; // indicating an error, assuming -1 is not a valid data value
    }

    struct QueueNode* temp = queue->front;
    int data = temp->data;

    queue->front = temp->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

// Function to push an element onto the stack
void push(struct Queue* q1, struct Queue* q2, int data) {
    // Enqueue the new element into the non-empty queue
    if (!isEmpty(q1)) {
        enqueue(q1, data);
    } else {
        enqueue(q2, data);
    }
}

// Function to pop an element from the stack
int pop(struct Queue* q1, struct Queue* q2) {
    int poppedValue;

    if (isEmpty(q1) && isEmpty(q2)) {
        printf("Stack is empty.\n");
        return -1; // indicating an error, assuming -1 is not a valid data value
    }

    // Dequeue all elements from the non-empty queue except the last one
    if (!isEmpty(q1)) {
        while (q1->front->next != NULL) {
            enqueue(q2, dequeue(q1));
        }
        poppedValue = dequeue(q1);
    } else {
        while (q2->front->next != NULL) {
            enqueue(q1, dequeue(q2));
        }
        poppedValue = dequeue(q2);
    }

    return poppedValue;
}

int main() {
    // Create two queues to represent the stack
    struct Queue* queue1 = initializeQueue();
    struct Queue* queue2 = initializeQueue();

    // Push elements onto the stack
    push(queue1, queue2, 10);
    push(queue1, queue2, 20);
    push(queue1, queue2, 30);

    // Pop elements from the stack
    printf("Popped: %d\n", pop(queue1, queue2));
    printf("Popped: %d\n", pop(queue1, queue2));
    printf("Popped: %d\n", pop(queue1, queue2));

    return 0;
}
