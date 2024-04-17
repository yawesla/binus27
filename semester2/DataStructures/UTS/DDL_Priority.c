#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char name[35];
    char status[10];
    int priority;
    struct node *prev;
    struct node *next;
} Node;

// Global pointers to maintain the head and tail of the linked list of transactions
Node *head = NULL; // Pointer to the first node in the linked list
Node *tail = NULL; // Pointer to the last node in the linked list
Node *temp;         // Temporary pointer for traversing the linked list

Node *createNode(char name[], char status[], int priority)
{
    // Allocate memory for a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    // Copy data into the new node
    strcpy(newNode->name, name);
    strcpy(newNode->status, status);
    newNode->priority = priority;

    // Set the next and previous pointers to NULL initially
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void push(char name[], char status[], int priority)
{
    struct node *node = createNode(name, status, priority);

    if (head == NULL)
    {
        // If the list is empty, set both head and tail to the new node
        head = tail = node;
    }
    else if (head->priority < node->priority)
    { // Push head
        head->prev = node;
        node->next = head;
        head = node;
    }
    else if (tail->priority > node->priority)
    { // Push Tail
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    else
    { // Push Mid
        struct node *temp = head;
        while (temp && temp->priority >= node->priority)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            // Push Tail
            node->prev = tail;
            tail->next = node;
            tail = node;
            return;
        }

        node->next = temp;
        node->prev = temp->prev;

        temp->prev->next = node;
        temp->prev = node;
    }
}

void popHead()
{
    if (head == NULL)
        return;

    // 1 node
    else if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }

    // Pop Head
    else
    {
        // temp = head;
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
}

void view()
{
    struct node *temp = head;

    if (temp->priority == 4)
        printf("%s is in the emergency room\n", temp->name);
    else if (temp->priority == 3)
        printf("%s is in the examination room\n", temp->name);
    else if (temp->priority == 1 || temp->priority == 2)
        printf("%s is in the consultation room\n", temp->name);

    // Waiting Rooom
    printf("Waiting Room: ");
    if (temp->next == NULL)
    {
        printf("None\n");
        return;
    }

    else
        temp = temp->next;

    while (temp)
    {
        if (temp->next == NULL)
            printf("%s\n\n", temp->name);
        else
            printf("%s, ", temp->name);
        temp = temp->next; // kosnep line ini sama spt i++
    }
}

int main()
{
    int n;
    printf("Input Size: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        char c1[10];
        char c2[35];
        char c3[35];
        int priority;

        printf("Input %d action: ", i + 1);
        scanf("%s", c1);
        getchar();

        if (strcmp(c1, "ADD") == 0)
        {
            scanf("%s %s", c2, c3);
            getchar();

            if (strcmp(c3, "Critical") == 0)
                priority = 4;
            else if (strcmp(c3, "Serious") == 0)
                priority = 3;
            else if (strcmp(c3, "Fair") == 0)
                priority = 2;
            else if (strcmp(c3, "Good") == 0)
                priority = 1;

            push(c2, c3, priority);
        }

        else if (strcmp(c1, "CALL") == 0)
        {
            view();
            popHead();
        }

        else
        {
            i--;
            printf("\nInput invalid\n\n");
        }
    }
    return 0;
}