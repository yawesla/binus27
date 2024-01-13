#include <stdio.h>

int main() {
    int seats;
    scanf("%d", &seats);

    int groups;
    scanf("%d", &groups);

    int people[101];
    for (int i = 0; i < groups; i++) {
        scanf("%d", &people[i]);
    }

    for (int i = 0; i < groups - 1; i++) {
        for (int j = 0; j < groups - i - 1; j++) {
            if (people[j] > people[j + 1]) {
                int temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }

    // printf("Sorted array: ");
    // for (int i = 0; i < groups; i++) {
    //     printf("%d ", people[i]);
    // }
    // printf("\n");

    int maxGroup =0;
    int calc = 0;
    for(int i=0;i<groups;i++){
        calc += people[i];
        if(calc <= seats) maxGroup++;;
        if(people[i] == 0) maxGroup--;
    }

    printf("maxGroup: %d", maxGroup);

    return 0;
}
