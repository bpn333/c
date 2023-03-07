#include<stdio.h>
int yes();
void main(){
	int n,i,c;
k:
	printf("\tprime checker\n\n\n");
	c=0;
	printf("num:-");
	scanf("%d",&n);
	for(i=1;i<n;i++){
		if((n%i)==0){
			c=c+1;
		}
	}
	if(c==1 || n==1){
		printf("\n :) number is prime\n");
	}
	else{
		printf("\n :( number is not prime\n");
	}
if(yes()==1){
	goto k;
}
}
