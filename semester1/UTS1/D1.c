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
                if (i % 2 == 0) aan += amount + 2000; // Add 2000 to even indices
            } else {
                aan += amount + 2500; // Add 2500 to odd indices
            } 
        }

        for (int k = 1; k <= urutan; k++){
            int amount;
            scanf("%d", &amount);
            kenken += amount;
        }

    printf("%d %d\n", aan, kenken);

    if (aan > kenken){
        printf("aan\n");
    } else{
        printf("kenken\n");
    }

    return 0;
}
