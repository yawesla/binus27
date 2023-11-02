#include <stdio.h>
#include <string.h>

int main()
{
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++)
    {
        char s[101];
        scanf("%s", s);

        char temp[101];
        int found = 0, index = 0;

        for (int j = 0; j < strlen(s) - 1; j++)
        {
            if (s[j] == s[j + 1])
            {
                // masukkan ke array
                temp[index] = s[j];
                s[j] = s[j + 1] = ' ';
                found = 1;
                index++;
            }
        }

        // temp[index] = '\0';

        printf("Case #%d: ", i); // Use 'i' instead of 'tc'
        if (found)
        {
            printf("%s\n", temp);
        }
        else
        {
            printf("N/A\n");
        }
    }

    return 0;
}


