#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char s[100];
    int i, chuyendoi = 0;
    scanf("%s", s);

    // ap dung cong thuc bien doi so nhi phan co dau
    // co so 1 o dau --> tru di 2^x (x la so bit) [neu la 0 thi khong can lam gi]
    if (s[0] == '1')
        chuyendoi -= pow(2, strlen(s) - 1);

    for (i = 1; i < strlen(s); i++)
    {
        if (s[i] == '1')
            chuyendoi += pow(2, strlen(s) - i - 1);
        // tu bit thu 2 tro di cong theo cong thuc thong thuong a_(x-1)*2^(x-1) + a_(x-2)*2^(x-2) + ... + a_0*2^0
    }
    
    printf("%d", chuyendoi); // in ra so sau khi da chuyen tu binary (co dau) ve so nguyen
}
