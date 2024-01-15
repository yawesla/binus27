#include <stdio.h>

typedef struct data
{
    int num;
    int score;
} list;

int calculateBeauty(int number) {
    int beauty = 0;
    while (number > 0) {
        beauty += number % 10; // Extract the last digit and add to beauty
        number /= 10; // Remove the last digit
    }
    return beauty;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    list beauty[N];

    // Simpan angka ke objek
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &beauty[i].num);
    }

    // Hitung skor
    for (int i = 0; i < N; i++)
    {
        beauty[i].score = calculateBeauty(beauty[i].num);
    }

    // Print hasil
    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n", beauty[i].num, beauty[i].score);
    }

    return 0;
}
