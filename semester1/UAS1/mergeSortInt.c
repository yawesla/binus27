#include <stdio.h>

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    puts(" ");
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // Corrected index calculation
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i]; // Corrected index calculation
    }

    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j]) // Mengubah < > untuk urutan besar kecil
        {
            arr[k] = leftArr[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int left, int right)
{

    if (right == left)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    int array[] = {26, 36, 32, 23, 50, 34, 45, 7, 14, 16};

    int n = sizeof(array) / sizeof(array[0]);

    puts("Sebelum Sort:");
    printArr(array, n);

    mergeSort(array, 0, n - 1);

    puts("Setelah Sort:");
    // printArr(array, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    puts(" ");

    return 0;
}
