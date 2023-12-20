#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int seats;
    scanf("%d", &seats);

    int groups;
    scanf("%d", &groups);

    int people[101];
    for (int i = 0; i < groups; i++) {
        scanf("%d", &people[i]);
    }

    // Use mergeSort instead of bubbleSort
    mergeSort(people, 0, groups - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < groups; i++) {
        printf("%d ", people[i]);
    }
    printf("\n");

    // Find maxGroup
    int maxGroup = 0;
    int calc = 0;
    for (int i = 0; i < groups; i++) {
        calc += people[i];
        if (calc <= seats) {
            maxGroup++;
        }

        if (calc == 0)
            maxGroup--;
        // printf("calc: %d\n", calc);
    }

    printf("Max Group: %d", maxGroup);

    return 0;
}

