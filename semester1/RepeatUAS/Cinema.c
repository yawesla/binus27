#include <stdio.h>

int mergeSort(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] < rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

int merge(int arr[], int left, int right)
{
    if (left == right)
        return;

    int mid = left + (right - left) / 2;
    merge(arr, left, mid);
    merge(arr, mid + 1, right);
    mergeSort(arr,left,mid,right);
}

int main()
{
    int seats;
    scanf("%d", &seats);

    int groups;
    scanf("%d", &groups);

    int people[101];
    for (int i = 0; i < groups; i++)
    {
        scanf("%d", &people[i]);
    }


    // MergeSort
    merge(people,0,groups-1);

    // BubbleSort
    // for (int i = 0; i < groups - 1; i++)
    // {
    //     for (int j = 0; j < groups - i - 1; j++)
    //     {
    //         if (people[j] > people[j + 1])
    //         {
    //             int temp = people[j];
    //             people[j] = people[j + 1];
    //             people[j + 1] = temp;
    //         }
    //     }
    // }

    printf("Sorted array: ");
    for (int i = 0; i < groups; i++)
    {
        printf("%d ", people[i]);
    }
    printf("\n");

    int maxGroup = 0;
    int calc = 0;
    for (int i = 0; i < groups; i++)
    {
        calc += people[i];
        if (calc <= seats)
            maxGroup++;
        ;
        if (people[i] == 0)
            continue; // bisa continue bisa maxGroup--
    }

    printf("maxGroup: %d", maxGroup);

    return 0;
}

// Input:
// 15 (jumlah seat)
// 4 (jumlah grup)
// 7 (orang dalam grup)
// 8
// 5
// 6

// logic = Di sorting dari kecil ke besar, lalu dijumlahkan