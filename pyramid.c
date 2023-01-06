#include <stdio.h>
void main()
{
int i,j,k,n,a;
n=5;
a=0;
for(i=1;i<=5;i++)
{
for(k=1;k<=n;k++)
{
printf(" ");
}
for(j=1;j<=i+a;j++)
{
printf("*");
}
printf("\n");
n=n-1;
a=a+1;
}
}
