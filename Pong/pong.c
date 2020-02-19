#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

typedef struct game_element
{
    int coord_x;
    int coord_y;
    int time;
    int direct_x;
    int direct_y;
}game_element;

void gotoxy(char x, char y);
void print_bar(game_element *bar,char cursor);
void print_ball(game_element *ball_points);
void pong_cal(game_element *ball_set,game_element *bar);
void hidecursor();

COORD coord={0,0};

int main()
{
game_element ball,bar;
clock_t start, stop;
//////////////////////////////////////////////////////
char entrada;
int count_ball=0, count_bar=0 , flag_speed=0;
////////////////////////////////////
bar.coord_x=0;
bar.coord_y=24;
bar.time=20;
ball.coord_x=0;
ball.coord_y=0;
ball.time=20;
ball.direct_x=1;
ball.direct_y=1;
////////////////////////
hidecursor();
start=clock();
while(1)
{
    pong_cal(&ball,&bar);
    if(kbhit()==1)
    {
        entrada=getch();
        switch(entrada)
        {
        case 'a':
            if(flag_speed==1)
            {
                print_bar(&bar,entrada);
                print_bar(&bar,entrada);
            }
            print_bar(&bar,entrada);

            break;

        case 'd':
            if(flag_speed==1)
            {
                print_bar(&bar,entrada);
                print_bar(&bar,entrada);
            }
            print_bar(&bar,entrada);
            break;

        case '0':
            ball.time=20;
            bar.time=20;
            flag_speed=0;


            break;

        case '1':
            ball.time=15;
            if(ball.time<=15)
            {
                ball.time-=5;
            }
            flag_speed=0;

            break;

        case '2':
            ball.time=20;
            bar.time=20;
            flag_speed=1;

            break;

        case '3':
            ball.time=15;
            if(ball.time<=15)
            {
                ball.time-=5;
            }
            flag_speed=1;

            break;

        default:
            system("cls");
            gotoxy(bar.coord_x,bar.coord_y);
            printf("%c%c%c%c%c%c",219,219,219,219,219,219);
            }
        }
        stop=clock();

        if((stop-start)>=1)
        {
            if((count_ball)>ball.time)
        {
            print_ball(&ball);
            count_ball=0;
        }

            count_ball++;
            count_bar++;
            start=clock();
        }
}
return 0;
}


void gotoxy(char x,char y)
{
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void print_bar(game_element *bar,char cursor)
{

if(bar->coord_x >=1 && cursor=='a')
    {

    gotoxy((bar->coord_x),bar->coord_y);
    printf("%c%c%c%c%c%c",32,32,32,32,32,32);
    bar->coord_x--;
    gotoxy(bar->coord_x,bar->coord_y);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);
    }
if(bar->coord_x <=78 && cursor=='d')
    {
    gotoxy(bar->coord_x,bar->coord_y);
    printf("%c%c%c%c%c%c",32,32,32,32,32,32);
    bar->coord_x++;
    gotoxy(bar->coord_x,bar->coord_y);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);
    }
}

void print_ball(game_element *ball_points)
{
       gotoxy(ball_points->coord_x,ball_points->coord_y);
       printf("%c",32);
       gotoxy(ball_points->coord_x,0);
       printf("%c%c%c%c%c%c",32,32,32,32,32,32);
       //////////////////////////////////////////////////
       ball_points->coord_x+=ball_points->direct_x;
       ball_points->coord_y+=ball_points->direct_y;
       gotoxy(ball_points->coord_x,ball_points->coord_y);
       printf("%c",254);
       gotoxy(ball_points->coord_x,0);
       printf("%c%c%c%c%c%c",219,219,219,219,219,219);
}

void pong_cal(game_element *ball,game_element *bar)
{
if((ball->coord_x == bar->coord_x) && ball->coord_y == bar->coord_y)
    {
    ball->direct_y=-1;
    }
if((ball->coord_x == bar->coord_x+3) && ball->coord_y == bar->coord_y)
    {
    ball->direct_y=-1;
    }
if((ball->coord_x == bar->coord_x-3) && ball->coord_y == bar->coord_y)
    {
   ball->direct_y=-1;
    }
if((ball->coord_x == bar->coord_x+2) && ball->coord_y == bar->coord_y)
    {
    ball->direct_y=-1;
    }
if((ball->coord_x == bar->coord_x-2) && ball->coord_y == bar->coord_y)
    {
    ball->direct_y=-1;
    }
if((ball->coord_x == bar->coord_x+1) && ball->coord_y == bar->coord_y)
    {
    ball->direct_y=-1;
    }
if((ball->coord_x == bar->coord_x-1) && ball->coord_y == bar->coord_y)
    {
    ball->direct_y=-1;
    }
if((ball->coord_x == bar->coord_x+4) && ball->coord_y == bar->coord_y)
    {
     ball->direct_y=-1;
    }
if((ball->coord_x == bar->coord_x+5) && ball->coord_y == bar->coord_y)
    {
    ball->direct_y=-1;
    }
if(ball->coord_x == 80)
   {
    ball->direct_x=-1;
   }
if(ball->coord_x==0)
   {
    ball->direct_x=1;
   }
if(ball->coord_y == 0)
   {
    ball->direct_y=1;
   }
if(ball->coord_y == 25)
{
    printf("Perdiste el juego");
    getch();
    }
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
