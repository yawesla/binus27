#include <stdio.h>
#include <string.h>

int main()
{
    int tc;
    scanf("%d", &tc);

    int hh, mm;
    char a[3];
    for (int i = 1; i <= tc; i++)
    {
        scanf("%d %d %s", &hh, &mm, &a);
        // printf("%d %d %s\n", hh, mm,format);
        if(hh <= 12 && mm <= 59 && ss <= 60)      
    {
        if((strcmp(a,"PM") == 0) || (strcmp(a,"pm") == 0) 
           && (hh != 0) && (hh != 12))
        {
            hh = hh + 12;
        }
        if((strcmp(a,"AM") == 0) || (strcmp(a,"am") == 0) && (hh == 12))
        {
            hh = 0;
        }
        printf("The obtained 24-hour format of input is \t");
        printf("%02d:%02d:%02d", hh, mm, ss);
        printf("\n\n");
    }
    else
    {
        printf("Provide the correct inputs.\n");
    }
    }

    return 0;
}
