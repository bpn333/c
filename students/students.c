#include <stdio.h>
int main(){
int i,n;
printf("students :");
scanf("%d",&n);
struct stu{
char name[10];
int roll;
char address[10];
}st[n];
FILE *fp;
fp=fopen("data.txt","a");
printf("\nfill students details :-");
fprintf(fp,"\n\nstudents details :-");
for(i=1;i<=n;i++)
{
printf("\n%d.name :",i);
scanf("%s",st[i].name);
printf("\n%d.roll :",i);
scanf("%d",&st[i].roll);
printf("\n%d.address :",i);
scanf("%s",st[i].address);
}
for(i=1;i<=n;i++)
{
fprintf(fp,"\n\nname : %s\nroll : %d\naddress : %s",st[i].name,st[i].roll,st[i].address);
}
fprintf(fp,"\n\n..................\n\n");
fclose(fp);
return 0;
}
