#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int value;
} Data;

// BinarySearch for string
int binarySearchString(Data arr[], int l, int r, const char* target) {
    int result = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        int comparisonResult = strcmp(arr[mid].name, target);

        if (comparisonResult == 0) {
            result = mid;
            l = mid + 1; // Find the largest index, so move to the right
        } else if (comparisonResult < 0) {
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

    Data arr[num + 1]; // Index from 1 to N
    for (int i = 1; i <= num; i++) {
        scanf("%s %d", arr[i].name, &arr[i].value);
    }

    for (int i = 0; i < query; i++) {
        char target[50];
        scanf("%s", target);

        // Perform binary search
        int result = binarySearchString(arr, 1, num, target);

        // Output the result
        printf("Hasil: %d\n", result);
    }

    return 0;
}


// testcase:
// 5 3
// Alice 10
// Bob 20
// Charlie 15
// David 25
// Eve 30
// Charlie
// Bob
// Alice