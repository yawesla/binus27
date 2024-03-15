#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL, *tail = NULL;

Node *createNewNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void pushTail(int value)
{
    Node *new_node = createNewNode(value);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

void pushHead(int value)
{
    Node *new_node = createNewNode(value);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void pushMid(int value)
{
    Node *new_node = createNewNode(value);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else if (head->next == NULL)
    {
        head->next = new_node;
        new_node->prev = head;
        tail = new_node;
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
        curr = head;
        int mid = len / 2;
        for (int i = 0; i < mid - 1; i++)
        {
            curr = curr->next;
        }
        new_node->next = curr->next;
        if (curr->next != NULL) // check if curr->next is not NULL
            curr->next->prev = new_node;
        new_node->prev = curr;
        curr->next = new_node;
    }
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

void popHead()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    Node *del = head;
    if (head->next != NULL)
        head->next->prev = NULL;
    head = head->next;
    free(del);
}

void popTail()
{
    if (tail == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    Node *del = tail;
    if (tail->prev != NULL)
        tail->prev->next = NULL;
    tail = tail->prev;
    free(del);
}

void freeList()
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    head = tail = NULL;
}

int main(int argc, char const *argv[])
{
    // pushMid(1);
    // pushMid(2);
    // pushMid(3);
    // pushMid(4);
    // pushMid(5);
    // popHead();
    // popTail();

    pushHead(3);
    pushHead(2);
    pushHead(5);

    pushTail(6);
    pushTail(8);
    pushTail(9);

    popHead();
    popTail();

    pushMid(11);



    viewAll();
    freeList();
    return 0;
}
