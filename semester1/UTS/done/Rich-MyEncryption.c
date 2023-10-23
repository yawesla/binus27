#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);
    // printf("%d",'0');

    for (int i = 0; i < tc; i++) {
        char string[501];
        scanf("%s", string);

        int length = strlen(string);
        for (int j = 0; j < length; j++) {
            if ((string[j] >= 'a' && string[j] <= 'w') || (string[j] >= 'A' && string[j] <= 'W') || (string[j] >= '0' && string[j] <= '6')) {
                string[j] += 3;
            } else if (string[j] >= 'x' && string[j] <= 'z') {
                string[j] = (string[j] - 'w') + 64;
            } else if (string[j] >= 'X' && string[j] <= 'Z') {
                string[j] = (string[j] - 'W') + 47;
            } else if (string[j] >= '7' && string[j] <= '9') {
                string[j] = (string[j] - '6') + 96;
            }
        }
        
        printf("Case #%d: ", i + 1);
        for (int j = 0; j < length; j++) {
            printf("%c", string[j]);
        }
        printf("\n");
    }
    
    return 0;
}