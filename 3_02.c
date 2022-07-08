#include <stdio.h>
#define p 3.14159
int main() {
    double r, M, S;
    scanf("%lf", &r);
    if (r <= 0)
        printf("ERROR");
    else {
        M = 2 * p * r;
        S = p * r * r;
        printf("%lf\n%lf", M, S);
    }
    return 0;
}
