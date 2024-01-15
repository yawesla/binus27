#include <stdio.h>

typedef struct data
{
    char num[101];
    int score;
} list;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    list S[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%s", S[i].num);

        // Hitung Score
        int beauty = 0;
        for (int j = 0; S[i].num[j] != '\0'; j++)
        {
            beauty += S[i].num[j] - '0';
        }
        S[i].score = beauty;
    }


    //Sort
    for(int j =0;j<N-1;j++){
        for(int k=0;k<N-j-1;k++){
            if (S[k].score > S[k + 1].score || (S[k].score == S[k + 1].score && strcmp(S[k].num, S[k + 1].num) > 0)){
                list temp = S[k];
                S[k] = S[k+1];
                S[k+1] = temp;
            }
        }
    }

    //display
    for (int i = 0; i < N; i++)
    {
        printf("Hasil: %s [%d]\n", S[i].num, S[i].score);
    }

    return 0;
}
