#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_LEN 50

// Define a structure for each task node
typedef struct Node {
    int id;
    char desc[STR_LEN];         // Task description
    char employee[STR_LEN];     // Assigned employee
    char dueDate[STR_LEN];      // Due date of the task
    char status[STR_LEN];       // Status of the task
    struct Node *next, *prev;   // Pointers to the next and previous nodes
} Node;

// Global pointers to maintain the head and tail of the linked list of tasks
Node *head = NULL, *tail = NULL;

// Function to insert a new task into the linked list
void insert(int id, char desc[], char employee[], char dueDate[], char status[]) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->desc, desc);
    strcpy(newNode->employee, employee);
    strcpy(newNode->dueDate, dueDate);
    strcpy(newNode->status, status);
    newNode->next = newNode->prev = NULL;

    // Insertion logic based on due date
    if (!head && !tail) {
        head = tail = newNode;
        return;
    }
    if (strcmp(dueDate, head->dueDate) > 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    else if (strcmp(dueDate, tail->dueDate) < 0) {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        return;
    }
    else {
        Node *curr = head;
        while (strcmp(dueDate, curr->next->dueDate) > 0) {
            curr = curr->next;
        }
        curr->next->prev = newNode;
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next = newNode;
        return;
    }
}

// Function to view all tasks in the linked list
void viewAll() {
    if (!tail) {
        puts("Queue is empty");
        return;
    }
    printf("ID | Task Description | Assigned Employee | Due Date | Status\n");
    Node *curr = tail;
    while (curr) {
        printf("%d | %s | %s | %s | %s\n", curr->id, curr->desc, curr->employee, curr->dueDate, curr->status);
        curr = curr->prev;
    }
}

// Function to convert a string to lowercase
void strToLower(char string[]) {
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        string[i] = tolower(string[i]);
    }
}

// Function to remove the last task from the linked list
void popTail() {
    if (!tail) {
        puts("Queue is empty");
        return;
    }
    if (head == tail) {
        printf("ID: %d\n", tail->id);
        printf("Description: %s\n", tail->desc);
        printf("Assigned Employee: %s\n", tail->employee);
        printf("Due Date: %s", tail->dueDate);
        printf("Status: Completed\n");
        free(tail);
        tail = head = NULL;
    }
    else {
        printf("ID: %d\n", tail->id);
        printf("Description: %s\n", tail->desc);
        printf("Assigned Employee: %s\n", tail->employee);
        printf("Status: Completed\n");
        tail = tail->prev;
        free(tail->next);
        tail->next = NULL;
    }
}

// Main function
int main() {
    int n;
    char desc[STR_LEN], employee[STR_LEN], due[STR_LEN];
    printf("Number of tasks: ");
    scanf("%d", &n);
    getchar();

    // Loop to input tasks
    for (int i = 0; i < n; i++) {
        printf("Task Description: ");
        scanf("%[^\n]", &desc);
        getchar();

        printf("Assign Employee: ");
        scanf("%[^\n]", &employee);
        getchar();

        printf("Due Date: ");
        scanf("%[^\n]", &due);
        getchar();

        insert(i + 1, desc, employee, due, "Pending");
        puts("");
    }

    // View all tasks
    viewAll();
    puts("");

    char input[STR_LEN];
    printf("Is there any task that has reached its due date (Y/N)? ");
    scanf("%[^\n]", &input);
    getchar();

    strToLower(input);
    if (strcmp(input, "y") == 0) {
        printf("How many? ");
        scanf("%d", &n);
        getchar();
        
        puts("Task details:");
        for (int i = 0; i < n; i++) {
            popTail();
        }
    }

    puts("");
    puts("The rest Tasks:");
    viewAll();

    return 0;
}
