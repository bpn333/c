#include<stdio.h>
int main(){
	int n,i,multi;
	printf("num:-");
	scanf("%d",&n);
	for(i=1;i<=10;i++)
	{
		multi=n*i;
		printf("%d*%d=%d\n",n,i,multi);
	}
}
