#include <stdio.h>
#include <math.h>
int main ()
{
    double x,y,F; //Khai bao cac bien
    scanf("%lf",&x);//Nhap x
    scanf("%lf",&y);//Nhap y
    //F=Y^6+X×Y^5+X^2×Y^4+X^3×Y^3+X^4×Y^2+X^5×Y+X^6
    F=pow(y,6)+x*pow(y,5)+pow(x,2)*pow(y,4)+pow(x,3)*pow(y,3)+pow(x,4)*pow(y,2)+pow(x,5)*y+pow(x,6);
    printf("%6lf",F);//In ra gia tri F
}
