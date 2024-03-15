#include <stdio.h>

int main (){
    int tinggi[10] = {175, 165, 166, 157, 184, 156, 163, 176, 171, 167};

    int totalTinggi = 0;
    for (int i = 0; i < 10; ++i) {
        totalTinggi += tinggi[i];
    }

    float avg = (float)totalTinggi / 10;

    printf("%.2f\n", avg);

    return 0;
}