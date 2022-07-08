#include <stdio.h>
int main ()
{
	int n, i, s=1;
	scanf ("%d",&n);
    if (n<0||n>=8)
       printf ("ERROR"); 
	else
	   {
	       for (i=1; i<=n; i++)
		       s=s*i;
	       printf ("%d",s);
	   }
}
