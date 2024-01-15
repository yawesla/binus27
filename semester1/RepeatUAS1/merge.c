void mergeSort(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // Corrected index calculation
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

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
        if (leftArr[i] <= rightArr[j]) // Mengubah < > untuk urutan besar kecil
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

    ////////////////////////////////////////////////////////////////
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

void merge(int arr[], int left, int right)
{

    if (right == left)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    merge(arr, left, mid);
    merge(arr, mid + 1, right);
    mergeSort(arr, left, mid, right);
}

//yg dipanggil di main merge(array, 0,n-1 / tc-1)
// int main(){
//     merge(arr,0,tc-1);
// }