#include <stdio.h>

int binarySeacrh(int arr[],int left, int right,int target){
    int result = -1;

    while(left <= right){
        int mid = left + (right - left) /2;
        if(arr[mid] == target){
            result = mid;
            left = mid +1 ;
        }
        else if(arr[mid] < target) left = mid+1;
        else right = mid -1;
    }

    return result;
}


int main(){
    int N,M;
    scanf("%d %d",&N,&M);

    int A[N+1];
    for(int i = 1;i<=N;i++){
        scanf("%d", &A[i]);
    }

    int target;
    for(int i =0;i<M;i++){
        scanf("%d",&target);

    int result = binarySeacrh(A,1,N,target);

    printf("Hasil: %d\n", result);
    }

    return 0;
    
}