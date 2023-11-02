#include <stdio.h>

int main()
{
    int urutan;
    scanf("%d", &urutan);

    int aan = 0, kenken = 0;
        for (int i = 1; i <= urutan; i++)
        {
            int amount;
            scanf("%d", &amount);

            if (urutan % 2 == 0){
                if (i % 2 == 0) aan += amount / 3/4; // Add 2000 to even indices
            } else {
                aan += amount / 4/5; // Add 2500 to odd indices
            } 
        }

        for (int k = 1; k <= urutan; k++){
            int amount;
            scanf("%d", &amount);
            kenken += amount;
        }

    printf("%d %d\n", aan, kenken);

    if (aan > kenken){
        printf("puput\n");
    } else{
        printf("pipit\n");
    }

    return 0;
}


// 59325.2 84442.1 85808.8 84740.4 62394 38499.7 29823.7 5765.63 27338.4 47818.7
// 81235.7 48049.7 39339.2 83624.3 33805.9 64852.4 36887.3 95719.8 14121 87021.7 47413.4 80111 52095.7 67920.1 72091.2 58243.8 53783.6 75885.7
 