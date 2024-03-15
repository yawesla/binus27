#include <stdio.h>

int main() {
    int num;

    printf("Input the number of elements to store in the array: ");
    scanf("%d", &num);

    int arr[num];

    for (int i = 0; i < num; ++i) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nThe values stored into the array are: ");
    for (int i = 0; i < num; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\nThe values stored into the array in reverse are: ");
    for (int i = num - 1; i >= 0; --i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
