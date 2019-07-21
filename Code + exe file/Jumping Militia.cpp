#include<bits/stdc++.h>
#include<iostream>
#include "graphics.h"
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include<windows.h>
using namespace std;
int store_x_rectangle,circle_x,store_y_rectangle,store_y_circle,k,maxx,maxy,temp,rectangle_x,head,feet,score,s,l,z,speed=17,r,m;
clock_t start,stop;
int d,level_controlar = 0,circle_y,a=5,i=0,j,t,f,p,rectangle_y;
char ch;
char c;
int life=99;
bool on_crouch=false;
bool pause=false;
bool su_n=true;
bool moo_n=true;
bool circl_e=false;
bool rectangl_e=true;
bool crouc_h=false;
void night_ground_generate();
void moon();
void sun();
void crouch();
void main_a();
void circle_check();
void initial_militia_generate();
void bar_ground_generate();
bool on_jump=false;
bool jump=false;
void End();
void check();
void ground_generate();
void bar_obstacle_generate();
void rectangular_obstacle_generate();
void circular_obstacle();
void militia_generate();
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"..\bgi");
    setcolor(3);
    settextstyle(4,0,4);
    outtextxy(30,2," Project-2: Jumping Militia");
    settextstyle(6,0,2);
    setcolor(WHITE);
    outtextxy(00,80," Submitted by:");
    outtextxy(20,180,"Nahiyan Nasrah ");
    outtextxy(20,200,"Registration No: 2016831012");
    outtextxy(20,140,"Mohammed Raihan Ullah");
    outtextxy(20,160,"Registration No: 2016831009");
    outtextxy(00,280," Submitted to: ");
    outtextxy(20,320,"Asif Mohammed Samir Sir ");
    outtextxy(20,340,"Assistant Professor");
    outtextxy(20,360,"IICT,SUST");
    ch=getch();
    cleardevice();
    main_a();
}
void main_a()
{
while(1)
{
delay(10);
setcolor(rand()%9);
settextstyle(4,0,6);
outtextxy(100,80," JUMPING");
outtextxy(100,160," MILITIA");
settextstyle(6,0,2);
setcolor(WHITE);
outtextxy(20,320," PRESS ENTER TO PLAY");

if(kbhit())
{
    ch=getch();
    if(ch==13)
        break;
}
}
az:
cleardevice();
setcolor(YELLOW);
settextstyle(3,0,4);
outtextxy(150,100,"PLAY[P]");
outtextxy(150,160,"LEVEL[L]");
outtextxy(150,220,"LOAD GAME[G]");
outtextxy(150,280,"HIGHSCORE[H]");
outtextxy(150,340,"INSTRUCTION[I]");
c=getch();
cleardevice();
if(c=='i')
{
    af:
    setcolor(WHITE);
    settextstyle(3,0,2);
    outtextxy(20,40,"==> Press [SPACE] key for jump");
    outtextxy(20,60,"==> Press [ENTER] key for crouch");
    outtextxy(20,80,"==> Press [P] key anytime for PAUSE");
    setcolor(YELLOW);
    outtextxy(20,120,"Caution:");
    setcolor(RED);
    outtextxy(20,160,"Don't HIT the obstacle");
    outtextxy(20,185,"Obstacle will reduce your health");
    outtextxy(20,210,"Use jump and crouch to avoid the obstacle");
    setcolor(WHITE);
    outtextxy(20,260,"Advice");
    setcolor(BLUE);
    outtextxy(20,300,"Try to survive as long as possible");
    setcolor(GREEN);
    outtextxy(10,370,"Back[B]");
    //outtextxy(10,400,"Play[Any Key]");
    c=getch();
    if(c=='b')
        goto az;
    else
        goto af;
}
else if(c=='h')
{
  freopen("HighScore.txt","r",stdin);
  cin>>d;
  printf("d: %d\n",d);
  fclose(stdin);
  char ar[100];
  ac:
  setcolor(RED);
  sprintf(ar,"HIGHSCORE: %d",d);
  outtextxy(150,200,ar);
  setcolor(WHITE);
  outtextxy(10,350,"Back[B]");
  //outtextxy(10,400,"Play[Any Key]");
  c=getch();
    if(c=='b')
        goto az;
    else
    goto ac;
}
else if(c=='g')
  {
    freopen("Score.txt","r",stdin);
    cin>>z>>l>>r;
    score=z;
    level_controlar=r;
    life=l;
    fclose(stdin);
    printf("%d %d",z,l);
  }
else if(c=='l')
{
    ap:
    setcolor(WHITE);
    settextstyle(3,0,4);
    outtextxy(100,150,"EASY[E]");
    setcolor(YELLOW);
    outtextxy(100,200,"MEDIUM[M]");
    setcolor(RED);
    outtextxy(100,250,"HARD[H]");
    setcolor(GREEN);
    settextstyle(3,0,2);
    outtextxy(10,350,"Back[B]");
    //outtextxy(10,400,"Play[Any Key]");
    c=getch();
    if(c=='e')
    {
    level_controlar=0;
    }
    else if(c=='m')
    {
    level_controlar=11;
    }
    else if(c=='h')
    {
    level_controlar=21;
    }
    else if(c=='b')
    {
        goto az;
    }
    else
        goto ap;
}
else if (c!='p')
{
    goto az;
}

cleardevice();//clear screen
maxx=getmaxx();//get the screen size
maxy=getmaxy();
circle_y=maxy-35;
start=clock();
rectangle_x=maxx;
f=maxy-20;
xy:
p=rand()%maxx;
rectangle_y=rand()%maxy;
if(rectangle_y<((maxy/2)-30))
    goto xy;
while(1)
{
if(level_controlar<3)
{
    setcolor(WHITE);
    settextstyle(3,0,2);
    outtextxy(120,150,"Tip:Press SPACE/ENTER for jump/crouch");
}
else
{
    setcolor(BLACK);
    settextstyle(3,0,2);
    outtextxy(120,150,"Tip:Press SPACE/ENTER for jump/crouch");

}
if(level_controlar<10)
   sun();
if(level_controlar>10 && level_controlar<20)
{
    if(moo_n)
    {
        setcolor(WHITE);
        settextstyle(3,0,2);
        outtextxy(200,170,"LEVEL UPGRADED");
        delay(800);
        cleardevice();
        moo_n=false;

    }
    moon();

}
if(level_controlar>20)
{
    if(su_n)
    {
        setcolor(WHITE);
        settextstyle(3,0,2);
        outtextxy(200,170,"LEVEL UPGRADED");
        delay(800);
        cleardevice();
        su_n=false;
    }
    sun();

}
if(level_controlar>20)
    speed=14;
head=circle_y-60;
feet=circle_y-5;
if(rectangle_x<20)
{
    level_controlar+=1;
    score+=1;


}
if(!crouc_h)
initial_militia_generate();
//Ground generator
if(level_controlar>10 && level_controlar<=20)
night_ground_generate();
else
    bar_ground_generate();
//Obstacle generator
if(rectangl_e)
{
rectangular_obstacle_generate();
if(level_controlar>10)
if(rectangle_x<=11)
{
rectangl_e=false;
circl_e=true;
}
}
if(circl_e)
{
circular_obstacle();
if(level_controlar>10)
if(rectangle_x<=11)
{
circl_e=false;
rectangl_e=true;
}
}
//taking command for jump

if(!crouc_h)
{
if(kbhit())
{
    ch=getch();
    if(ch==32)
        jump=true;
     if(ch==13 && !on_crouch)
     {
        on_crouch=true;
        crouc_h=true;
        a=20;
     }
     if(ch=='p')
        pause=true;


}
}
if(pause)
{
    pause=false;
    cleardevice();
    setcolor(WHITE);
    setcolor(RED);
    settextstyle(3,0,3);
    outtextxy(100,150,"SAVE GAME & EXIT [G]");
    outtextxy(100,200,"RESUME GAME [ANY KEY]");
    outtextxy(100,250,"NEW GAME[N]");
    ch=getch();
    cleardevice();
    if(ch=='n')
    {
        score=0;
        life=99;
        goto az;
    }
    else if(ch=='g')
    {
        freopen("Score.txt","w",stdout);
         z=score;
         l=life;
         r=level_controlar;
        cout<<z<<endl;
        cout<<l<<endl;
        cout<<r<<endl;
        fclose(stdout);
        setcolor(RED);
        settextstyle(3,0,4);
        outtextxy(200,220,"GAME SAVED");
        getch();
        exit(0);
    }
   else
   {
       char mn[5];
    for(m=3;m>=0;m--)
    {
     sprintf(mn,"Game will be resume in: %d",m);
     outtextxy(180,230,mn);
     delay(600);
     cleardevice();
    }
   }
}
if(crouc_h)
{
crouch();
}
if(a<=1)
{
    crouc_h=false;
    on_crouch=false;
}

if(jump)//switch to see if the ball on its starting point
{
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
//left hand
bar(73,circle_y-40,78,circle_y-25);

//right hand
bar(113,circle_y-40,118,circle_y-25);

militia_generate();
if(!on_jump)//checking if the ball at the max y position(starting position) *
    circle_y-=30;//if at max, decreasing the value to move upward
else
    circle_y+=30;//if at half of the screen, move downward
if(circle_y<=(rectangle_y-100))//if the ball at the half way of screen,setting it as initial position for downward moving
{

    on_jump=true;//a switch for upward or downward moving(*)
}
if(circle_y>=maxy-35)//if the ball at its starting point,setting it as initial position for upward moving
{
    on_jump=false;//a switch for upward or downward moving(*)
    jump=false;//a switch for getting command for jump. Command only be taken if the at its starting point and if the switch is false!
}
circle_x=100;//x axis point of circle
store_y_circle=circle_y;//storing y axis point of the circle for further check
 }


if(a>0)
a-=1;
     setcolor(WHITE);
     settextstyle(3,0,1);
     char arr[100];
     sprintf(arr,"HEALTH: %d",life);
     outtextxy(00,40,arr);
     sprintf(arr,"SCORE: %d ",score);
     outtextxy(00,10,arr);
     outtextxy(106,40,"%");
     if(level_controlar<10)
     outtextxy(00,70,"Level: Easy");
     if(level_controlar>10 && level_controlar<20)
     outtextxy(00,70,"Level: Medium");
     if(level_controlar>20)
     outtextxy(00,70,"Level: Hard");
if(rectangl_e)
check();//check if the ball collide the obstacle
if(circl_e)
circle_check();
}
ch=getch();
}

//function for checking the collision
void check(){
if((store_x_rectangle>=73 && store_x_rectangle<=118) && (feet>store_y_rectangle  || head>store_y_rectangle) && (feet<(store_y_rectangle+105) || head<(store_y_rectangle+105))&& (life!=0))
{
    life-=4;
    //sndPlaySound("SCREAM3.wav", SND_FILENAME | SND_ASYNC );
}
if(life<=0)
{
    //sndPlaySound("Scream+9.wav", SND_FILENAME | SND_ASYNC );
    End();

}
   }

void circle_check(){
if((store_x_rectangle>=73 && store_x_rectangle<=118) && (feet>store_y_rectangle  || head>store_y_rectangle) && (feet<(store_y_rectangle+20) || head<(store_y_rectangle+20))&& (life!=0))
{
    life-=4;
    //sndPlaySound("SCREAM3.wav", SND_FILENAME | SND_ASYNC );
}
if(life<=0)
{
    //sndPlaySound("Scream+9.wav", SND_FILENAME | SND_ASYNC );
    End();

}
   }
//This function has nothing but a exit command and it works for  ending the game
void End()

{
    char ch;
freopen("HighScore.txt","w",stdout);
    if(s<score)
    {
        s=score;
        cout<<s<<endl;
    }
fclose(stdout);
cleardevice();
delay(500);
setcolor(RED);
settextstyle(3,0,4);
outtextxy(150,150,"   GAME OVER ");
delay(500);
char anm[100];
setcolor(WHITE);
settextstyle(3,0,2);
sprintf(anm,"YOUR SCORE: %d ",score);
outtextxy(205,250,anm);
setcolor(YELLOW);
settextstyle(3,0,2);
outtextxy(0,420,"NEW GAME [ANY KEY]");
outtextxy(0,440,"EXIT [E]");

ch=getch();
if(ch=='e')
exit(0);
else
{
cleardevice();
life=99;
level_controlar=0;
score=0;
main_a();
}
}
void militia_generate()
{

setcolor(WHITE);
setfillstyle(SOLID_FILL,3);


//head
circle(95,circle_y-60,10);
floodfill(90,circle_y-60,WHITE);
//body
bar(80,circle_y-50,110,circle_y-20);

//left nut
circle(75,circle_y-45,5);
floodfill(75,circle_y-45,WHITE);

//right nut
circle(115,circle_y-45,5);
floodfill(115,circle_y-45,WHITE);



if(on_jump)
{
//left hand
bar(73,circle_y-50,78,circle_y-70);

//right hand
bar(113,circle_y-50,118,circle_y-70);
}

if(!on_jump)
{
//left hand
bar(73,circle_y-40,78,circle_y-25);

//right hand
bar(113,circle_y-40,118,circle_y-25);
}


//left leg
bar(83,circle_y-20,90,circle_y-5);

//right leg
bar(100,circle_y-20,107,circle_y-5);


delay(20);
//Darkening

 setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);


//head
circle(95,circle_y-60,10);
floodfill(90,circle_y-60,BLACK);

//body
bar(80,circle_y-50,110,circle_y-20);


//left nut
circle(75,circle_y-45,5);
floodfill(75,circle_y-45,BLACK);

//right nut
circle(115,circle_y-45,5);
floodfill(115,circle_y-45,BLACK);



if(on_jump)
{
//left hand
bar(73,circle_y-50,78,circle_y-70);

//right hand
bar(113,circle_y-50,118,circle_y-70);
}

if(!on_jump)
{
//left hand
bar(73,circle_y-40,78,circle_y-25);

//right hand
bar(113,circle_y-40,118,circle_y-25);
}

//left leg
bar(83,circle_y-20,90,circle_y-5);

//right leg
bar(100,circle_y-20,107,circle_y-5);
}
void bar_ground_generate()
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,BROWN);
    bar(0,maxy-34,maxx,maxy-19);

    setcolor(WHITE);
    setfillstyle(SOLID_FILL,GREEN);
    bar(0,maxy-39,maxx,maxy-34);

}
void night_ground_generate()
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(0,maxy-34,maxx,maxy-19);

    setcolor(WHITE);
    setfillstyle(SOLID_FILL,GREEN);
    bar(0,maxy-39,maxx,maxy-34);

}
void rectangular_obstacle_generate()
{
  for(k=rectangle_y;k<rectangle_y+120;k=k+10)
   {
    setcolor(WHITE);
    rectangle(rectangle_x-10,rectangle_y,rectangle_x,k);
   }
store_x_rectangle=rectangle_x;//Storing x axis position of obstacle for further check
store_y_rectangle=rectangle_y;//Storing y axis position of obstacle for further check

delay(speed);//Speed control of game
//removing previous position of the obstacle

for(k=rectangle_y;k<rectangle_y+120;k=k+10)
   {
    setcolor(BLACK);
    rectangle(rectangle_x-10,rectangle_y,rectangle_x,k);
   }
rectangle_x-=10;//setting new value for obstacle towards negative x axis
//when obstacle hit the very left point of the screen,generate a new obstacle
if(rectangle_x<10)
{
    rectangle_x=maxx;//setting x axis value for new obstacle
    //randomizing for obstacle height
    xz:
    p=rand()%maxx;
    rectangle_y=rand()%maxy;
    if(rectangle_y<(maxy/2)-25)//controlling the height not to set over jumping ability
        goto xz;
}
}
void initial_militia_generate()
{
setcolor(WHITE);
setfillstyle(SOLID_FILL,3);


//head
circle(95,circle_y-60,10);
floodfill(90,circle_y-60,WHITE);

//body
bar(80,circle_y-50,110,circle_y-20);

//left nut
circle(75,circle_y-45,5);
floodfill(75,circle_y-45,WHITE);

//right nut
circle(115,circle_y-45,5);
floodfill(115,circle_y-45,WHITE);

//left hand
bar(73,circle_y-40,78,circle_y-25);

//right hand
bar(113,circle_y-40,118,circle_y-25);



//left leg
bar(83,circle_y-20,90,circle_y-5);

//right leg
bar(100,circle_y-20,107,circle_y-5);

}
void circular_obstacle()
{
setcolor(WHITE);
circle(rectangle_x,rectangle_y,25);
setfillstyle(SOLID_FILL,RED);
floodfill(rectangle_x,rectangle_y,WHITE);
store_x_rectangle=rectangle_x;//Storing x axis position of obstacle for further check
store_y_rectangle=rectangle_y;//Storing y axis position of obstacle for further check

delay(speed);//Speed control of game
//removing previous position of the obstacle

setcolor(BLACK);
circle(rectangle_x,rectangle_y,25);
setfillstyle(SOLID_FILL,BLACK);
floodfill(rectangle_x,rectangle_y,BLACK);

rectangle_x-=10;//setting new value for obstacle towards negative x axis
//when obstacle hit the very left point of the screen,generate a new obstacle
if(rectangle_x<10)
{
    rectangle_x=maxx;//setting x axis value for new obstacle
    //randomizing for obstacle height
    xz:
    p=rand()%maxx;
    rectangle_y=rand()%maxy;
    if(rectangle_y<(maxy/2)+100)//controlling the height not to set over jumping ability
        goto xz;

}
}
void crouch()
{
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);

//head
circle(95,circle_y-60,10);
floodfill(90,circle_y-60,BLACK);

//body
bar(80,circle_y-50,110,circle_y-20);

//left nut
circle(75,circle_y-45,5);
floodfill(75,circle_y-45,BLACK);

//right nut
circle(115,circle_y-45,5);
floodfill(115,circle_y-45,BLACK);

//left hand
bar(73,circle_y-40,78,circle_y-25);

//right hand
bar(113,circle_y-40,118,circle_y-25);



//left leg
bar(83,circle_y-20,90,circle_y-5);

//right leg
bar(100,circle_y-20,107,circle_y-5);




setcolor(WHITE);
setfillstyle(SOLID_FILL,3);

//head
circle(95,circle_y-45,10);
floodfill(90,circle_y-45,WHITE);
//body
bar(80,circle_y-35,110,circle_y-5);

//left nut
circle(75,circle_y-30,5);
floodfill(75,circle_y-30,WHITE);

//right nut
circle(115,circle_y-30,5);
floodfill(115,circle_y-30,WHITE);

//left hand
bar(73,circle_y-25,78,circle_y-10);

//right hand
bar(113,circle_y-25,118,circle_y-10);

delay(1);
//Darkening

 setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);


//head
circle(95,circle_y-45,10);
floodfill(90,circle_y-45,BLACK);

//body
bar(80,circle_y-35,110,circle_y-5);


//left nut
circle(75,circle_y-30,5);
floodfill(75,circle_y-30,BLACK);

//right nut
circle(115,circle_y-30,5);
floodfill(115,circle_y-30,BLACK);

//left hand
bar(73,circle_y-25,78,circle_y-10);

//right hand
bar(113,circle_y-25,118,circle_y-10);
}
void sun()
{
    setcolor(BLUE);
    arc(160,60,140,245,20);
    arc(170,70,190,307,20);
    arc(180,65,270,380,20);

    arc(235,25,135,250,15);
    arc(245,35,169,295,15);
    arc(260,40,220,340,15);
    arc(270,35,260,405,15);

    arc(320,60,140,245,20);
    arc(330,70,190,307,20);
    arc(340,65,270,380,20);

    arc(410,50,140,280,15);
    arc(420,57,210,350,15);
    arc(430,45,275,400,15);



    setcolor(YELLOW);
    circle(550,55,25);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(550,55,YELLOW);

    setcolor(YELLOW);
    line(550,5,550,30);
    line(563,40,583,20);
    line(575,55,600,55);
    line(565,70,585,90);
    line(550,80,550,105);
    line(515,85,555,55);
    line(500,55,525,55);
    line(515,20,535,40);

}
void moon()
{
    setcolor(BLUE);
    arc(160,60,140,245,20);
    arc(170,70,190,307,20);
    arc(180,65,270,380,20);

    arc(235,25,135,250,15);
    arc(245,35,169,295,15);
    arc(260,40,220,340,15);
    arc(270,35,260,405,15);

    arc(320,60,140,245,20);
    arc(330,70,190,307,20);
    arc(340,65,270,380,20);

    arc(410,50,140,280,15);
    arc(420,57,210,350,15);
    arc(430,45,275,400,15);

    setcolor(WHITE);
    settextstyle(5,0,6);
    outtextxy(570,75,"*");
    outtextxy(210,85,"*");
    outtextxy(370,80,"*");
    outtextxy(300,95,"*");
    outtextxy(450,90,"*");
    outtextxy(160,20,"*");
    outtextxy(350,30,"*");

    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    arc(500,57,240,409,50);
    arc(485,48,265,395,55);
    floodfill(540,55,WHITE);

}
