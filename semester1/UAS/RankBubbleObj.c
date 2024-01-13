// Intput:
// 5
// Nafi#20
// Irfan#90
// Zidny#60
// Love#76
// Lia#88

#include <stdio.h>

typedef struct data
{
    char nama[11];
    int nilai;
} list;

list siswa[100];


int main(){
    int ppl;
    scanf("%d",&ppl);

    for(int i=0;i<ppl;i++){
        scanf("%[^#]#%d",siswa[i].nama,&siswa[i].nilai);
    }

    for(int i =0;i<ppl-1;i++){
        for(int j=0;j<ppl-i-1;j++){
            if(siswa[j].nilai < siswa[j+1].nilai){
                    list temp = siswa[j];
                    siswa[j] = siswa[j+1];
                    siswa[j+1] = temp;
                }
        }
    }

    //display
    for(int i=0;i<ppl;i++){
        printf("%s %d",siswa[i].nama,siswa[i].nilai);
    }
}