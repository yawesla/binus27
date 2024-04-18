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
    Node *newNode = createNode(name, status, priority);

    if (head == NULL)
    {
        // If the list is empty, set both head and tail to the new node
        head = tail = newNode;
    }
    else if (newNode->priority > head->priority ) 
    { // Push head
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    else if (newNode->priority < tail->priority)
    { // Push Tail
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else
    { // Push Mid
        Node *temp = head;

        // Mulai dari head dan traverse list untuk menemukan posisi yang sesuai
        while (temp && newNode->priority <= temp->priority)
        {
            temp = temp->next;
        }

        if (temp == NULL) // Jika temp adalah NULL, itu berarti node baru memiliki prioritas terendah,
        {
            // Push Tail
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            return;
        }

        //Perbarui pointer untuk menyisipkan node baru di tengah list
        newNode->next = temp;
        newNode->prev = temp->prev;

        temp->prev->next = newNode;
        temp->prev = newNode;
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
        // Simpan node head
        Node *temp = head;

        // Pindahkan head ke node berikutnya
        head = head->next;
        free(temp);
        head->prev = NULL;
    }
}

// Kondisi Jika menggunakan PopTail
void popTail()
{
    if (tail == NULL)
        return;

    // 1 node
    else if (head == tail)
    {
        free(head); // opsional, bisa saya free head / tail
        head = tail = NULL;
    }

    // Pop Tail
    else
    {
        // Simpan node sebelum tail
        Node *temp = tail;

        // Hapus tail
        tail = tail->prev;
        free(temp);
        tail->next = NULL;
    }
}

void view()
{
    Node *temp = head;

    if (temp->priority == 4)
        printf("%s is in the emergency room\n", temp->name);
    else if (temp->priority == 3)
        printf("%s is in the examination room\n", temp->name);
    else if (temp->priority == 1 || temp->priority == 2)
        printf("%s is in the consultation room\n", temp->name);

    // Waiting Rooom
    printf("Waiting Room: ");

    // Mengecek apakah tidak ada node setelah node pertama (tail)
    if (temp->next == NULL)
    {
        printf("None\n"); // Jika tidak ada node setelahnya, mencetak "None" karena tidak ada pasien yang menunggu
        return; // Mengakhiri fungsi
    }
    else
        temp = temp->next; // Jika ada, maju ke node berikutnya dalam linked list  (i++)

    // Melakukan iterasi melalui linked list untuk mencetak nama pasien yang menunggu
    while (temp)
    {
        // Mengecek apakah node yang sedang diperiksa adalah node terakhir dalam linked list
        // Jika sisa 1 Node, maka print tanpa koma
        if (temp->next == NULL)
            printf("%s \n\n", temp->name); // Jika ya, mencetak nama pasien tanpa koma dan ditambahkan baris baru
        else
            printf("%s, ", temp->name); // Jika tidak, mencetak nama pasien dengan koma

    
        temp = temp->next; // Maju ke node berikutnya dalam linked list
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