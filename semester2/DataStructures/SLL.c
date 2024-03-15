#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *head = NULL;

Node *createNewNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void pushTail(int value)
{
    if (head == NULL)
    {
        head = createNewNode(value);
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = createNewNode(value);
    }
}

void pushHead(int value)
{
    Node *new_node = createNewNode(value);
    new_node->next = head;
    head = new_node;
}

void pushMid(int value)
{
    if (head == NULL)
    {
        head = createNewNode(value);
    }
    else
    {
        int len = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            len++;
            curr = curr->next;
        }
        int count = len % 2 == 0 ? len / 2 : (len - 1) / 2;
        curr = head;
        for (int i = 0; i < count - 1; i++)
        {
            curr = curr->next;
        }
        Node *new_node = createNewNode(value);
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

void deleteNode(int value)
{
    Node *temp = head;

    // if x/value is in head node
    if (temp != NULL && temp->value == value)
    {
        head = temp->next;
        free(temp);
        return;
    }
    Node *prev = NULL;
    while (temp != NULL && temp->value != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void viewAll()
{
    Node *curr = head;
    while (curr != NULL)
    {
        printf("[%d]->", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    pushTail(1);
    pushTail(2);
    pushTail(3);
    pushTail(4);
    pushTail(5);
    // pushTail(4);

    // pushHead(7);
    // pushHead(-1);
    // pushHead(-2);
    // pushHead(-3);

    pushMid(100);

    deleteNode(5);
    viewAll();
    return 0;
}
