#include <stdio.h>

//sort by ASC (low to high)
void bubbleSortASC(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main()
{
    int seats;
    scanf("%d", &seats);

    int groups;
    scanf("%d", &groups);

    int people[101];
    for (int i = 0; i < groups; i++)
    {
        scanf("%d", &people[i]); // Fix: use &people[i] instead of &people

        // Move the bubbleSort outside the loop to sort all groups
    }

    // Move the bubbleSort outside the loop to sort all groups
    bubbleSortASC(people, groups);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < groups; i++)
    {
        printf("%d ", people[i]);
    }
    printf("\n");

    // find maxGroup
    int maxGroup = 0;
    int calc = 0;
    for (int i = 0; i < groups; i++)
    {
        calc += people[i];
        if (calc <= seats)
        {
            maxGroup++;
        }

        if(calc == 0) maxGroup--;
        // printf("calc: %d\n", calc);
    }

    printf("Max Goup: %d", maxGroup);

    return 0;
}
