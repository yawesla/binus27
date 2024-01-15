#include <stdio.h>

// MERGESORT

void merge_sort(int arr[], int left, int right)
{
    // stop recursion
    if (right == left)
    {
        return;
    }

    // divide
    int middle = left + (right - left) / 2;
    merge_sort(arr, left, middle);
    merge_sort(arr, middle + 1, right);

    // conquer
    int temp[right - left + 1];

    int leftIndex = left;
    int leftLimit = middle;

    int rightIndex = middle + 1;
    int rightLimit = right;

    int tempIndex = 0;

    while (leftIndex <= leftLimit && rightIndex <= rightLimit)
    {
        if (arr[leftIndex] <= arr[rightIndex])
        {
            temp[tempIndex] = arr[leftIndex];
            leftIndex++;
        }
        else
        {
            temp[tempIndex] = arr[rightIndex];
            rightIndex++;
        }
        tempIndex++;
    }

    while (rightIndex <= rightLimit)
    {
        temp[tempIndex] = arr[rightIndex];
        rightIndex++;
        tempIndex++;
    }

    while (leftIndex <= leftLimit)
    {
        temp[tempIndex] = arr[leftIndex];
        leftIndex++;
        tempIndex++;
    }

    tempIndex = left;
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[tempIndex - left];
        tempIndex++;
    }
}

int main()
{
    int array[] = {2, 3, 1, 5, 7, 6, 9, 8, 10};
    // int array[] = {26, 36, 32, 23, 50, 34, 45, 7, 14,16};
    
    int length = sizeof(array) / sizeof(array[0]);

    merge_sort(array, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        if (i != length - 1)
        {
            printf("%d ", array[i]);
        }
        else
        {
            printf("%d\n", array[i]);
        }
    }

    return 0;
}

