#include <stdio.h>
#include <string.h>
#define SIZE 256
int main()
{
    char str1[100], str2[100];
    scanf("%s\n%s", str1, str2); // nhap 2 chuoi
    int COUNT[SIZE] = {0};       // dat bien dem ban dau bang 0, moi bien dem tuong ung 1 chu cai
    int len = strlen(str1), i;

    strcat(str1, str2); // gan chuoi str1 vao voi str2 --> luc nay se thanh 1 chuoi `str1`
    for (i = 0; i < len; i++)
        COUNT[(int)(str1[i])]++; // ep kieu str1[i] sang int, voi moi str[i], COUNT tang 1 don vi

    for (i = 0; i < SIZE; i++)
        if (COUNT[i]) // neu COUNT[i] khac 0 (cu the o day la > 0)
            printf("%c", (char)(i)); //in ra phan tu do 

    printf("\n"); // xuong dong

    for (i = 0; i < SIZE; i++)
        if (COUNT[i]) // neu chu so do xuat hien it nhat 1 lan 
            printf("%-3d\n", COUNT[i]); // thi in ra so lan xuat hien
    return 0;
}
