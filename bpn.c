#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
int width=50,height=30,up=0,side=0;
int status=1;
char c;
void display(){
	int i,j;
	for(j=1;j<=height;j++){
		for(i=1;i<=width;i++){
		if(i==1 || i==width || j==1 || j==height){
			printf("#");
		}
                else if(i==(width/2)-1+side && j==(height/2)+up){
                        printf("b");
                }
		else if(i==(width/2)+side && j==(height/2)+up){
			printf("p");
		}
	        else if(i==(width/2)+1+side && j==(height/2)+up){
                        printf("n");
                }
		else{
			printf(" ");
		}
		}
		printf("\n");
	}
}

void shoot(){
	printf("\033[%d;%dH", (height/2)+up, (width/2)+side+2);
	for(int i=(width/2)+side;i<=width-3;i++){
        printf("-");
	}
	printf("\n");

}

void input(){
    struct termios old_termios, new_termios;
    tcgetattr(STDIN_FILENO, &old_termios); // Save current terminal attributes
    new_termios = old_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios); // Apply new terminal attributes
    c = getchar(); // Read a single character from the user
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios); // Restore original terminal attributes
if(c=='w'){
	up=up-1;
}
else if(c=='s'){
	up=up+1;
}
else if(c=='a'){
	side=side-1;
}
else if(c=='d'){
	side=side+1;
}
else if(c=='x'){
	shoot();
}


if(side>width/2){
	side=-(width/2);
}
else if(side<-(width/2)){
	side=width/2;
}
else if(up>height/2){
	up=-(height/2);
}
else if(up<-(height/2)){
	up=height/2;
}
}


void main(){
	while(status){
	display();
	input();
	//sleep(1);
	system("clear");
	}
}
