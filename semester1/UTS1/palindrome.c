#include <stdio.h>
#include <string.h>

int main()
{

    int tc;
    scanf("%d", &tc);

    char string[501];
    for (int i = 1; i <= tc; i++)
    {
        scanf("%s", string);

        int len = strlen(string);

        char palindrome[len];
        // int isPalindrome = 0;
        for (int j = len; j >= 0; j--)
        {
            palindrome[len] = string[j];
            printf("%c", palindrome[j]);
        }

        palindrome[len] = '\0';


        printf("--\n string:%s palindrom:%s\n", string, palindrome);
        if (palindrome[len] == string[len]) printf("yes\n");
        else printf("no\n");


    }
    return 0;
}