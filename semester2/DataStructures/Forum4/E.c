#include <stdio.h>

int main() {
    int num;

    printf("Input the size of the square matrix: ");
    scanf("%d", &num);

    int arr[num][num];

    printf("Input elements in the matrix:\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            printf("element - [%d],[%d] : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The First matrix is :\n");
    printf("The matrix is :\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int rowSum[num], colSum[num];
    for (int i = 0; i < num; i++) {
        rowSum[i] = colSum[i] = 0;
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            rowSum[i] += arr[i][j];
            colSum[j] += arr[i][j];
        }
    }

    printf("The sum or rows and columns of the matrix is :\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("%d", rowSum[i]);
        printf("\n");
    }

    for (int i = 0; i < num; i++) {
        printf("%d ", colSum[i]);
    }
    printf("\n");

    return 0;
}
