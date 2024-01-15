#include <stdio.h>

int main()
{
    FILE *fp = fopen("C:/Users/user/OneDrive/Kuliah/sem1/socs1/UAS/B1.txt", "r");
    int N;

    int r = 0;
    int A[1001];
    int frequency[1001] = {0};  // Initialize frequency array with zeros

    // Read N outside the loop
    fscanf(fp, "%d", &N);

    while (r < N)  // You probably want to read N values
    {
        fscanf(fp, "%d", &A[r]);

        // Increment frequency for the current value ketika r =2 dan 3, maka A[r] = 12, jadi akan di increment
        frequency[A[r]]++;

        r++;
    }

    // Find the mode (most frequent value)
    int mode = -1;
    int maxFrequency = 0;

    for (int i = 0; i < N; i++)
    {
        printf("%d[%d] : %d\n",A[i],frequency[A[i]],maxFrequency);
        if (frequency[A[i]] > maxFrequency)
        {
            maxFrequency = frequency[A[i]];
            mode = A[i];
        }
        // If there are multiple values with the same frequency, choose the smallest one
        else if (frequency[A[i]] == maxFrequency && A[i] < mode)
        {
            mode = A[i];
        }
    }

    // Display
    printf("N = %d\n", N);
    printf("A[i] = ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\nFrequency array: ");
    for (int i = 0; i < 1001; i++)
    {
        if (frequency[i] > 0)
        {
            printf("%d[%d] ", i,frequency[i]);
        }
    }

    printf("\nMode: %d (frequency: %d)\n", mode, maxFrequency);

    fclose(fp);
    return 0;
}
