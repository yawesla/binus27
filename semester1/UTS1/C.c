#include <stdio.h>

int main() {
    double num[12];
    double sum = 0;

    for (int i = 0; i < 12; i++) {
        scanf("%lf", &num[i]);
        sum += num[i];
    }

    double pajak = (sum * 15) / 100;
    double gedung = (sum * 5) / 100;
    double sisa = sum - (pajak + gedung);

    printf("%.2f\n", pajak);
    printf("%.2f\n", gedung);
    printf("%.2f\n", sisa);

    return 0;
}



// input1 : 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000
// input2 : 6.3356e+06 8.59839e+06 8.72151e+06 8.62527e+06 6.61207e+06 4.45944e+06 3.67781e+06 1.51042e+06 3.45391e+06 5.29899e+06 8.30952e+06 5.31979e+06
// output1:
// 1800000.00
// 600000.00
// 9600000.00
// output1:
// 10638408.00
// 3546136.00
// 56738176.00