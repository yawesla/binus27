#include <stdio.h>
#include <string.h>

typedef struct data{
    char nama[11];
    int nilai;
} list;


list siswa[11];

int main(){
    int tc;
    scanf("%d",&tc);
    getchar();

    for(int i =0;i< tc;i++){
        scanf("%[^#]#%d", siswa[i].nama,&siswa[i].nilai);
        getchar();
    }


    for(int i =0;i<tc-1;i++){
        for(int j=0;j<tc-i-1;j++){
            if(siswa[j].nilai > siswa[j+1].nilai){
                list temp = siswa[j];
                siswa[j] = siswa[j+1];
                siswa[j+1] = temp;
            }
        }
    }

    // Dispaly
    printf("\nRank:\n");
    for(int i =0;i< tc;i++){
        printf("%d. %s %d\n",i+1,siswa[i].nama,siswa[i].nilai);
    }

    char target[11];
    scanf("%[^\n]",target);
    getchar();

    for(int i = 0;i<tc;i++){
        printf("%d - %s\n",i+1,siswa[i].nama);
        //bisa juga strcmp() == 0 (true) ketika menggunakan getchar();
        if(!strcmp(target, siswa[i].nama) ){
            printf("Hasil: %d\n" , i+1);
            break;
        }
    }


    return 0;
}