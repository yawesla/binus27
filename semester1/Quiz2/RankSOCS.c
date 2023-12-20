#include <stdio.h>
#include <string.h>

typedef struct data
{
    char nama[11];
    int nilai;
} list;

list siswa[1001];

void bubbleSort(list arr[], int n)
{
    list temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Swap if the element found is smaller than the next element
            if (arr[j].nilai > arr[j + 1].nilai) // ASC (low to high)
            // if (arr[j].nilai < arr[j + 1].nilai) //DESC (high to low)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);
    getchar();

    for (int i = 1; i <= tc; i++)
    {
        int ppl;
        scanf("%d", &ppl);
        getchar();

        for (int j = 0; j < ppl; j++)
        {
            scanf("%[^#]#%d", siswa[j].nama, &siswa[j].nilai);
            getchar();
        }

        bubbleSort(siswa, ppl);

        for (int j = 0; j < ppl; j++)
        {
            printf("Rank %d: %s\n", j + 1, siswa[j].nama);
        }

        char target[11];
        scanf("%[^\n]", target);
        getchar();

        // printf("%s (Target) Rank is: ", target);
        
        for (int j = 0; j < ppl; j++) {
            if (!strcmp(target, siswa[j].nama)) {
                printf("Case #%d: %d\n", i, j + 1);
                break;
            }
        }   

    }
    return 0;
}
