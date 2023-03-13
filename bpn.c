#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<time.h>
int width=50,height=30,up=0,side=0;
int status=1,enemy_alive=1,enemyx=50,enemyy=15,count=0,score=0,enemy_health=100;
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
		else if(i==enemyx && j==enemyy){
			if(enemy_alive && enemy_health==200)
				printf("B");
			else if(enemy_alive && enemy_health==150)
				printf("@");
			else if(enemy_alive && enemy_health==100)
				printf("0");
			else if(enemy_alive && enemy_health==50)
				printf(".");
			else
				printf(" ");
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
	if (((height/2)+up)==enemyy && enemyx>((width/2)+side)){
		enemy_health=enemy_health-50;
		if(enemy_health<1){
		enemy_alive=0;
		score=score+1;
		}
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

void enemy(){
	if(enemy_alive)
		enemyx=enemyx-1;
	else
		count=count+1;
	if(count>3){
		count=0;
		enemyx=50;
		enemyy=rand() % 28;
		enemy_alive=1;
		if((rand() % 100) < 20)
			enemy_health=50;
		else if((rand() % 100) < 80)
			enemy_health=100;
		else if((rand() % 100) < 95)
			enemy_health=150;
		else
			enemy_health=200;
		if(enemyy==1)
			enemyy=2;
		else if(enemyy==height)
			enemyy=height-1;
	}

	if(enemyx==0){
		status=0;
	}
}

void main(){
	while(status){
	srand(time(0));
	system("clear");
	display();
	input();
	enemy();
	//sleep(1);
	}
	system("clear");
	printf(":( gameover\nscore=%d\n",score);
}
