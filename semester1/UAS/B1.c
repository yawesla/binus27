#include <stdio.h>

int main()
{
    FILE *fp = fopen("C:/Users/user/Documents/myRepo Github/binus27/semester1/UAS/B1.txt", "r");
    int N;
    int A[N];

    int r = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%d", &N);

        for (int i = 0; i < N; i++)
        {
            fscanf(fp,"%d", &A[i]);
        }
        r++;
    }

    // Display
    printf("N = %d\n", N);
    for (int i = 0; i < N; i++)
    {
        printf("A[i] = %d", A[i]);
    }
    return 0;
}