#include<stdio.h>
void main(){
	int c;
k:
	printf("**welcome to database**\n");
	printf("\n\n1.write\n2.read");
	printf("\n\nchoice:-");
	scanf("%d",&c);
	switch(c){
		case 1:
		save();
		break;

		case 2:
		read();
		break;

		default:
		printf("TRY AGAIN\n\n\n");
		goto k;
	}
}




void save(){
        int i,n;
	FILE *fp;
	fp=fopen("data.txt","a");
        printf("\nnum:-");
        scanf("%d",&n);
        struct stu{
                int roll;
                char name[10];
                char address[10];
        }std[n];
        for(i=1;i<=n;i++){
                printf("\n%d.roll:-",i);
                scanf("%d",&std[i].roll);
                printf("%d.name:-",i);
                scanf("%s",std[i].name);
                printf("%d.address:-",i);
                scanf("%s",std[i].address);
        }
        for(i=1;i<=n;i++){
                fprintf(fp,"\t***DATA***");
                fprintf(fp,"\n%d.roll:-%d",i,std[i].roll);                     
		fprintf(fp,"\n%d.name:-%s",i,std[i].name);
                fprintf(fp,"\n%d.address:-%s",i,std[i].address);
        }
	fclose(fp);
}
