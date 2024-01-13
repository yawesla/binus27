#include <stdio.h>

int linearSearch(int arr[], int n, int target){
    for(int i=0,j=n-1;i<n && j>= 0; i++, j--){
        if(target == arr[i]) return i;
        else if(target == arr[j]) return j;
    }
    return -1;
}

int main(){
    int arr[] = {6,3,8,9,13,1,5};

    //linear
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = linearSearch(arr,size,6);

    printf("the target is found at %d\n",result);

    return 0;
}