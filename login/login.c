#include<stdio.h>
int check();
void changepass();
char u[30],p[30],username[30],password[30];
int count=1;
void main(){
	printf("\tfacebook\n");
in:
	printf("username:-");
	scanf("%s",u);
	printf("password:-");
	scanf("%s",p);
	if(check()){
		printf("sucess\n");
	}
	else{
		printf("failed\n");
			goto in;
		}
	}

int check(){
	FILE *fp;
	char a[30][30],c,user[30];
	int i=1;
	fp=fopen("data.txt","r");
	while(fscanf(fp,"%s",a[i])!=EOF){
		i=i+1;
	}
	strcpy(username,a[3]);
	strcpy(password,a[6]);
	if((strcmp(u,username)!=0) || (strcmp(p,password)!=0)){
		if(count<3){
                        count=count+1;
			return 0;
                }
                else{
                        printf("forgot password");
                        printf("\n[y/n]:-");
                        scanf(" %c",&c);
                        if(c=='y'){
x:
                                printf("\nusername=");
				scanf("%s",user);
				if(strcmp(user,username)!=0){
					printf("wrong username\n");
					goto x;
				}
				else{
					changepass();
					return 1;
				}
                        }
			else{
				return 0;
			}
        }
	
	}
	else{
		return 1;
	}
	fclose(fp);
}

void changepass(){
	char pass1[30],pass2[30];
	FILE *cp;
t:
	printf("new password:-");
	scanf("%s",pass1);
	printf("re-enter:-");
	scanf("%s",pass2);
	if(strcmp(pass1,pass2)!=0){
		printf("INCORRECT\n");
		goto t;
	}
	else{
		cp=fopen("data.txt","w");
		fprintf(cp,"username = %s\npassword = %s\n",username,pass2);
		fclose(cp);
	}
}
