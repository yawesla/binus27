// format :
// X Y
// num1
// num2

// where X is how many digit number in num1, and Y how many digit number in num2
// Sample Input (1) :
// 3 4
// 1 2 3
// 4 5 6 7
// Sample Output (1) :
// unique

// Sample Input (2) :
// 3 4
// 1 2 3
// 3 2 5 6

// Sample Output (2) :
// not unique

#include <stdio.h>

int main(){
    int tc =2;
    int x,y;
    int num1,num2;

    scanf("%d %d",&x,&y);

    for(int i=0;i<tc;i++){
        
        for(int j=0;j < x;j++){
            scanf("%d",&num1);
            printf("print %d ",num1);
        }


        for(int k=1;k < y;k++){
            scanf("%d",&num2);
            printf("print %d ",num2);
        }
    }
}