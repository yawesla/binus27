#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a task
typedef struct {
    int id;            // Task ID
    char date[11];     // Date in YYYY-MM-DD format
    char description[100];
    char status[20];   // Status: pending or completed
} Task;

// Priority Queue Node
typedef struct Node {
    Task task;
    struct Node* next;
} Node;

// Priority Queue
typedef struct {
    Node* front;
    Node* rear;
} PriorityQueue;

// Function to create a new task
Task createTask(int id, const char* date, const char* description) {
    Task newTask;
    newTask.id = id;
    strcpy(newTask.date, date);
    strcpy(newTask.description, description);
    strcpy(newTask.status, "pending"); // Initial status is pending
    return newTask;
}

// Function to create a new node
Node* createNode(Task task) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->task = task;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a priority queue
PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->front = pq->rear = NULL;
    return pq;
}

// Function to check if the priority queue is empty
int isEmpty(PriorityQueue* pq) {
    return pq->front == NULL;
}

// Function to enqueue a task into the priority queue
void enqueue(PriorityQueue* pq, Task task) {
    Node* newNode = createNode(task);
    if (isEmpty(pq)) {
        pq->front = pq->rear = newNode;
    } else {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

// Function to dequeue a task from the priority queue
Task dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = pq->front;
    Task task = temp->task;
    pq->front = pq->front->next;
    free(temp);
    return task;
}

// Function to display details of a task
void displayTask(Task task) {
    printf("ID: %d\n", task.id);
    printf("Date: %s\n", task.date);
    printf("Description: %s\n", task.description);
    printf("Status: %s\n", task.status);
}

// Function to sort tasks by date (ascending order)
void sortByDate(PriorityQueue* pq) {
    // Bubble sort
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;
    Task temp;
    if (pq->front == NULL)
        return;
    do {
        swapped = 0;
        ptr1 = pq->front;
        while (ptr1->next != lptr) {
            if (strcmp(ptr1->task.date, ptr1->next->task.date) > 0) {
                temp = ptr1->task;
                ptr1->task = ptr1->next->task;
                ptr1->next->task = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to view all tasks sorted by date
void viewTasks(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty.\n");
        return;
    }
    PriorityQueue* tempQueue = createPriorityQueue();
    while (!isEmpty(pq)) {
        Task task = dequeue(pq);
        displayTask(task);
        enqueue(tempQueue, task);
    }
    pq->front = tempQueue->front;
    pq->rear = tempQueue->rear;
    free(tempQueue);
}

// Function to remove completed tasks
void removeCompletedTasks(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty.\n");
        return;
    }
    PriorityQueue* tempQueue = createPriorityQueue();
    while (!isEmpty(pq)) {
        Task task = dequeue(pq);
        if (strcmp(task.status, "completed") != 0) {
            enqueue(tempQueue, task);
        }
    }
    pq->front = tempQueue->front;
    pq->rear = tempQueue->rear;
    free(tempQueue);
}

int main() {
    // Create a priority queue
    PriorityQueue* taskQueue = createPriorityQueue();

    // Insert some tasks
    enqueue(taskQueue, createTask(1, "2024-04-05", "Complete project report"));
    enqueue(taskQueue, createTask(2, "2024-04-06", "Prepare presentation slides"));
    enqueue(taskQueue, createTask(3, "2024-04-03", "Review meeting agenda"));
    enqueue(taskQueue, createTask(4, "2024-04-07", "Submit expense report"));

    // Sort tasks by date
    sortByDate(taskQueue);

    // View all tasks
    printf("All Tasks:\n");
    viewTasks(taskQueue);

    // Mark a task as completed
    printf("\nMarking a task as completed...\n");
    Task completedTask = dequeue(taskQueue); // Dequeue a task
    strcpy(completedTask.status, "completed"); // Change status to completed
    enqueue(taskQueue, completedTask); // Enqueue back with updated status

    // Remove completed tasks
    printf("\nRemoving completed tasks...\n");
    removeCompletedTasks(taskQueue);

    // View remaining tasks
    printf("\nRemaining Tasks:\n");
    viewTasks(taskQueue);

    return 0;
}
