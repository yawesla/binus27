#include <stdio.h>

int main()
{
    int N, A[1001], freq[1001] = {0};
    FILE *fp = fopen("C:/Users/user/OneDrive/Kuliah/sem1/socs1/RepeatUAS/B.txt", "r");

    int r = 0;
    while (fscanf(fp, "%d", &N) == 1)
    {

        for (int i = 0; i < N; i++)
        {
            fscanf(fp, "%d", &A[i]);
            freq[A[i]]++;
        }
        r++;
    }

    // Mencari Modus
    int modus = -1;
    int maxFreq = 0;
    for (int i = 0; i < N; i++)
    {
        printf("%d[%d] : %d\n", A[i], freq[A[i]], maxFreq);
        if (freq[A[i]] > 0){
            maxFreq = freq[A[i]];
            modus = A[i];
        }
    }

    // Display
    printf("\nN = %d\n", N);
    printf("A[i] = ", N);
    for (int i = 0; i < 1001; i++)
    {
        if(freq[i] > 0){
        printf("%d[%d] ", i, freq[i]);
        }
    }
    printf("\nHasil = %d\n",modus);

    fclose(fp);
    return 0;
}