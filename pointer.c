#include <stdio.h>
int main(){
int a,*b;
a=5;
b=&a;
a=a-*b;
printf("%d",a);
return 0;
}
