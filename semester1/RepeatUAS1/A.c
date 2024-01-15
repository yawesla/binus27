#include <stdio.h>
#include <string.h>

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
        // Hitung Score dari char
        int cantik = 0;
        // kondisi j<M --> S[i].num[j] != '\0'
        for(int j = 0; j<M;j++){
            cantik += S[i].num[j] - '0';
        }
        S[i].score = cantik;
    }


    //bubbleSort
    for(int i=0;i<N-1;i++){
        for(int j = 0;j<N-i-1;j++){
            if(S[j].score > S[j+1].score || (S[j].score == S[j+1].score && strcmp(S[j].num,S[j+1].num) > 0)){
                list temp = S[j];
                S[j] = S[j+1];
                S[j+1] = temp;
            }
        }
    }

    // Display
    for (int i = 0; i < N; i++)
    {
        printf("Hasil: %s[%d]\n", S[i].num,S[i].score);
    }

    return 0;
}