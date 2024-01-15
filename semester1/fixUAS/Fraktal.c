#include <stdio.h>

long long int fraktal_C(long long int x) {
    long long int totalAsterisks = 0;

    if (x <= 0) {
        return 0;
    } else {
        totalAsterisks += fraktal_C(x - 2); // Add the total from the recursive call
        for (long long int i = 1; i <= x; i++) {
            // Uncomment the next line if you want to print asterisks
            // printf("*");
            totalAsterisks++; // Add each asterisk that would be printed
        }

        totalAsterisks += fraktal_C(x - 1); // Add the total from the second recursive call
    }

    return totalAsterisks;
}

int main() {
    long long int X;
    scanf("%lld", &X);

    long long int result = fraktal_C(X);

    printf("Total Asterisks: %lld\n", result);

    return 0;
}
