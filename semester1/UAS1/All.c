#include <stdio.h>
#include <string.h>

typedef struct data
{
    char nama[11];
    int num;
    int score;
} list;

list kecantikan[100];

// int binarySearchName(list arr[], int low, int high, const char *target) {
//     while (low <= high) {
//         int mid = low + (high - low) / 2;
//         int cmp = strcmp(arr[mid].nama, target);

//         if (cmp != 0){
//             printf("masuk: %d\n",mid+1);
//             printf("%s %s\n",arr[mid+1].nama,target);
//             return mid+1; //found the target
//         }
//         else if (cmp < 0)
//             low = mid + 1; 
//         else
//             high = mid - 1;
//     }

//     return -1;
// }

void merge(list arr[], int left, int mid, int right) // arrnya menjasi list kalo mau sort obj
{
    int n1 = mid - left + 1; // Corrected index calculation
    int n2 = right - mid;

    list leftArr[n1], rightArr[n2]; // arrnya menjasi list kalo mau sort obj

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i]; // Corrected index calculation
    }

    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i].score > rightArr[j].score || (leftArr[i].score == rightArr[j].score && strcmp(leftArr[i].nama, rightArr[j].nama) < 0)) // Mengubah < > untuk urutan besar kecil
        {
            arr[k] = leftArr[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        k++;
        j++;
    }
}

void mergeSort(list arr[], int left, int right)
{

    if (right == left)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    FILE *fp = fopen("C:/Users/user/OneDrive/Kuliah/sem1/socs1/UAS/AllMateri.txt", "r");

    int r = 0;
    int tc, posisi;
    char target[11];

    while (!feof(fp))
    {
        fscanf(fp, "%d", &tc);
        // getchar();
        for (int i = 0; i < tc; i++)
        {
            fscanf(fp, "%[^#]#%d", kecantikan[i].nama, &kecantikan[i].num);
            // getchar();
        }
        fscanf(fp, "%d %s", &posisi, target);
        // getchar();
        r++;
    }


    // Hitung Score
    for (int i = 0; i < tc; i++)
    {
        int beauty = 0;
        int temp = kecantikan[i].num;
        while (temp > 0)
        {
            beauty += temp % 10;
            temp /= 10;
        }
        kecantikan[i].score = beauty;
    }


    // MergeSort Berdasarkan Score besar ke kecil
    mergeSort(kecantikan, 0, tc - 1);

    // Display
    puts(" ");
    printf("Data Sort:");
    for (int i = 0; i < tc; i++)
    {
        printf("%s %d %d", kecantikan[i].nama, kecantikan[i].num, kecantikan[i].score);
    }
    puts(" ");

    // Mencari Nama berdasarkan Posisi 
    int res1 = posisi - 1; // Adjust position to array index

    //Mencari Posisi berdsarkan Nama
    // int res2 = binarySearchName(kecantikan, 0, tc - 1, target);
    int res2;
    puts(" ");
    for (int i = 0; i < tc; i++)
    {
        printf("Index %d %s %s\n",i,kecantikan[i].nama, target);
        if (!strcmp(target,kecantikan[i].nama))
        {
            printf("MASUKKKK KONDISI TOTTT");
            res2 = i + 1;
            break;
        }
    }

    puts(" ");
    printf("Mencari Posisi [%d] = {%s} dan Posisi dari [%s] = {%d} \n", posisi, kecantikan[res1].nama, target,res2);
    

    fclose(fp);
    return 0;
}
