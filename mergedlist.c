//2. Consider two liked list A and B in sorted order. Write a program to merge the linked list A and B such that the final list C is in sorted order.

#include <stdio.h>
#include <stdlib.h>

// Node structure representing a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of a linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to merge two sorted linked lists into a new sorted linked list
struct Node* mergeSortedLists(struct Node* listA, struct Node* listB) {
    struct Node* mergedList = NULL;

    while (listA != NULL && listB != NULL) {
        if (listA->data < listB->data) {
            insertNode(&mergedList, listA->data);
            listA = listA->next;
        } else {
            insertNode(&mergedList, listB->data);
            listB = listB->next;
        }
    }

    // If there are remaining elements in listA
    while (listA != NULL) {
        insertNode(&mergedList, listA->data);
        listA = listA->next;
    }

    // If there are remaining elements in listB
    while (listB != NULL) {
        insertNode(&mergedList, listB->data);
        listB = listB->next;
    }

    return mergedList;
}

// Function to print the elements of a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize linked lists A and B
    struct Node* listA = NULL;
    struct Node* listB = NULL;

    // Insert elements into linked lists A and B (assuming they are sorted)
    insertNode(&listA, 2);
    insertNode(&listA, 4);
    insertNode(&listA, 6);

    insertNode(&listB, 1);
    insertNode(&listB, 3);
    insertNode(&listB, 5);

    // Merge the sorted linked lists A and B into a new sorted linked list C
    struct Node* mergedList = mergeSortedLists(listA, listB);

    // Print the merged list C
    printf("Merged List: ");
    printList(mergedList);

    // Free allocated memory (not necessary for a short-lived program)
    while (mergedList != NULL) {
        struct Node* temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}
Consider two liked list A of size N. Write a program to Split the linked list two parts i.e. B and C each of size N/2


#include <stdio.h>
#include <stdlib.h>

// Node structure representing a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of a linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to split a linked list into two parts of size N/2
void splitLinkedList(struct Node* source, struct Node** front, struct Node** back) {
    if (source == NULL || source->next == NULL) {
        *front = source;
        *back = NULL;
        return;
    }

    struct Node* slow = source;
    struct Node* fast = source->next;

    // Move 'fast' two steps and 'slow' one step at a time until 'fast' reaches the end
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' is now at the middle node
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

// Function to print the elements of a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize linked list A
    struct Node* listA = NULL;

    // Insert elements into linked list A
    insertNode(&listA, 1);
    insertNode(&listA, 2);
    insertNode(&listA, 3);
    insertNode(&listA, 4);
    insertNode(&listA, 5);

    // Split linked list A into two parts B and C
    struct Node* listB = NULL;
    struct Node* listC = NULL;
    splitLinkedList(listA, &listB, &listC);

    // Print the original and split lists
    printf("Original List A: ");
    printList(listA);

    printf("Split List B: ");
    printList(listB);

    printf("Split List C: ");
    printList(listC);

    // Free allocated memory (not necessary for a short-lived program)
    while (listA != NULL) {
        struct Node* temp = listA;
        listA = listA->next;
        free(temp);
    }

    return 0;
}

