#include <stdio.h>
#include <string.h>

struct object
{
    char nama[100];
    int umur;
    char kelas[10];
    char nim[100];
};

void printData(struct object siswa)
{
    printf("Nama: %s\n", siswa.nama);
    printf("NIM: %s\n", siswa.nim);
    printf("Kelas: %s\n", siswa.kelas);
    printf("Umur: %d\n", siswa.umur);
}

int main()
{

    object siswa[100];
    // char nama[100],nim[100];
    // int umur;

    // buka
    FILE *fp = fopen("C:/Users/user/Documents/myRepo Github/binus27/semester1/Quiz2/data.in", "r");
    int i =0;
    // file enf of file
    while (!feof(fp))
    {
        fscanf(fp, "%[^#]#%[^#]#%[^#]#%d\n", siswa[i].nama, siswa[i].nim, siswa[i].kelas,&siswa[i].umur);
        i++;
    }

    for (int j = 0; j < i; j++)
    {
        printData(siswa[j]);
        puts(" ");
    }


    fclose(fp);

    return 0;
}