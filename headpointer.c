//4.Write a program to create a single linked list. The address of the head is to be stored in a separate structure which has two fields 

struct head {
struct node *head_ptr; 
int num; 
}; 
//The head_ptr will store the pointer to the head node num: Is the count of the number of elements present in the linked list. Write implementations for insertion and deletion which will update the head structure appropriately

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly-linked list node
struct Node {
    int data;
    struct Node* next;
};

// Define a structure to store the head of the linked list
struct Head {
    struct Node* head_ptr;
    int num;
};

// Function to initialize the head structure and create an empty linked list
void initializeList(struct Head* head) {
    head->head_ptr = NULL;
    head->num = 0;
}

// Function to insert a new node at the end of the linked list
void insertNode(struct Head* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head->head_ptr == NULL) {
        head->head_ptr = newNode;
    } else {
        struct Node* current = head->head_ptr;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    head->num++;
}

// Function to delete a node with a given data value from the linked list
void deleteNode(struct Head* head, int data) {
    struct Node* current = head->head_ptr;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                head->head_ptr = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            head->num--;
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Element %d not found in the list.\n", data);
}

// Function to print the elements of the linked list
void printList(struct Head* head) {
    struct Node* current = head->head_ptr;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Head head;
    initializeList(&head);

    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);

    printf("Linked List: ");
    printList(&head);

    deleteNode(&head, 3);
    printf("Linked List after deleting 3: ");
    printList(&head);

    return 0;
}
