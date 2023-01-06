#include <stdio.h>
#include <string.h>
char s[1000][10],movie[1000][10];
int i=0,r,j,k,n[1000];
k=1;
r=1;
int main(){
FILE *fp;
fp = fopen("1.txt","r");
while (fscanf(fp,"%s",s[i])!=EOF){
i=i+1;
}
while (fscanf(fp,"%d",&n[k])!=EOF){
k=k+1;
}
for(j=0;j<i;j++){
if(strcmp(s[j],"movie")==0){
strcpy(movie[r],s[j+2]);
r=r+1;
}
}
printf("%s",movie[1]);
printf("%d",n[6]);
return 0;
}
