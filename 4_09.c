#include <stdio.h>
#include <math.h>
int main()
{
    int n, i;
    float x, S = 0, m;
    scanf("%f%f", &x, &m);
    if (m == (int)m)
    {
        n = m;
        if (n < 1 || x <= 0)
            printf("Error");
        else
        {
            for (i = 1; i <= n; i++)
                S = sqrt(x + S);
            printf("%.4f", S);
        }
    }
    else
        printf("Error");
}
