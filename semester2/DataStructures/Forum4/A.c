#include <stdio.h>

int main (){
    int tc = 5,num, total = 0;

    for(int i =0;i<tc;i++){
        scanf("%d", &num);

        total += num;
    }

    printf("%d\n",total);

    return 0;
}