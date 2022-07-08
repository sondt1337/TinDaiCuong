#include <stdio.h>
int main()
{
    double toan, ly, hoa, tong;
    scanf("%lf%lf%lf", &toan, &ly, &hoa);
    tong = toan + ly + hoa;
    printf("%lf\n%lf", tong, tong/3.0);
    return 0;
}
