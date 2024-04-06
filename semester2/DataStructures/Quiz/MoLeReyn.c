#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_LEN 50

typedef struct Node
{
    char date[STR_LEN];
    char name[STR_LEN];
    int qty;
    struct Node *next, *prev;
} Node;

Node *head = NULL, *tail = NULL;

void pushTail(char date[], char name[], int qty)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->date, date);
    strcpy(newNode->name, name);
    newNode->qty = qty;
    newNode->next = newNode->prev = NULL;

    if (!tail)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void printStock()
{
    if (!head)
    {
        puts("Stock is empty!");
        return;
    }

    int count100D = 0, count500D = 0, count1000D = 0;
    Node *curr = head;
    while (curr)
    {
        if (strcmp(curr->name, "100D") == 0)
        {
            count100D += curr->qty;
        }
        else if (strcmp(curr->name, "500D") == 0)
        {
            count500D += curr->qty;
        }
        else if (strcmp(curr->name, "1000D") == 0)
        {
            count1000D += curr->qty;
        }
        curr = curr->next;
    }

    printf("100D Stock: %d\n", count100D);
    curr = head;
    while (curr)
    {
        if (strcmp(curr->name, "100D") == 0)
        {
            printf(" 100D : %d item (%s)\n", curr->qty, curr->date);
        }
        curr = curr->next;
    }
    printf("500D Stock: %d\n", count500D);
    curr = head;
    while (curr)
    {
        if (strcmp(curr->name, "500D") == 0)
        {
            printf(" 500D : %d item (%s)\n", curr->qty, curr->date);
        }
        curr = curr->next;
    }
    printf("1000D Stock: %d\n", count1000D);
    curr = head;
    while (curr)
    {
        if (strcmp(curr->name, "1000D") == 0)
        {
            printf(" 1000D : %d item (%s)\n", curr->qty, curr->date);
        }
        curr = curr->next;
    }
}

void popNode(Node *node)
{
    if (node == head)
    {
        head = node->next;
        free(head->prev);
        head->prev = node = NULL;
    }
    else if (node == tail)
    {
        tail = node->prev;
        free(tail->next);
        tail->next = node = NULL;
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        free(node);
        node = NULL;
    }
}

void delItem(char name[])
{
    if (!head)
    {
        puts("List is empty!");
        return;
    }
    if (strcmp(head->name, name) == 0 && head == tail)
    {
        popNode(head);
        return;
    }
    Node *curr = head;
    Node *temp = NULL;
    while (curr)
    {
        if (strcmp(curr->name, name) == 0)
        {
            temp = curr;
            curr = curr->next;
            popNode(temp);
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, qty;
    char date[STR_LEN], name[STR_LEN];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d", &date, &name, &qty);
        getchar();
        pushTail(date, name, qty);
    }
    printStock();

    
    char toDel[STR_LEN];
    scanf("%s", &toDel);
    getchar();

    delItem(toDel);
    puts("Remaining Stock:");
    printStock();
    return 0;
}
