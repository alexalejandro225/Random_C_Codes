#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void gotoxy(char x, char y);
void print_bar(char x,char y);
void print_ball(char x,char y);

COORD coord={0,0};

typedef struct game_element
{
    int coord_x;
    int coord_y;
}game_element;

int main()
{
    game_element ball,bar;
//clock_t start, stop;
//start=clock();
//getch();
//stop=clock();
//printf("hola mundo:%f",(double)(stop - start) / CLOCKS_PER_SEC);
print_bar(10,10);
print_ball(15,15);
return 0;
}


void gotoxy(char x,char y)
{
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void print_bar(char x,char y)
{
gotoxy(x,y);
printf("%c%c%c%c%c%c%c",178,178,178,178,178,178,178);
}

void print_ball(char x,char y)
{
gotoxy(x,y);
printf("%c",219);
}
