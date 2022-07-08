#include <stdio.h>
int main()
{
    int a, b, min;
    scanf("%d%d", &a, &b);
    if (a >= b)
        min = b;
    else
        min = a;
    while (min >= 1)
    {
        if (a % min == 0 && b % min == 0)
            break;
        min--;
    }
    if (min <= 0)
        printf("ERROR");
    else
    {
        printf("%d\n", min);
        printf("%d", a * b / min);
    }
}
