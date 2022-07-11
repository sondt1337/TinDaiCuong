#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    int tich, a[n];
    if (n == 1)
        tich = 0;
    if (n >= 2 && n <= 10)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        tich = a[1] * a[0];
        for (i = 1; i < n - 1; i++)
        {
            if (a[i] * a[i + 1] > tich)
                tich = a[i] * a[i + 1];
        }
    }
    if (tich > 0)
        printf("%d", tich);
    else
        printf("%d", 0);
}
