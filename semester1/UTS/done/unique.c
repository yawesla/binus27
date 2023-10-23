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

int main() {
    int x, y;

    // Assuming the maximum value of elements is 100
    int temp[101] = {0};
    int temp2[101] = {0};

    scanf("%d %d", &x, &y);

    // Read and populate temp array
    for (int j = 0; j < x; j++) {
        int num1;
        scanf("%d", &num1);
        temp[num1] = 1; // Mark the element as present
    }

    // Read and populate temp2 array
    for (int k = 0; k < y; k++) {
        int num2;
        scanf("%d", &num2);
        temp2[num2] = 1; // Mark the element as present
    }

    int isUnique = 0; // Assuming unique initially

    for (int i = 1; i <= x+y; i++) {
        if (temp[i] == temp2[i]) {
            isUnique = 1; // If any element differs, it's not unique
            break;
        }
    }

    if (isUnique == 0) {
        printf("Unique\n");
    } else {
        printf("Not Unique\n");
    }

    return 0;
}
