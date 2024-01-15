#include <stdio.h>

int main()
{
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

    for (int j = 0; j < num; j++)
    {
        total += val[j];
    }

    // Output the read values
    printf("Num: %d\n", num);
    for (int j = 0; j < num; j++)
    {
        printf("val[%d]: %d\n", j, val[j]);
    }

    puts(" ");

    printf("Total : %d\n", total);
    // Close the file
    fclose(fp);

    return 0;
}
