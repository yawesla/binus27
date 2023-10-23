#include <stdio.h>
#include <string.h>

int main()
{
    int tc;
    scanf("%d", &tc);

    for (int i = 0; i < tc; i++)
    {
        char string[501];
        scanf("%s", string);

        int length = strlen(string);
        for (int j = 0; j < length; j++)
        {
            char hash = string[j];

            if (isalpha(hash))
            {
                hash += 3;
                if (hash == '{')
                {
                    hash = 'A';
                }
                if (hash =='|')
                {
                    hash = 'B';
                }
                if (hash == '}')
                {
                    hash = 'C';
                }
                if (hash == '[')
                {
                    hash = '1';
                }
                if (hash == '\\')
                {
                    hash = '2';
                }
                if (hash == ']')
                {
                    hash = '3';
                } 
                
            }
            else if (isdigit(hash))
            {
                hash += 3;
                if (hash == ':')
                {
                    hash = 'a';
                }
                if (hash ==';')
                {
                    hash = 'b';
                }
                if (hash == '<')
                {
                    hash = 'c';
                }
            }

            string[j] = hash;
        }

        printf("Case #%d: %s\n", i + 1, string);
    }

    return 0;
}
