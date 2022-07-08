#include <stdio.h>
int main()
{
    float gkt, cn, t;
    scanf("%f%f%f", &gkt, &cn, &t);
    printf("%f", gkt*cn + gkt*cn*t/100.0);
    return 0;
}
