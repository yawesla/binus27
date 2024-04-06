#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for each transaction node
struct node
{
    char category[20];
    char detail[20];
    int amount;
    struct node *next;
    struct node *prev;
};

// Global pointers to maintain the head and tail of the linked list of transactions
struct node *head = NULL;  // Pointer to the first node in the linked list
struct node *tail = NULL;  // Pointer to the last node in the linked list
struct node *temp;         // Temporary pointer for traversing the linked list

// Function to insert a new transaction node
void insertNode(char category[], char detail[], int amount)
{
    // Allocate memory for a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    // Copy data into the new node
    strcpy(newNode->category, category);
    strcpy(newNode->detail, detail);
    newNode->amount = amount;
    // Set the next and previous pointers to NULL initially
    newNode->next = NULL;
    newNode->prev = NULL;

    // Check if the list is empty
    if (head == NULL)
    {
        // If the list is empty, set both head and tail to the new node
        head = tail = newNode;
    }
    else
    {
        // If the list is not empty, append the new node to the end of the list
        tail->next = newNode;   // Set the next pointer of the current tail node to point to the new node
        newNode->prev = tail;   // Set the previous pointer of the new node to point back to the current tail node
        tail = newNode;         // Update the tail pointer to point to the new node, as it is now the last node in the list
    }
}

// Function to delete transactions with a specific detail
void deleteTransaction(char detail[])
{
    // Start from the head of the list
    temp = head;
    // Traverse the list
    while (temp != NULL)
    {
        // Check if the detail of the current node matches the detail to be deleted
        if (strcmp(temp->detail, detail) == 0)
        {
            // Delete the node
            // Cases: head node, tail node, or intermediate node

            if (temp == head && temp == tail)
            {
                // Case: Only one node in the list
                head = tail = NULL;
            }
            else if (temp == head)
            {
                // Case: Node to be deleted is the head node
                head = head->next;
                head->prev = NULL;
            }
            else if (temp == tail)
            {
                // Case: Node to be deleted is the tail node
                tail = tail->prev;
                tail->next = NULL;
            }
            else
            {
                // Case: Node to be deleted is an intermediate node
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);  // Free the memory allocated for the deleted node
            return;      // Exit after deleting the first matching transaction
        }
        temp = temp->next;  // Move to the next node
    }
    // If the transaction with the given detail is not found
    printf("Transaction with detail '%s' not found.\n", detail);
}

// Function to print the balance and expenses for each category
void printData(int initialBalance)
{
    int totalBalance = initialBalance;
    int foodExpense = 0, houseExpense = 0, entertainmentExpense = 0, otherExpense = 0;

    // Traverse the list to calculate the total balance and category expenses
    temp = head;
    while (temp != NULL)
    {
        totalBalance -= temp->amount; // Update total balance for each transaction

        // Update category expenses based on the category of the current transaction
        if (strcmp(temp->category, "food") == 0)
        {
            foodExpense += temp->amount;
        }
        else if (strcmp(temp->category, "house") == 0)
        {
            houseExpense += temp->amount;
        }
        else if (strcmp(temp->category, "entertainment") == 0)
        {
            entertainmentExpense += temp->amount;
        }
        else if (strcmp(temp->category, "other") == 0)
        {
            otherExpense += temp->amount;
        }
        temp = temp->next;  // Move to the next node
    }

    // Print the total account balance
    printf("Account Balance: %d\n", totalBalance);
    // Print category expenses
    printf("food: %d\nhouse: %d\nentertainment: %d\nother: %d\n", foodExpense, houseExpense, entertainmentExpense, otherExpense);

    // Print the details of each transaction
    temp = head;
    while (temp != NULL)
    {
        printf("%s (%s): %d\n", temp->detail, temp->category, temp->amount);
        temp = temp->next;  // Move to the next node
    }
}

// Main function
int main()
{
    int initialBalance, numTransactions;
    scanf("%d", &initialBalance);  // Input the initial account balance
    scanf("%d", &numTransactions); // Input the number of transactions

    // Input transactions
    for (int i = 0; i < numTransactions; i++)
    {
        char category[20], detail[20];
        int amount;
        scanf("%s %s %d", category, detail, &amount); // Input category, detail, and amount for each transaction
        insertNode(category, detail, amount);         // Insert the transaction into the linked list
    }

    char deleteDetail[20];
    printf("Enter the detail of the transaction to delete: ");
    scanf("%s", deleteDetail);
    deleteTransaction(deleteDetail);  // Delete the transaction with the specified detail
    
    // Print account balance, category expenses, and transaction details
    printData(initialBalance);

    // Free memory allocated for nodes
    temp;  // Temporary pointer for freeing memory
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);  // Free memory for each node
    }

    return 0;
}
