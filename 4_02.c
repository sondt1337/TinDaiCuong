#include <stdio.h>
int main ()
{
	int n, i, a=0; 
	scanf ("%d",&n); 
	if (n<=1) 
	    printf ("Khong phai so nguyen to");
	else{
	    for (i=2; i<n; i++) 
	        if (n%i==0)
	           a++;
	    if (a==0)
	        printf ("La so nguyen to"); 
	    else 
	        printf ("Khong phai so nguyen to");
	}
}
