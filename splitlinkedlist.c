//3. Consider two liked list A of size N. Write a program in c to Split the linked list two parts i.e. B and C each of size N/2.


#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly-linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to split a linked list into two equal-sized lists
void splitLinkedList(struct Node* head, struct Node** listB, struct Node** listC) {
    if (head == NULL || listB == NULL || listC == NULL) {
        return;
    }

    int length = 0;
    struct Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }

    int halfLength = length / 2;
    *listB = head;
    
    current = head;
    for (int i = 1; i < halfLength; i++) {
        current = current->next;
    }

    *listC = current->next;
    current->next = NULL;
}

// Function to print the elements of a linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* listA = NULL;
    struct Node* listB = NULL;
    struct Node* listC = NULL;

    // Insert elements into linked list A
    insertAtEnd(&listA, 1);
    insertAtEnd(&listA, 2);
    insertAtEnd(&listA, 3);
    insertAtEnd(&listA, 4);
    insertAtEnd(&listA, 5);

    printf("List A: ");
    printList(listA);

    splitLinkedList(listA, &listB, &listC);

    printf("List B: ");
    printList(listB);

    printf("List C: ");
    printList(listC);

    // Clean up memory
    struct Node* current = listB;
    while (current != NULL) {
        struct Node* temp = curr3
        ent;
        current = current->next;
        free(temp);
    }

    current = listC;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

