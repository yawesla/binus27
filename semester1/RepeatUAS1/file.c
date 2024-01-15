#include <stdio.h>

int main(){
    int num, val[1001], total = 0;
    FILE *fp = fopen("C:/Users/user/OneDrive/Kuliah/sem1/socs1/UAS/jojoFile.txt", "r");

    int i = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%d", &num);

        for (int j = 0; j < num; j++)
        {
            fscanf(fp, "%d", &val[j]);
        }
        i++;
    }

    fclose(fp);
    return 0;
}