#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    int a[t], b[t], c[t];
    
    for(int i = 0; i < t; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }

    for (int j = 0; j < t; j++) {
        if (b[j] + c[j] < a[j]) {
            printf("Case #%d: no\n", j+1);
        } else {
            printf("Case #%d: yes\n", j+1
            );
        }
    }

    return 0;
}