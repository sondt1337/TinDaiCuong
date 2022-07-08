#include <stdio.h>
#include <math.h>
int main()
{
    double x, y, z, ketqua, a;
    scanf("%lf%lf%lf", &x, &y, &z);
    a = z * cos(y);
    if (x >= a)
        ketqua = ((x + y + z) / (x * x + y * y + 1)) - (x - (z * cos(y)));
    else
        ketqua = ((x + y + z) / (x * x + y * y + 1)) - ((z * cos(y)) - x);
    printf("%lf", ketqua);
    return 0;
}
