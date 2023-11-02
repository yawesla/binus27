#include <stdio.h>

int main() {
    int N, H;
    scanf("%d %d", &N, &H);

    int matrix[10][10];

    // Membaca elemen-elemen matriks
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int minHealth = 10001; // Inisialisasi dengan nilai yang lebih besar dari 10,000
    int K = -1; // Inisialisasi dengan nilai yang tidak valid
    int B = -1;

    // Mencari nilai kesehatan terkecil dan posisinya
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] < minHealth) {
                minHealth = matrix[i][j];
                K = i;
                B = j;
            }
        }
    }

    // Menggunakan kesehatan terkecil untuk menyembuhkan
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == K && j == B) {
                matrix[i][j] += H * H;
            } else if (i == K || j == B) {
                matrix[i][j] += H;
            }
            if (matrix[i][j] > 10000) {
                matrix[i][j] = 10000; // Maksimum kesehatan adalah 10,000
            }
        }
    }

    // Mencetak matriks hasil
    printf("ans: ");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");

    return 0;
}
