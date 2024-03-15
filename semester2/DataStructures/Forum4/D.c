#include <stdio.h>

int main() {
    int num;

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &num);

    int arr[num];
    int positiveArr[num], negativeArr[num];
    int posCount = 0, negCount = 0;

    for (int i = 0; i < num; ++i) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);

        if (arr[i] > 0) {
            positiveArr[posCount++] = arr[i];
        } else if (arr[i] < 0) {
            negativeArr[negCount++] = arr[i];
        }
    }

    printf("\nThe Positive elements are: ");
    for (int i = 0; i < posCount; ++i) {
        printf("%d ", positiveArr[i]);
    }

    printf("\nThe Negative elements are: ");
    for (int i = 0; i < negCount; ++i) {
        printf("%d ", negativeArr[i]);
    }

    return 0;
}
