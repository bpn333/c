#include<stdio.h>
#include"conio.h"
#include<time.h>
int playery,defaultx=5,defaulty=20,jump_height=3,gameover=0,width=60,cap=300,inair=0,score=0,jumping=0,shooting=0,ammox,ammoy;
char c,enemy='#',character='0',ground='-',sun='.',ammo='-';

struct cou{
	int gravity;
	int cactus;
	int jump;
	int shoot;
	int ammo;  //ammo numbers
}count;

struct obst{
	int x;
}obstacle[3];

void base(){
	/*i am trying to make a moon/sun*/
	gotoxy(width/2,defaulty/4);
	printf("%c%c%c",sun,sun,sun);
	gotoxy(width/2-1,defaulty/4+1);
	printf("%c   %c",sun,sun);
	gotoxy(width/2-1,defaulty/4+2);
	printf("%c   %c",sun,sun);
	gotoxy(width/2,defaulty/4+3);
	printf("%c%c%c",sun,sun,sun);
    //ground
	for(int i=0;i<width;i++){
		gotoxy(i,defaulty+1);
		printf("%c",ground);
	}

}

void player(){
	gotoxy(defaultx,playery);
	printf("%c",character);
	gotoxy(defaultx+2,defaulty+2);
	if(jumping && count.jump>cap){
	if((playery+jump_height)!=defaulty){
		gotoxy(defaultx,playery);
		printf(" ");
		playery=playery-1;
	}
	else{
		jumping=0;
		inair=1;
	}
	count.jump=0;
	}
	else
		count.jump++;
}

void shoot(){
	int tmp;
		gotoxy(ammox,ammoy);
		printf("%c",ammo);
	if(count.shoot>cap/8){
			if(ammox>width){
				shooting=0;
				gotoxy(ammox,ammoy);
				printf(" ");
			}
			if((ammox==obstacle[0].x) && ammoy==defaulty){
				gotoxy(ammox-1,ammoy);
				printf(" ");
				gotoxy(ammox,ammoy);
				printf(" ");
				gotoxy(ammox+1,ammoy);
				printf(" ");
				tmp=obstacle[0].x;
				obstacle[0].x=obstacle[1].x;
				obstacle[1].x=obstacle[2].x;
				obstacle[2].x=tmp;
				obstacle[2].x=width+rand()%10;
				score=score+1;
				shooting=0;
			}
			else if(shooting){
				gotoxy(ammox,ammoy);
				printf(" ");
				ammox=ammox+1;
			}
	count.shoot=0;
	}

	else{
		count.shoot++;
	}
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
	if(chr==' ' && !jumping && !inair){
		jumping=1;
	}
	if(chr=='x' && !shooting && count.ammo){
		ammox=defaultx+1;
		ammoy=playery;
		shooting=1;
		count.ammo--;
	}
}

void gravity(){
	if(playery!=defaulty){
	if(count.gravity>cap){
		gotoxy(defaultx,playery);
		printf(" ");
		playery=playery+1;
		count.gravity=0;
	}
	else
		count.gravity++;
}
else
inair=0;
}

void rearrange(){
	int i,j,tmp;
	for(i=0;i<3;i++){
		for(j=i+1;j<3;j++){
			if(obstacle[i].x>obstacle[j].x){
				tmp=obstacle[i].x;
				obstacle[i].x=obstacle[j].x;
				obstacle[j].x=tmp;
			}
		}
	}
}


void cactus(){
	int tmp;
	if((defaultx==obstacle[0].x) && (playery==defaulty))
		gameover=1;
	if(obstacle[0].x==0){
		tmp=obstacle[0].x;
		obstacle[0].x=obstacle[1].x;
		obstacle[1].x=obstacle[2].x;
		obstacle[2].x=tmp;
		obstacle[2].x=width+rand()%10;
		score=score+1;
	}
	if(count.cactus>cap){
	for(int i=0;i<3;i++){
	if(!(obstacle[i].x>width)){
	gotoxy(obstacle[i].x,defaulty);
	printf("%c",enemy);
	}
	}
	for(int i=0;i<3;i++){
		gotoxy(obstacle[i].x+1,defaulty);
		printf(" ");
		gotoxy(obstacle[i].x-1,defaulty);
		printf(" ");
		obstacle[i].x=obstacle[i].x-1;
	}
	count.cactus=0;
}
	else{
		if(inair || jumping)
			count.cactus=count.cactus+2;
		else
			count.cactus++;
	}
}

void main(){
	obstacle[0].x=width+20;
	obstacle[1].x=width+40;
	obstacle[2].x=width+60;
	clrscr();
	base();
	playery=defaulty;
	while(!gameover){
		srand(time(0));
		player();
		if(inair)
			gravity();
		logic();
		cactus();
		if(score!=0 && score%31==10 && ground!='='){
			//night theme
			ground='=';
			enemy='+';
			sun=' ';
			character='0';
			ammo='-';
			base();
			count.ammo=count.ammo+score/3;
		}
		else if(score!=0 && score%31==20 && ground!='*'){
			//crazy ass
			ground='*';
			enemy='8';
			character='0';
			sun='+';
			ammo='-';
			base();
			count.ammo=count.ammo+score/3;
		}
		else if(score!=0 && score%31==30 && ground!='_'){
			//op alien theme
			ground='_';
			enemy='@';
			character='$';
			sun='o';
			ammo='>';
			base();
			count.ammo=count.ammo+score/3;
		}
		rearrange();
		if(shooting){
			shoot();
		}

		gotoxy(0,defaulty/2);
		printf("ammo=%d  ",count.ammo);
		gotoxy(0,defaulty+2);
		printf("score=%d",score);
	}
	clrscr();
	printf("score=%d\n",score);
}
