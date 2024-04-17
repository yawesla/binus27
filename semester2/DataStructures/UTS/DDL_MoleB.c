#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stok100, stok500, stok1000;

// Structure to represent a task node
struct node
{
    char duedate[15];
    char diamond[7];
    int count;
    struct node *next; // Pointer to the next task node
    struct node *prev; // Pointer to the previous task node
};

// Global pointers to maintain the head and tail of the linked list of tasks
struct node *head = NULL;
struct node *tail = NULL;
struct node *temp; // Temporary pointer for traversing the linked list

// Function to input data for a new task
void inputdata()
{
    // Allocate memory for a new task node
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    // Input task details: Due date, type of diamond, and count
    scanf("%s %s %d", newnode->duedate, newnode->diamond, &newnode->count);
    getchar(); // Clear the input buffer

    // Initialize next and previous pointers to NULL
    newnode->next = newnode->prev = NULL;

    // Insert the new node into the linked list
    if (head == NULL)
        head = tail = newnode;
    else
    {
        // Push Tail(end)
        tail->next = newnode; // Set the next pointer of the current tail node to point to the new node
        newnode->prev = tail; // Set the previous pointer of the new node to point back to the current tail node
        tail = newnode;       // Update the tail pointer to point to the new node, as it is now the last node in the list
    }
}

// Function to calculate and update stock data based on the linked list
void cekdata()
{
    // Initialize stock variables
    stok100 = 0, stok500 = 0, stok1000 = 0;

    // Traverse the linked list
    temp = head;
    while (temp != NULL)
    {
        // Update stock variables based on the type of diamond
        if (strcmp(temp->diamond, "100D") == 0)
            stok100 += temp->count;
        if (strcmp(temp->diamond, "500D") == 0)
            stok500 += temp->count;
        if (strcmp(temp->diamond, "1000D") == 0)
            stok1000 += temp->count;

        // Move to the next node
        temp = temp->next;
    }
}

// Function to print stock data and details of each diamond type
void printdata()
{
    // Calculate stock data
    cekdata(); // Update the stock counts for each diamond type

    // Print stock data for 100D diamonds
    printf("100D Stock: %d\n", stok100); // Print the total stock count for 100D diamonds
    temp = head; // Reset temp to point to the beginning of the linked list
    while (temp != NULL) // Loop through the linked list until temp reaches the end  (!temp)
    {
        if (strcmp(temp->diamond, "100D") == 0) // Check if the current node's diamond type is 100D
        {
            // If the current node is a 100D diamond, print its count and due date
            printf("100D : %02d item (%s)\n", temp->count, temp->duedate);
        }
        temp = temp->next; // Move temp to the next node
    }

    // Print stock data for 500D diamonds
    printf("500D Stock: %d\n", stok500); // Print the total stock count for 500D diamonds
    temp = head; // Reset temp to point to the beginning of the linked list
    while (temp != NULL) // Loop through the linked list until temp reaches the end
    {
        if (strcmp(temp->diamond, "500D") == 0) // Check if the current node's diamond type is 500D
        {
            // If the current node is a 500D diamond, print its count and due date
            printf("500D : %02d item (%s)\n", temp->count, temp->duedate);
        }
        temp = temp->next; // Move temp to the next node
    }

    // Print stock data for 1000D diamonds
    printf("1000D Stock: %d\n", stok1000); // Print the total stock count for 1000D diamonds
    temp = head; // Reset temp to point to the beginning of the linked list
    while (temp != NULL) // Loop through the linked list until temp reaches the end
    {
        if (strcmp(temp->diamond, "1000D") == 0) // Check if the current node's diamond type is 1000D
        {
            // If the current node is a 1000D diamond, print its count and due date
            printf("1000D : %02d item (%s)\n", temp->count, temp->duedate);
        }
        temp = temp->next; // Move temp to the next node
    }
}

// Function to delete data of a specific diamond type
void hapusdata()
{
    char hapus[7];
    scanf("%s", hapus);
    getchar(); // Clear the input buffer

    // Traverse the linked list
    temp = head;
    while (temp != NULL)
    {
        // If the diamond type matches, remove its data
        if (strcmp(temp->diamond, hapus) == 0)
        {
            strcpy(temp->diamond, ""); // Clear the diamond type
        }
        temp = temp->next;
    }
}

// Main function
int main()
{
    int tc;
    scanf("%d", &tc);
    getchar(); // Clear the input buffer

    // Loop to input data for each task
    for (int i = 0; i < tc; i++)
    {
        inputdata();
    }

    // Print stock data and details before deletion
    printdata();

    // Delete data of a specific diamond type
    hapusdata();

    // Print stock data and details after deletion
    printdata();

    return 0;
}
