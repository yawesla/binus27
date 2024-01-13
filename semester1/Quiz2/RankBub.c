#include <stdio.h>
#include <string.h>

typedef struct data{
    char nama[11];
    int nilai;
} list;

list siswa[1001];

int main(){

    int tc;
    scanf("%d",&tc);
    getchar();

    for (int i =1 ;i <= tc;i++){
        int ppl;
        scanf("%d",&ppl);
        getchar();

        for(int j =0;j<ppl;j++){
            scanf("%[^#]#%d",siswa[j].nama,&siswa[j].nilai);
            getchar();
        }

        for(int j=0;j<ppl-1;j++){
            for(int k=0;k<ppl-j-1;k++){
                if(siswa[k].nilai < siswa[k+1].nilai){
                    list temp = siswa[k];
                    siswa[k] = siswa[k+1];
                    siswa[k+1] = temp;
                }
            }
        }

        

        char target[11];
        scanf("%s",target);
        getchar();

        for(int j=0;j<ppl;j++){
            // printf("#%d: %s\n", j+1,siswa[j].nama);
            if(!strcmp(target,siswa[j].nama)) {
                printf("Case #%d: %d. %s\n", i,j+1,siswa[j].nama);
            }
        }


    }
    return 0;
}