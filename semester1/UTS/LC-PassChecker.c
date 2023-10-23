#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char password[100];

    scanf("%s", password);

    int required_characters = 6;
    int missing_count = 0;

    // char numbers[] = "0123456789";
    // char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
    // char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // char special_characters[] = "!@#$%^&*()-+";

    int mychar = 0;
    bool isValid = false;
    int isKapital = 0, isKecil = 0, isNomor = 0, isChar = 1;
    for (int i = 0; i < strlen(password); i++)
    {
        mychar++;
        if (isupper(password[i]))
        {
            isValid = true;
        }
        else
        {
            isKapital = 1;
        }

        if (islower(password[i]))
        {
            isValid = true;
        }
        else
        {
            isKapital = 1;
        }

        if (isdigit(password[i]))
        {
            isValid = true;
            isNomor = 1;
        }
        else
        {
            isValid = true;
            isChar -= 1;
        }
    }

    printf("sebelum %d\n", mychar);
    if (!isValid && mychar >= required_characters )
    {
        printf("false\n");
        mychar = required_characters - mychar;
        mychar = isKapital + isChar + isNomor + isKecil;
    }
    else if (isValid && mychar >= required_characters )
    {
        printf("true\n");
        mychar = 0;
    }

    printf("%d\n", mychar);

    return 0;
}
