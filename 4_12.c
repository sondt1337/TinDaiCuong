#include <stdio.h>
#include <math.h>
long giaithua(int n)
{
    if (n > 0)
        return n * giaithua(n - 1);
    else
        return 1;
}
int main()
{
    double x, S3 = 0, T, m;
    int n;
    scanf("%lf%lf", &x, &m);
    if (m == (int)m && m > 0 && x >= 0)
    {
        n = m;
        while (n > 0)
        {
            T = pow(x, n);
            if (n % 2 == 0)
                S3 += T / giaithua(n);
            else
                S3 -= T / giaithua(n);
            n--;
        }
        printf("%.4lf", S3 + 1);
    }
    else
        printf("Error");
}
