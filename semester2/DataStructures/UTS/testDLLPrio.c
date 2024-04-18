#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char name[30];
    char status[30];
    int priority;
    struct node *prev;
    struct node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
Node *temp;

Node *createNode(char name[], char status[], int priority)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

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
    Node *newNode = createNode(name, status, priority);

    if (head == NULL)
    {
        head = tail = newNode;
    }

    else if (newNode->priority > head->priority)
    {
        // Push Head
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    else if (newNode->priority < tail->priority)
    {
        // Push tail
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    else
    {
        // push mid
        Node *temp = head;

        while (temp && newNode->priority <= temp->priority)
        {
            temp = temp->next;
        }

        if (temp ==NULL)
        {
            // Push Tail
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        newNode->next = temp;
        newNode->prev = temp->prev;

        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

void popHead(){
    if(head == NULL) {
        return;
    }

    else if(head == tail){
        free(head);
        tail = head = NULL;
    }

    else{
        //Pop Head
        Node *temp = head;

        head = head->next;
        free(temp);
        head->prev = NULL;
    }
}

void view(){
    Node *temp = head;

     if (temp->priority == 4)
        printf("%s is in the Emergency room\n", temp->name);
    else if (temp->priority == 3)
        printf("%s is in the Examination room\n", temp->name);
    else if (temp->priority == 1 || temp->priority == 2)
        printf("%s is in the Consultation room\n", temp->name);

    // Waiting Rooom
    printf("Waiting Room: ");

    if(temp->next == NULL){
        printf("None\n");
        return;
    }

    else{
        // JIka ada node selanjutnya maka digeser kanan/next
        temp = temp->next;
    }

    while(temp){
        if(temp->next ==NULL){
            printf("%s \n\n",temp->name);
        } else {
            printf("%s, ",temp->name);
        }
    }

    temp= temp->next;

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

        else if (strcmp(c1, "CALL") == 0) // Jika tindakan adalah "CALL"
        {
            view(); // Menampilkan status ruang tunggu
            popHead(); // Memanggil pasien pertama dari antrian
        }

        else // Jika tindakan tidak valid
        {
            i--; // Mengurangi nilai i agar tindakan yang tidak valid tidak dihitung
            printf("\nInput invalid\n\n"); // Memberi tahu pengguna bahwa tindakan yang dimasukkan tidak valid
        }
    }
    return 0;
}