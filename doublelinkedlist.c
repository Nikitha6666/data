//8.  Write a program in c to insert N Student information into the Doubly Linked List. Write a function to a. Search a Student and display his details. b. Display the details of the students who have scored above 90 in Math’s and Science.

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    float mathScore;
    float scienceScore;
    struct Student* prev;
    struct Student* next;
};

// Function to insert a student at the end of the doubly linked list
void insertStudent(struct Student** head, int rollNumber, char name[], float mathScore, float scienceScore) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newStudent->rollNumber = rollNumber;
    strcpy(newStudent->name, name);
    newStudent->mathScore = mathScore;
    newStudent->scienceScore = scienceScore;
    newStudent->prev = NULL;
    newStudent->next = NULL;

    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
        newStudent->prev = current;
    }
}

// Function to search for a student by roll number and display their details
void searchStudent(struct Student* head, int rollNumber) {
    struct Student* current = head;
    int found = 0;

    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            printf("Student found!\n");
            printf("Roll Number: %d\n", current->rollNumber);
            printf("Name: %s\n", current->name);
            printf("Math Score: %.2f\n", current->mathScore);
            printf("Science Score: %.2f\n", current->scienceScore);
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found) {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

// Function to display details of students who scored above 90 in Math and Science
void displayAbove90Students(struct Student* head) {
    struct Student* current = head;

    printf("Students who scored above 90 in Math and Science:\n");
    while (current != NULL) {
        if (current->mathScore > 90 && current->scienceScore > 90) {
            printf("Roll Number: %d\n", current->rollNumber);
            printf("Name: %s\n", current->name);
            printf("Math Score: %.2f\n", current->mathScore);
            printf("Science Score: %.2f\n", current->scienceScore);
        }
        current = current->next;
    }
}

int main() {
    struct Student* head = NULL;
    int N, rollNumber;
    char name[50];
    float mathScore, scienceScore;

    printf("Enter the number of students (N): ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &rollNumber);
        printf("Name: ");
        scanf("%s", name);
        printf("Math Score: ");
        scanf("%f", &mathScore);
        printf("Science Score: ");
        scanf("%f", &scienceScore);

        insertStudent(&head, rollNumber, name, mathScore, scienceScore);
    }

    printf("\nEnter the Roll Number to search: ");
    scanf("%d", &rollNumber);
    searchStudent(head, rollNumber);

    displayAbove90Students(head);

    // Free memory
    struct Student* current = head;
    while (current != NULL) {
        struct Student* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
