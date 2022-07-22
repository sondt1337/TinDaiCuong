#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    int i, count1 = 0, count2 = 0;
    scanf("%s", s);
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z') // kiem tra phan tu co phai la chu cai thuong khong --> neu co thi bien count1 tang 1 don vi
            count1++;
        if (s[i] >= 'A' && s[i] <= 'Z') // kiem tra phan tu co phai la chu cai hoa khong --> neu co thi bien count1 tang 1 don vi
            count1++;
        if (s[i] >= '0' && s[i] <= '9') // kiem tra phan tu co phai la so khong --> neu co thi tang bien count2 len 1 don vi
            count2++;
    }
    if (count1 == count2) // neu so chu cai bang so chu so
        printf("0");
    if (count1 > count2) // neu so chu cai nhieu hon so chu so
        printf("1");
    if (count1 < count2) // neu so chu cai it hon so chu so
        printf("2");
}
