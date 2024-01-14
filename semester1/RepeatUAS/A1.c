#include <stdio.h>
#include <string.h>

typedef struct data{
    char str[101];
    int total; // total konsonan selai aiueo
} list;

int main(){
    int N,M;
    scanf("%d %d",&N,&M);

    list S[N];
    for (int i = 0; i< N;i++){
        scanf("%s",S[i].str);

        S[i].total = 0;
        for(int j = 0;j<M;j++){
            if(S[i].str[j] != 'a' && S[i].str[j] != 'i' && S[i].str[j] != 'u' && S[i].str[j] != 'e' && S[i].str[j] != 'o'){
                S[i].total++;
            }
        }
    }

    //Sort
    for(int i =0;i<N-1;i++){
        for(int j=0;j<N-i-1;j++){
            if(S[j].total > S[j+1].total || (S[j].total == S[j+1].total && strcmp(S[j].str,S[j+1].str) > 0)){
                list temp = S[j];
                S[j] = S[j+1];
                S[j+1] = temp;
            }
        }
    }

    // Display
    for (int i = 0; i < N; i++)
    {
        printf("Hasil: %s[%d]\n", S[i].str,S[i].total);
    }
    return 0;
}