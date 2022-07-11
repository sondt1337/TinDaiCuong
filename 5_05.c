#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    int tong, a[n];
    if (n == 1)
        tong = 0;
    if (n >= 2 && n <= 10)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        tong = a[1] + a[0];
        for (i = 1; i < n - 1; i++)
        {
            if (a[i] + a[i + 1] > tong)
                tong = a[i] + a[i + 1];
        }
    }
    if (tong > 0)
        printf("%d", tong);
    else
        printf("%d", 0);
}
