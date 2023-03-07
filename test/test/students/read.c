#include <stdio.h>
int main(){
int i=0,n;
char r[10],s[100][10];
FILE *fp;
fp=fopen("data.txt","r");
printf("roll :");
scanf("%s",r);
while(fscanf(fp,"%s",s[i])!=EOF){
i=i+1;
}
n=i;
for(i=0;i<n;i++){
if(strcmp(s[i],r)==0){
printf("\n\n%s %s %s\n%s %s %s\n%s %s %s\n",s[i-5],s[i-4],s[i-3],s[i-2],s[i-1],s[i],s[i+1],s[i+2],s[i+3]);
}
}
fclose(fp);
return 0;
}
