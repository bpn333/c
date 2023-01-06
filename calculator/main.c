#include <stdio.h>
int sum(int ,int );
int diff(int ,int );
int mul(int ,int );
int div(int ,int );
int main(){
int a,b;
printf("num :");
scanf("%d",&a);
printf("num :");
scanf("%d",&b);
printf("\n----------------\n");
printf("sum :%d\n",sum(a,b));
printf("diff :%d\n",diff(a,b));
printf("mul :%d\n",mul(a,b));
printf("div :%d\n",div(a,b));
return 0;
}
