//2. Consider two liked list A and B in sorted order. Write a program to merge the linked list A and B such that the final list C is in sorted order.

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

// Function to merge two sorted linked lists into a new sorted linked list
struct Node* mergeSortedLists(struct Node* listA, struct Node* listB) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (1) {
        if (listA == NULL) {
            tail->next = listB;
            break;
        }
        if (listB == NULL) {
            tail->next = listA;
            break;
        }

        if (listA->data <= listB->data) {
            tail->next = listA;
            listA = listA->next;
        } else {
            tail->next = listB;
            listB = listB->next;
        }

        tail = tail->next;
    }

    return dummy.next;
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

    // Insert elements into linked list A (sorted)
    insertAtEnd(&listA, 2);
    insertAtEnd(&listA, 5);
    insertAtEnd(&listA, 7);

    // Insert elements into linked list B (sorted)
    insertAtEnd(&listB, 3);
    insertAtEnd(&listB, 4);
    insertAtEnd(&listB, 6);

    printf("List A: ");
    printList(listA);

    printf("List B: ");
    printList(listB);

    struct Node* mergedList = mergeSortedLists(listA, listB);

    printf("Merged List C: ");
    printList(mergedList);

    // Clean up memory
    struct Node* current = mergedList;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
