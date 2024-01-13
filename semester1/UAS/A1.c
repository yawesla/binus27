#include <stdio.h>
#include <string.h>

typedef struct {
    char str[101];
    int consonantCount;
} StringData;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    StringData strings[N];

    for (int i = 0; i < N; i++) {
        scanf("%s", strings[i].str);

        // Menghitung banyaknya huruf konsonan secara langsung
        strings[i].consonantCount = 0;
        for (int j = 0; j < M; j++) {
            if (strings[i].str[j] != 'a' && strings[i].str[j] != 'e' &&
                strings[i].str[j] != 'i' && strings[i].str[j] != 'o' && strings[i].str[j] != 'u') {
                strings[i].consonantCount++;
            }
        }
    }

    // Mengurutkan array of structs menggunakan bubble sort
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (strings[j].consonantCount > strings[j + 1].consonantCount ||
                (strings[j].consonantCount == strings[j + 1].consonantCount &&
                 strcmp(strings[j].str, strings[j + 1].str) > 0)) {
                StringData temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }

    // Menampilkan hasil pengurutan
    for (int i = 0; i < N; i++) {
        printf("Hasil : %s\n", strings[i].str);
    }

    return 0;
}
