#include<stdio.h>
void main(){
	int a,b;
	scanf("%d",&a);
	printf("\n%d\n",a>0);
	b=(a>0)?1:0;
	printf("\n%d\n",b);
	(a>0)?printf("op\n"):printf("\n");
}
