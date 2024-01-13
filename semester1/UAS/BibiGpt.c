#include <stdio.h>

// BinarySearch
int binarySearch(int arr[], int l, int r, int target) {
    int result = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target) {
            result = mid;
            l = mid + 1; // Find the largest index, so move to the right
        } else if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return result;
}

int main() {
    int num, query;
    scanf("%d %d", &num, &query);

    int arr[num + 1]; // Index from 1 to N
    for (int i = 1; i <= num; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < query; i++) {
        int target;
        scanf("%d", &target);

        // Perform binary search
        int result = binarySearch(arr, 1, num, target);

        // Output the result
        printf("Hasil: %d\n", result);
    }

    return 0;
}
