#include <stdio.h>
#include <math.h>
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
            S3 = S3 + T / n;
            n--;
        }
        printf("%.4lf", S3 + 1);
    }
    else
        printf("Error");
}
