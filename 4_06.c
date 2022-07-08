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
    double x, S1 = 0, T, m;
    int n;
    scanf("%lf%lf", &m, &x);
    if (m == (int)m && m > 0)
    {
        n = m;
        while (n > 0)
        {
            T = pow(x, n);
            S1 += T;
            n--;
        }
        printf("%lf", S1 + 1);
    }
    else
        printf("Error");
}
