#include <stdio.h>
int main()
{
    int n, g = 0, h = 0, i;
    double tong1 = 0, tong2 = 0;
    scanf("%d", &n);
    int a[100];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            g++;
            tong1 += a[i];
        }
        if (a[i] < 0)
        {
            h++;
            tong2 += a[i];
        }
    }
    if (g == 0)
        printf("%lf Mang khong co so duong ", tong2 / h);
    else
        if (h == 0)
            printf("Mang khong co so am %lf", tong1);
        else
            printf("%lf %lf", tong2 / h, tong1);
}
