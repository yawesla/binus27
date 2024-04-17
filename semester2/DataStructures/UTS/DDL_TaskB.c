#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to represent a task node
struct node
{
    int id;                 // Task ID
    char due_date[15];      // Due date of the task
    char description[30];   // Description of the task
    char name[10];          // Assigned employee's name
    char status[13];        // Status of the task
    struct node *next;      // Pointer to the next task node
    struct node *prev;      // Pointer to the previous task node
};

// printf("%s (%s): %d\n", temp->detail,temp->category, temp->amount);
// Global pointers to maintain the head and tail of the linked list of tasks
struct node *head = NULL;
struct node *tail = NULL;
struct node *temp;          // Temporary pointer for traversing the linked list

// Function declarations
// void inputdata(int i);      // Function to input data for a new task
// void printdata();           // Function to print all tasks
// void deletenode(int del);   // Function to delete completed tasks

// Function to input data for a new task
void inputdata(int id)
{
    // Allocate memory for a new task node
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    // Input task details
    newnode->id = id;  // Assign task ID

    printf("Task Description: ");
    scanf("%[^\n]", newnode->description);
    getchar(); // Clear the input buffer

    printf("Assign Employee: ");
    scanf("%[^\n]", newnode->name);
    getchar(); // Clear the input buffer
    
    printf("Due Date: ");
    scanf("%[^\n]", newnode->due_date);
    getchar(); // Clear the input buffer

    // Set task status as Pending
    strcpy(newnode->status, "Pending");

    // Initialize next and previous pointers to NULL
    newnode->next = newnode->prev = NULL;

    // Insert the new node into the linked list based on due date
    if (head == NULL)
    {
        // If the list is empty, new node becomes both head and tail
        head = tail = newnode;
    }
    else if (strcmp(newnode->due_date, head->due_date) < 0)
    {
        // Push Head (beginning)
        // If due date of new node is earlier than head's due date, insert at the beginning (Push Head)
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    else if (strcmp(newnode->due_date, tail->due_date) >= 0)
    {
        // Push Tail (End)
        // If due date of new node is later than or equal to tail's due date, insert at the end (Push Tail)
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    else
    {
        // Otherwise, find the correct position to insert the new node (disini ada bubbleSort??)
        temp = head;
        while (temp->next != NULL && strcmp(temp->due_date, newnode->due_date) < 0)
            temp = temp->next;
        temp->next->prev = newnode;
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
    }
}

// Function to print all tasks
void printdata()
{
    // Print column headers
    printf("ID %-30s Assigned Employee %-15s Status\n", "Task Description", "Due Date");
    temp = head;
    // Traverse the linked list and print each task
    while (temp != NULL)
    {
        printf("%2d %-30s %-17s %-15s %s\n", temp->id, temp->description, temp->name, temp->due_date, temp->status);
        temp = temp->next;
    }
}

// Function to delete completed tasks (Pop Head/Awal)
void deletenode(int del)
{
    // Check if the list is empty
    // if (!head) {
    //     puts("List is empty");
    //     return;
    // }

    // Loop to delete 'del' number of completed tasks
    for (int i = 0; i < del; i++)
    {
        // Use a temporary pointer to traverse the list
        temp = head;

        // Print details of the completed task
        printf("ID: %d\nDescription: %s\nAssigned Employee: %s\nDue Date: %s\nStatus: Completed\n", temp->id, temp->description, temp->name, temp->due_date);
        head = head->next;

        // Free memory allocated to the completed task
        free(temp);

        // Update the previous pointer of the new head to NULL
        head->prev = NULL;
    }
}

// Main function
int main()
{
    // Input the number of tasks
    printf("Number of tasks: ");
    int tasks;
    scanf("%d", &tasks);
    getchar(); // Clear the input buffer

    // Loop to input data for each task
    for (int i = 1; i <= tasks; i++)
    {
        inputdata(i);
    }

    // Print all tasks
    printdata();

    // Input whether there are tasks that have reached their due date
    char choice[5];
    printf("Is there any task that has reached its due date (Y/N)? ");
    scanf("%s", choice);
    getchar(); // Clear the input buffer

    // If tasks have reached their due date, delete them
    if (strcmp(choice, "Y") == 0)
    {
        int del;
        printf("How many? ");
        scanf("%d", &del);
        getchar(); // Clear the input buffer

        printf("Task details:\n");
        deletenode(del);
    }

    // Print the remaining tasks
    printf("The rest Tasks\n");
    printdata();

    return 0;
}
