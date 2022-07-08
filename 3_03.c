#include <stdio.h>
int main()
{
    double x, y, a, b, c;
    scanf("%lf%lf", &x, &y);
    a = x * x + y * y;
    b = (x + y) * (x + y);
    c = (x - y) * (x - y);
    printf("%lf\n%lf\n%lf", a, b, c);
    return 0;
}
