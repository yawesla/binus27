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

void merge(list arr[], int left, int mid, int right) //arrnya menjasi list kalo mau sort obj
{
    int n1 = mid - left + 1; // Corrected index calculation
    int n2 = right - mid;

    list leftArr[n1], rightArr[n2]; //arrnya menjasi list kalo mau sort obj

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
        if (leftArr[i].nilai >= rightArr[j].nilai) // Mengubah < > untuk urutan besar kecil
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


int main(){
    int ppl;
    scanf("%d",&ppl);

    for(int i=0;i<ppl;i++){
        scanf("%[^#]#%d",siswa[i].nama,&siswa[i].nilai);
    }

    //sort
    mergeSort(siswa, 0, ppl - 1);

    //display
    for(int i=0;i<ppl;i++){
        printf("%s %d",siswa[i].nama,siswa[i].nilai);
    }
}