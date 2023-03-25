#include<stdio.h>
#include<stdlib.h>
#include "conio.h"
#include<time.h>

const int width=50,height=30,cap=13;
char screen[50][30];
int gameover=0,count=0,path=1,score=0;
int playerx,playery,pathx,pathy;

void initialize(){
        for(int j=0;j<height;j++){
                for(int i=0;i<width;i++){
                        if(i==0 || j==0 || i==width-1 || j==height-1)
                                screen[i][j]='#';
                        else if(i==playerx && j==playery)
                                screen[i][j]='0';
                        else if(path && (pathx-i)<3 && (i-pathx)<3)
                                if((pathy-j)<3 && (j-pathy)<3)
                                        screen[i][j]=' ';
                                else
                                        screen[i][j]='|';
                        else
                                screen[i][j]=' ';
                }
        }
}

void display(){
        for(int j=0;j<height;j++){
                for(int i=0;i<width;i++){
                        printf("%c",screen[i][j]);
                }
            printf("\n");
        }
        printf("score=%d\n",score);
}

char input(){
        char c;
        if(kbhit()){
                c=getch();
                return c;
        }
        else
                return 0;
}

void logic(){
        char c=input();
        if(c==' ')
                playery=playery-2;
        else if(c=='q')
                gameover=1;

        if(path && (pathx-playerx)<3 && (playerx-pathx)<3){
                if(!((pathy-playery)<3 && (playery-pathy)<3))
                        gameover=1;
        }

        if(pathx<0){
                path=1;
                score=score+1;
                pathx=width;
                if(rand()%2==0)
                     pathy=playery + rand() % 5;
                else
                         pathy=playery - rand() % 5;
                if(pathy<0 || pathy>height)
                        pathy=height/2;
        }
        if(playery>height || playery<0)
                gameover=1;

}

void gravity(){
        playery=playery+1;
        pathx=pathx-5;
}

void main(){
        playerx=width/4;
        playery=height/2;
        pathx=width-5;
        pathy=height/2;
        while(!gameover){
                srand(time(0));
                system("clear");
                initialize();
                display();
                logic();
                if(count>cap){
                        gravity();
                        count=0;
                }
                else
                        count++;
        }
        system("clear");
        printf("score=%d\n",score);
        getch();
}
