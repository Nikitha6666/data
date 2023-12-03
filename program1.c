//1) Write a program IN C to insert N employee information into the Linked List. a. Write a function to Search an Employee and display his details. b. Display the Average salary of all the Employees with designation Manager.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an employee
struct Employee {
    char name[50];
    int empId;
    char designation[50];
    float salary;
    struct Employee* next;
};

// Function to insert an employee at the end of the linked list
void insertEmployee(struct Employee** head, char name[], int empId, char designation[], float salary) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    
    if (newEmployee == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    strcpy(newEmployee->name, name);
    newEmployee->empId = empId;
    strcpy(newEmployee->designation, designation);
    newEmployee->salary = salary;
    newEmployee->next = NULL;
    
    if (*head == NULL) {
        *head = newEmployee;
    } else {
        struct Employee* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEmployee;
    }
}

// Function to search for an employee by empId and display their details
void searchEmployee(struct Employee* head, int empId) {
    struct Employee* current = head;
    int found = 0;
    
    while (current != NULL) {
        if (current->empId == empId) {
            printf("Employee found!\n");
            printf("Name: %s\n", current->name);
            printf("Employee ID: %d\n", current->empId);
            printf("Designation: %s\n", current->designation);
            printf("Salary: %.2f\n", current->salary);
            found = 1;
            break;
        }
        current = current->next;
    }
    
    if (!found) {
        printf("Employee with Employee ID %d not found.\n", empId);
    }
}

// Function to calculate the average salary of employees with the designation "Manager"
float averageSalaryOfManagers(struct Employee* head) {
    int count = 0;
    float totalSalary = 0.0;
    
    struct Employee* current = head;
    
    while (current != NULL) {
        if (strcmp(current->designation, "Manager") == 0) {
            totalSalary += current->salary;
            count++;
        }
        current = current->next;
    }
    
    if (count == 0) {
        printf("No Managers found.\n");
        return 0.0;
    } else {
        return totalSalary / count;
    }
}

int main() {
    struct Employee* head = NULL;
    int N, empId;
    char name[50], designation[50];
    float salary;
    
    printf("Enter the number of employees (N): ");
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", name);
        printf("Employee ID: ");
        scanf("%d", &empId);
        printf("Designation: ");
        scanf("%s", designation);
        printf("Salary: ");
        scanf("%f", &salary);
        
        insertEmployee(&head, name, empId, designation, salary);
    }
    
    printf("\nEnter the Employee ID to search: ");
    scanf("%d", &empId);
    searchEmployee(head, empId);
    
    float avgSalary = averageSalaryOfManagers(head);
    if (avgSalary > 0.0) {
        printf("\nAverage salary of Managers: %.2f\n", avgSalary);
    }
    
    // Free memory
    struct Employee* current = head;
    while (current != NULL) {
        struct Employee* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}
