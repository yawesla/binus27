#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{

    int tc;
    scanf("%d", &tc);

    int uang, persentase, durasi;
    for (int t = 1; t <= tc; t++)
    {
        scanf("%d %d %d", &uang, &persentase, &durasi);

        printf("Case #%d:\n",t);

        for (int i = 1; i <= durasi; i++)
        {
            int bunga = uang * persentase /100.0 / 12.0  * 80/100;
            int tabungan = uang + bunga;
            uang = tabungan;
            printf("%d %d\n", i, tabungan);
        }
    }
    return 0;
}