#include<stdio.h>
#include"conio.h"
#include<time.h>
int playery,defaultx=5,defaulty=20,jump_height=5,gameover=0,width=60,count=0,cap=1000,tiktik=0,inair=0,score=0;
char c;

struct obst{
	int x;
}obstacle[3];

void player(){
	gotoxy(defaultx,playery);
	printf("0");
	gotoxy(defaultx,defaulty+2);
}
char input(){
	if(kbhit()){
		c=getch();
		return c;
	}
	else
		return 0;
}

void logic(){
	char chr=input();
	if(chr==' ' && !inair){
		gotoxy(defaultx,playery);
		printf(" ");
		playery=playery-jump_height;
		inair=1;
	}
}

void gravity(){
	if(count>cap){
		gotoxy(defaultx,playery);
		printf(" ");
		playery=playery+1;
		count=0;
	}
	else
		count++;
}

void cactus(){
	if(tiktik>cap){
	for(int i=0;i<3;i++){
	gotoxy(obstacle[i].x,defaulty);
	printf("#");
	}
	for(int i=0;i<3;i++){
		gotoxy(obstacle[i].x+1,defaulty);
		printf(" ");
		gotoxy(obstacle[i].x-1,defaulty);
		printf(" ");
		obstacle[i].x=obstacle[i].x-1;
		if(obstacle[i].x==0){
			obstacle[i].x=width+30+rand()%10;
			score=score+1;
		}
	}
	for(int i=0;i<3;i++){
	if((defaultx==obstacle[i].x) && (playery==defaulty))
		gameover=1;
	}
	tiktik=0;
}
	else{
		if(inair)
			tiktik=tiktik+2;
		else
			tiktik++;
	}
}

void main(){
	obstacle[0].x=width+20;
	obstacle[1].x=width+40;
	obstacle[2].x=width+60;
	clrscr();
	for(int i=0;i<width;i++){
		gotoxy(i,defaulty+1);
		printf("_");
	}
	playery=defaulty;
	while(!gameover){
		srand(time(0));
		player();
		if(playery<defaulty)
			gravity();
		else
			inair=0;
		logic();
		cactus();
	}
	clrscr();
	printf("score=%d\n",score);
}
