#include <stdio.h>
#include <string.h>
int main()
{
    char str[100], flag[100]; // chuoi str de nhap vao, chuoi flag de xuat ra
    int i, j = 0, k = 0;
    fgets(str, 100, stdin); // nhap cuoi str
    while (str[k] == ' ')   // neu gap dau cach ngay phan tu dau tien
        k++;                // tang k den khi khong gap dau cach nao nua --> phan tu bat dau luc nay se la s[k]
    for (i = k; i < strlen(str); i++)
    {

        if (str[i] == ' ') // neu gap phan tu la dau cach
        {
            while (str[i + 1] == ' ') // kiem tra cac phan tu tiep theo co la dau cach khong
                i++;                  // neu co thi tang i len --> phan tu tiep theo se la flag[j] = str[i]
        }
        flag[j] = str[i];
        j++;
    }
    puts(flag); // in ra flag
}
