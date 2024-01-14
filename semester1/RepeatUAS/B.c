#include <stdio.h>

int main()
{
    int N,A[1001], total =0;
    FILE *fp = fopen("C:/Users/user/OneDrive/Kuliah/sem1/socs1/RepeatUAS/B.txt", "r");

    int r = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%d", &N);

        for (int i = 0; i < N; i++)
        {
            fscanf(fp, "%d", &A[i]);
            total += A[i];
        }
        r++;
    }

    // Display
    printf("N = %d\n", N);
    printf("A[i] = ", N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nHasil = %d\n", total);

    fclose(fp);
    return 0;
}