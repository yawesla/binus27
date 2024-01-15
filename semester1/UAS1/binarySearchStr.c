#include <stdio.h>
#include <string.h>

int binarySearchStr(char arr[][20], int low, int high, const char* target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(arr[mid], target);

        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    char arr[][20] = {"apple", "banana", "cherry", "date", "grape"}; // Sorted array of strings

    int size = sizeof(arr) / sizeof(arr[0]);
    const char* targetStr = "cherry";

    int result = binarySearchStr(arr, 0, size - 1, targetStr);

    if (result != -1)
        printf("The string '%s' is found at index %d\n", targetStr, result);
    else
        printf("The string '%s' is not present in the array\n", targetStr);

    return 0;
}
