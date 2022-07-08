#include <stdio.h>
int main()
{
    int n, a = 0, b = 0;
    scanf("%d", &n);
    if (n >= 1000)
        printf("ERROR");
    else
    {
        if (n < 10)
            printf("%d", n);
        else
        {
            while ((n / 100) >= 1)
            {
                a = n / 100;
                n %= 100;
            }
            while ((n / 10) >= 1)
            {
                b = n / 10;
                n %= 10;
            }
            printf("%d", a + b + n);
        }
    }
}
