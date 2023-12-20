#include <stdio.h>
#include <string.h>

typedef struct data
{
    char nama[11];
    int nilai;
} list;

list siswa[1001];
list temp[1001]; // Temporary array for merge sort

void merge(list arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Copy data to temporary arrays
    list L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        // if (L[i].nilai <= R[j].nilai) //ASC (low to high)
        if (L[i].nilai >= R[j].nilai) // DESC (high to low)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(list arr[], int left, int right)
{
    if (left < right)
    {
        // Same as (left+right)/2, but avoids overflow for
        // large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

        mergeSort(siswa, 0, ppl - 1);

        for (int j = 0; j < ppl; j++)
        {
            printf("Rank %d: %s\n", j + 1, siswa[j].nama);
        }

        char target[11];
        scanf("%[^\n]", target);
        getchar();

        // printf("%s (Target) Rank is: ");
        for (int j = 0; j < ppl; j++)
        {
            if (!strcmp(target, siswa[j].nama))
            {
                printf("Case #%d: %d\n", i, j + 1);
                break;
            }
        }
    }
    return 0;
}
