#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "conio.h"

const int width=50,height=30;
char screen[50][30];
int gameover=0;
int playerx,playery;

void initialize(){
        for(int j=0;j<height;j++){
                for(int i=0;i<width;i++){
                        if(i==0 || j==0 || i==width-1 || j==height-1)
                                screen[i][j]='#';
                        else if(i==playerx && j==playery)
                                screen[i][j]='0';
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
        if(c=='w')
                playery=playery-1;
        else if(c=='s')
                playery=playery+1;
        else if(c=='a')
                playerx=playerx-1;
        else if(c=='d')
                playerx=playerx+1;
        else if(c=='q')
                gameover=1;
}

void main(){
        playerx=width/2;
        playery=height/2;
        system("clear");
        while(!gameover){
                initialize();
                display();
                logic();
                //sleep(1);
                system("clear");
        }
}
