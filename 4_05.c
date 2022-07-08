#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, delta;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (a == 0)
    {
        if (b == 0 && c == 0)
            printf("Phuong trinh vo so nghiem");
        if (b == 0 && c != 0)
            printf("Phuong trinh vo nghiem");
        if (b != 0)
            printf("%lf", -c / b);
    }
    else
    {
        delta = b * b - 4 * a * c;
        if (delta == 0)
            printf("%lf", -b / (2 * a));
        if (delta > 0)
        {
            printf("%lf\n", (-b + sqrt(delta)) / (2 * a));
            printf("%lf", (-b - sqrt(delta)) / (2 * a));
        }
        if (delta < 0)
        {
            printf("%lf+%lfi\n", -b / (2 * a), sqrt(-delta) / (2 * a));
            printf("%lf-%lfi", -b / (2 * a), sqrt(-delta) / (2 * a));
        }
    }
}
