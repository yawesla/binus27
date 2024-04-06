#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_EMPLOYEE_NAME_LENGTH 50
#define MAX_DATE_LENGTH 11

// Structure to represent a task
typedef struct
{
    int id;
    char description[MAX_DESCRIPTION_LENGTH];
    char employee[MAX_EMPLOYEE_NAME_LENGTH];
    char due_date[MAX_DATE_LENGTH];
    char status[20]; // Status: pending or completed
} Task;

// Priority Queue (FIFO)
Task taskQueue[MAX_TASKS];
int front = -1, rear = -1;

// Function to enqueue a task into the priority queue
void enqueue(Task task)
{
    if (rear == MAX_TASKS - 1)
    {
        printf("Queue is full. Cannot enqueue more tasks.\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    taskQueue[rear] = task;
}

// Function to dequeue a task from the priority queue
Task dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }
    Task task = taskQueue[front];
    front++;
    return task;
}

// Function to sort tasks by due date (ascending order)
void sortByDate()
{
    Task temp;
    for (int i = front; i <= rear; i++)
    {
        for (int j = i + 1; j <= rear; j++)
        {
            if (strcmp(taskQueue[i].due_date, taskQueue[j].due_date) > 0)
            {
                temp = taskQueue[i];
                taskQueue[i] = taskQueue[j];
                taskQueue[j] = temp;
            }
        }
    }
}

// Function to insert a new task with pending status
void insertTask(int id, char *description, char *employee, char *due_date)
{
    Task newTask;
    newTask.id = id;
    strcpy(newTask.description, description);
    strcpy(newTask.employee, employee);
    strcpy(newTask.due_date, due_date);
    strcpy(newTask.status, "Pending");
    enqueue(newTask);
}

// Function to mark a task as completed and remove it from the queue
void removeCompletedTask(int id)
{
    int found = 0;
    for (int i = front; i <= rear; i++)
    {
        printf("ID KONTOL : %d == %d\n",taskQueue[i].id,id );
        printf("STATUS KONTOL = %s\n ",taskQueue[i].status);
        if (taskQueue[i].id == id && strcmp(taskQueue[i].status, "Completed") == 1)
        {
            found = 1;
            for (int j = i; j < rear; j++)
            {
                taskQueue[j] = taskQueue[j + 1];
            }
            rear--;
            printf("Task with ID %d removed.\n", id);
            break;
        }
    }
    if (!found)
    {
        printf("No task found with ID %d or task is not completed.\n", id);
    }
}

// Function to display all tasks in the queue
void displayTasks()
{
    if (front == -1 || front > rear)
    {
        printf("No tasks in the queue.\n");
        return;
    }
    printf("ID\tDescription\tEmployee\tDue Date\tStatus\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t%s\t%s\t%s\t%s\n", taskQueue[i].id, taskQueue[i].description, taskQueue[i].employee,
               taskQueue[i].due_date, taskQueue[i].status);
    }
}

// Function to display all pending tasks in the queue
void displayPendingTasks()
{
    if (front == -1 || front > rear)
    {
        printf("No pending tasks.\n");
        return;
    }
    printf("ID\tDescription\tEmployee\tDue Date\tStatus\n");
    for (int i = front; i <= rear; i++)
    {
        if (strcmp(taskQueue[i].status, "Pending") == 0)
        {
            printf("%d\t%s\t%s\t%s\t%s\n", taskQueue[i].id, taskQueue[i].description, taskQueue[i].employee,
                   taskQueue[i].due_date, taskQueue[i].status);
        }
    }
}

int main()
{
    int num_tasks;
    printf("Number of tasks: ");
    scanf("%d", &num_tasks);
    getchar(); // Consume newline character

    for (int i = 1; i <= num_tasks; i++)
    {
        char description[MAX_DESCRIPTION_LENGTH];
        char employee[MAX_EMPLOYEE_NAME_LENGTH];
        char due_date[MAX_DATE_LENGTH];

        printf("Task Description: ");
        scanf(" %[^\n]", description); // Read string until newline character
        getchar();                     // Consume newline character

        printf("Assign Employee: ");
        scanf(" %[^\n]", employee); // Read string until newline character
        getchar();                  // Consume newline character

        printf("Due Date (YYYY-MM-DD): ");
        scanf(" %[^\n]", due_date); // Read string until newline character
        getchar();                  // Consume newline character

        insertTask(i, description, employee, due_date);
    }

    printf("\nTasks before sorting by due date:\n");
    displayTasks();

    sortByDate();
    printf("\nTasks after sorting by due date:\n");
    displayTasks();

    char choice;
    printf("\nIs there any task that has reached its due date? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y')
    {
        int num_completed_tasks;
        printf("How many tasks have reached their due date? ");
        scanf("%d", &num_completed_tasks);
        getchar(); // Consume newline character

        for (int i = 0; i < num_completed_tasks; i++)
        {
            int id;
            printf("Task ID: ");
            scanf("%d", &id);
            getchar(); // Consume newline character

            // // Validate if the entered ID is within the range of valid task IDs
            // if (id < 1 || id > (rear - front + 1))
            // {
            //     printf("Invalid task ID. Please enter a valid ID.\n");
            //     i--; // Decrement i to re-prompt for the same iteration
            //     continue;
            // }

            // Update the task details
            printf("Description: ");
            scanf(" %[^\n]", taskQueue[id - 1].description);
            getchar(); // Consume newline character

            printf("Assigned Employee: ");
            scanf(" %[^\n]", taskQueue[id - 1].employee);
            getchar(); // Consume newline character

            printf("Due Date: ");
            scanf(" %[^\n]", taskQueue[id - 1].due_date);
            getchar(); // Consume newline character

            printf("Status (Completed/Pending): ");
            scanf(" %[^\n]", taskQueue[id - 1].status);
            getchar(); // Consume newline character

            // If the task status is "Completed", remove it from the queue
            if (strcmp(taskQueue[id - 1].status, "Completed") == 0)
            {
                removeCompletedTask(id);
            }
        }

        printf("\nRemaining tasks:\n");
        displayPendingTasks();
    }

    return 0;
}
