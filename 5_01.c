#include <stdio.h>
int main()
{
    int n, i, tong = 0;
    int a[100];
    scanf("%d", &n);
    if (n <= 0)
        printf("Error");
    else
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            tong += a[i];
        }
        for (i = n - 1; i >= 0; i--)
            printf("%d ", a[i]);
        printf("\n");
        printf("%d", tong);
    }
}
