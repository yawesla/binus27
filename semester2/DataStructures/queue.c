// Queue implementation in C

#include <stdio.h>
#define SIZE 8

void enQueue(int);
void deQueue();
void display();
void peek();

int items[SIZE], front = -1, rear = -1;

int main()
{
    // deQueue is not possible on empty queue
    //   deQueue();

    // enQueue 5 elements
    enQueue(20);
    enQueue(30);
    enQueue(15);
    deQueue();
    peek();
    enQueue(23);

    // 6th element can't be added to because the queue is full
    //   enQueue(6);

    //   display();

    // deQueue removes element entered first i.e. 1
    deQueue();

    // Now we have just 4 elements
    display();

    return 0;
}

void enQueue(int value)
{
    if (rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        items[rear] = value;
        printf("\nInserted -> %d", value);
    }
}

void deQueue()
{
    if (front == -1)
        printf("\nQueue is Empty!!");
    else
    {
        printf("\nDeleted : %d", items[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void peek() // Function definition for peek/front
{
    if (front == -1)
    {
        printf("\nQueue is Empty!!");
    }
    else
    {
        printf("\nFront element: %d", items[front]);
    }
}

// Function to print the queue
void display()
{
    if (rear == -1)
        printf("\nQueue is Empty!!!");
    else
    {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", items[i]);
    }
    printf("\n");
}