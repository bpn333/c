#include <stdio.h>
int main()
{
int n,i,j,p,k,a,b;
printf("num :");
scanf("%d",&n);
c:
printf("\nchoose a pattern \n1.lower base\n2.upper base\n3.pyramid\nchoice :");
scanf("%d",&p);
printf("\n\n\n");

//lower base triangle
if(p==1)
{
for(i=1;i<=n;i++)
{
for(j=1;j<=i;j++)
{
printf("*");
}
printf("\n");
}
}

//upper base triangle
else if(p==2)
{
for(i=n;i>=1;i--)
{
for(j=i;j>=1;j--)
{
printf("*");
}
printf("\n");
}
}

//pyramid
else if(p==3)
{
a=0;
b=n;
for(i=1;i<=n;i++)
{
for(k=1;k<=b;k++)
{
printf(" ");
}
for(j=1;j<=i+a;j++)
{
printf("*");
}
printf("\n");
b=b-1;
a=a+1;
}
}

//wrong choice
else
{
printf("------------try again----------");
goto c;
}
return 0;
}
