# Writeups rev1.c - access denied CTF
Ở bài này chúng ta sẽ lưu ý 1 chút là đọc kĩ code và phân tích để có thể viết lại được code và ra flag
## file rev1.c 
```csharp=1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100
char flag[] = {-111, -47, -47, -79, -39, -39, 49, -79, 97, -127, -79, 49, -55, 9, 27, 89, -19, 59, 97, 49, -19, 89, -37, 121, -37, 89, -69, -37, -19, -111, 89, -37, -19, 113, -71, 97, -19, -101, 49, 49, 11, 91, -69, 11, -79, -87};

char reverse(char ch) {
    int x = 0;
    for(int i = 0; i < 8; i++) {
        x *= 2;
        if((ch & (1 << i))) {
            x++;
        }
    }
    return (char)x;
}

void encode(char str[]) {
    int xor = 23;
    for(int i = 0; str[i] != '\0'; i++) {
        str[i] = reverse(str[i]);
        str[i] = (char)(xor ^ str[i]);
    }
}

int main()
{
    
    char str[MAXSIZE];
    scanf("%100s", str);

    getchar();
    encode(str);
    if(strcmp(flag, str) == 0){
        printf("Access Granted :(");
    }
    else{
        printf("Access Denied :)");
    }
}
``` 
có thể thấy từ void `reverse` ta có 1 phần tử của flag (lấy trường hợp cụ thể là flag[0] ) khi chạy qua `reverse` sẽ tiếp tục chạy thêm vòng lặp gồm 8 loop (0 -->7) sẽ biến đổi:
- Ví dụ a (text) --> 01100001 (binary) và qua 8 lần so sánh với 00000001 (và các cách dịch chuyển sang trái 1 bit của nó) thì ta được biến x lúc này thành 
( ( ( ( 0 * 2 + 1 )* 2 * 2 * 2 * 2) * 2 + 1) * 2 + 1) * 2  = 134

và ngay cuối hàm ta thấy ép kiểu x sang `char` nên lúc này x mặc định để ta tính là: 10001100.

Tiếp theo từ việc `encode` flag (ta coi là đang encode 1 phần tử flag[0] ) ta thấy rằng trong hàm encode sẽ có reverse (bước trên đã làm) và biến đổi flag[0] lúc này bằng:
`xr ^ flag[0]` (đã được ép kiểu sang char và xr ở đây bằng 23(dec) --> 00010111(bin))

Chúng ta sẽ tiến hành in thử flag ra thì được 
`æ╤╤▒┘┘1▒aü▒1╔   φ;a1φY█y█Y╗█φæY█φq╣aφ¢11`
`[╗`
`▒⌐`

Mình nghĩ đây là flag đã được biến đổi giống như chúng ta encode và reverse `str`.

Thật vậy, mình với kinh nghiệm làm bài rsa-1 thì đã biết form của flag là `accessdenied{}` nên mình thử nhập str là `a` thêm `printf("%s", flag)` thì đều thu được đầu ra là 2 kí tự giống hệt nhau `æ æ`.

mình thử ẩn dòng `str[i] = (char)(xr ^ str[i]);` dưới comment và thêm thử hàm decode:
```csharp=1
void decode(char flag[]) {
    int i, xor = 23;
    for( i = 0; flag[i] != '\0'; i++) {
        str[i] = (char)(xor ^ flag[i]);
    }
}
```
đến đây flag và str vẫn giống nhau. nên mình nhận ra có điều gì đó chúng ta có thể rút gọn được

và mình để ý 1 chút ở số 134 ở bên trên thì đổi ra thành 01100001 và đúng bằng decode(flag[0]) được đảo ngược lại 

vậy nên mình nghĩ chỉ cần sử dụng hàm decode(flag) và đảo ngược lại nó là xong

### Viết lại code (viết lại bằng C)
```csharp=1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag[] = {-111, -47, -47, -79, -39, -39, 49, -79, 97, -127, -79, 49, -55, 9, 27, 89, -19, 59, 97, 49, -19, 89, -37, 121, -37, 89, -69, -37, -19, -111, 89, -37, -19, 113, -71, 97, -19, -101, 49, 49, 11, 91, -69, 11, -79, -87};
int main()
{
    int xr = 23, i;
    for (i = 0; flag[i] != '\0'; i++)
    {
        flag[i] = (int)(xr ^ flag[i]);
        if (flag[i] < 0)
            flag[i] = 256 + flag[i];
        //ở đây sẽ không thêm trường hợp của số dương vì mình thử thì thấy thế =))
        printf("%d, ", flag[i]);
    }
}
```
Kết quả in ra chuỗi các số nhị phân (ở đây có thể hiểu chính là flag dưới dạng nhị phân đã bị đảo ngược)

Kết quả sau khi viết lại chương trình ta thu được dãy các số nguyên được hiểu là sau khi đảo ngược của encode(flag) 

## Chuyển dãy số về số nhị phân
>mình sử dụng C++ cho đơn giản, còn nếu bạn nào muốn chạy từng số 1 có thể dùng tool

```csharp=1
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int flag[] = {134, 198, 198, 166, 206, 206, 38, 166, 118, 150, 166, 38, 222, 30, 12, 78, 250, 44, 118, 38, 250, 78, 204, 110, 204, 78, 172, 204, 250, 134, 78, 204, 250, 102, 174, 118, 250, 140, 38, 38, 28, 76, 172, 28, 166, 190};

void DecimalToBinary(int n) {
   int binaryNumber[100], num=n;
   int i = 0;
   while (n > 0) {
      binaryNumber[i] = n % 2;
      n = n / 2;
      i++;
   }
   int j;
   for (j = i - 1; j >= 0; j--)
   cout<<binaryNumber[j];
   cout<<" ";
}
int main()
{
    int i;
    for (i = 0; i < 46; i++)
    {
        DecimalToBinary(flag[i]);
    }
}
```
Sau khi chuyển dãy trên về số nhị phân ta thu được dãy nhị phân như sau:
`10000110 11000110 11000110 10100110 11001110 11001110 100110 10100110 1110110 10010110 10100110 100110 11011110 11110 1100 1001110 11111010 101100 1110110 100110 11111010 1001110 11001100 1101110 11001100 1001110 10101100 11001100 11111010 10000110 1001110 11001100 11111010 1100110 10101110 1110110 11111010 10001100 100110 100110 11100 1001100 10101100 11100 10100110 10111110`

ta để ý thêm cho các số nhị phân sao cho đủ 8bit để khi đổi chiều lại không bị lỗi

### Code đảo ngược các chuỗi binary để tìm ra flag
```csharp=1
#include<iostream>
using namespace std;
void str_reverse(char str[]) {
  int lo = 0;
  int length;
  for (length = 0; str[length] != '\0' ; length++) {} 
  while ( lo < length ) {
    --length;
    char tmp = str[lo];
    str[lo] = str[length];
    str[length] = tmp;
    ++lo;
  }
}

int main() {
    char str[100];
    int i =100;
    while (i  > 0) {
    cin >>  str;
    str_reverse(str);
    cout << str << " ";
    i--;}
    return 0;
}
```

Sau khi đã đảo ngược xong, ta thu được dãy `01100001 01100011 01100011 01100101 01110011 01110011 01100100 01100101 01101110 01101001 01100101 01100100 01111011 01111000 00110000 01110010 01011111 00110100 01101110 01100100 01011111 01110010 00110011 01110110 00110011 01110010 00110101 00110011 01011111 01100001 01110010 00110011 01011111 01100110 01110101 01101110 01011111 00110001 01100100 01100100 00111000 00110010 00110101 00111000 01100101 01111101`

Sử dụng trang [web này](https://www.rapidtables.com/convert/number/binary-to-ascii.html) để xử lý nốt phần còn lại và thu được flag.

#### Flag: accessdenied{x0r_4nd_r3v3r53_ar3_fun_1dd8258e}

