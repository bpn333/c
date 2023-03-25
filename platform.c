#include<stdio.h>
#include<stdlib.h>
#include "conio.h"

const int width=50,height=30,jump_height=5,cap=300;
int gameover=0,count=0;
struct plr{
	int x;
	int y;
}player;

struct level_platform{
	int a1,a2,a3;
}platform;

void level1(){
	platform.a1=height;
	platform.a2=height-10;
	platform.a3=height-15;
	for(int i=0;i<=width;i++){
		gotoxy(i,platform.a1);
		printf("-");
		if(i>width/2){
		gotoxy(i,platform.a2);
		printf("_");
		}
		else{
		gotoxy(i,platform.a3);
		printf("=");
		}
	}
}

void character(){
	gotoxy(player.x,player.y);
	printf("0");
	gotoxy(0,height+1);
}

char input(){
	char c;
	if(kbhit()){
		c=getch();
	}
	else
		return 0;
}

void logic(){
	char c=input();
	if(c==' '){
		gotoxy(player.x,player.y);
		printf(" ");
		player.y=player.y-jump_height;
	}
	else if(c=='a'){
		gotoxy(player.x,player.y);
		printf(" ");
		player.x=player.x-1;
	}
	else if(c=='d'){
		gotoxy(player.x,player.y);
		printf(" ");
		player.x=player.x+1;
	}
	else if(c=='q'){
		gotoxy(player.x,player.y);
		printf(" ");
		gameover=1;
	}

	if(player.x>width){
		player.x=0;
	}
	else if(player.x<0){
		player.x=width;
	}
	if(player.y>height){
		player.y=0;
	}
	else if(player.y<0){
		player.y=height;
	}
}
void gravity(){
	if((player.x<=width/2) && player.y<platform.a3-1){
		gotoxy(player.x,player.y);
		printf(" ");
		player.y=player.y+1;
	}
	else if(!(player.y==platform.a3-1 && player.x<=width/2) && (player.x>width/2) && player.y<(platform.a2-1)){
		gotoxy(player.x,player.y);
		printf(" ");
		player.y=player.y+1;
	}
	else if(!(player.y==platform.a3-1 && player.x<=width/2) && !(player.y==platform.a2-1 && player.x>width/2) && player.y<(platform.a1-1)){
		gotoxy(player.x,player.y);
		printf(" ");
		player.y=player.y+1;
	}
}


void main(){
	player.x=width/2;
	player.y=height/2;
	clrscr();
	level1();
	while(!gameover){
		character();
		logic();
		if(count>cap){
		    gravity();
			count=0;
		}
		else
			count++;

	}
	clrscr();
}
