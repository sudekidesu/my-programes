#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<windows.h>

#define M 22
#define N 62



#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int t=200;
int score=0;
int wall[M][N];
int snake[M*N][2];
int bodynode;
int direction;
int food_x;
int food_y;




void gotoxy(int i,int j)
{
    COORD position= {j,i};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
}



void Initial()
{
    srand(time(NULL));
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	printf("����������ʼ��Ϸ");
	getch();
}

void Wall()
{
    int i,j;
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
		{
			if(i==0 || i==M-1 || j==0 || j==N-1)
				wall[i][j]=1;
		}
	}
}

void Definehead()
{
    bodynode=3;
    snake[0][0]=16;
    snake[0][1]=11;
    snake[1][0]=16;
    snake[1][1]=10;
	snake[2][0]=16;
	snake[2][1]=9;
    direction=RIGHT;
}

void Food()
{
    int i;
    food_x=1+rand()%(M-2);
    food_y=1+rand()%(N-2);

	for(i=0;i<bodynode;i++)
	{
    	if(snake[i][0]==food_x && snake[i][1]==food_y)
		{
                food_x=1+rand()%(M-2);
                food_y=1+rand()%(N-2);
		}
	}
    gotoxy(food_x,food_y);
    printf("$");
}

void Drawmap()
{
    gotoxy(0,0);
    int i,j;
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            if(wall[i][j]==0)
                printf(" ");
            else
                printf("|");
        }
        printf("\n");
    }
}

void Move()
{
    int i;
    gotoxy(snake[bodynode-1][0],snake[bodynode-1][1]);
    printf(" ");
	if(snake[0][0]==food_x && snake[0][1]==food_y)
		  {
			  bodynode++;
              score+=10;
              Food();
		  }
    for(i=bodynode-1; i>0; i--)
    {
        snake[i][0]=snake[i-1][0];
        snake[i][1]=snake[i-1][1];
    }
    switch(direction)
    {
    case UP:
        snake[0][0]--;
        break;
    case DOWN:
        snake[0][0]++;
        break;
    case LEFT:
        snake[0][1]--;
        break;
    case RIGHT:
        snake[0][1]++;
        break;
    }

}

void Drawsnake()
{
    int i;
    gotoxy(snake[0][0],snake[0][1]);
	printf("@");
    for(i=1; i<bodynode; i++)
    {
        gotoxy(snake[i][0],snake[i][1]);
        printf("*");
    }
}

void Control()
{
    if(kbhit()!=0)
    {
        char c;
        while(!kbhit()==0)
            c=getch();
        switch(c)
        {
           case 'w':
           case 'W':
                if(direction!=DOWN)
                   direction=UP;
                   break;
           case 's':
           case 'S':
               if(direction!=UP)
                   direction=DOWN;
                   break;
           case 'a':
           case 'A':
               if(direction!=RIGHT)
                   direction=LEFT;
                   break;
           case 'd':
           case 'D':
               if(direction!=LEFT)
                   direction=RIGHT;
                   break;
           case '\x20':
               do{
			    	Sleep(0);
			   }while(getch()!='\x20');
                   break;
		   case '\x30':
			   if(t>50)
				  t-=150;
			      break;
		   case '\x39':
			   if(t<350)
				  t+=150;
			   break;
        }
    }
}

int Judgedie()
{
    int judgedie=0;
    if(snake[0][0]==0 || snake[0][0]==M-1 || snake[0][1]==0 || snake[0][1]==N-1)
        judgedie=1;
    for(int i=1; i<bodynode; i++)
    {
        if(snake[i][0]==snake[0][0] && snake[i][1]==snake[0][1])
            judgedie=1;
    }
	return judgedie;
}



void Scoresort(int sort[])
{
    int i,j,temp,rank=0;
	for(i=0;i<10;i++)
	{
		for(j=9;j>i;j--)
			if(sort[j]>sort[j-1])
			{
				temp=sort[j-1];
				sort[j-1]=sort[j];
				sort[j]=temp;
			}
	}
	printf("��Ϸ���а�\n");
	for(i=0;i<6;i++)
	{
		rank++;
		printf("�� %d ��:  %d ��\n",rank,sort[i]);
	}

}

void Rank()
{
	int i=0;
	int grade[2000]={0};
	FILE *fp;
	fp=fopen("../grade.txt","ab");
	if(fp==0)
	{
		printf("file error\n");
		exit(1);
	}
	fprintf(fp,"%d ",score);
	fclose(fp);

	fp=fopen("../grade.txt","r");
	if(fp==0)
	{
		printf("file error\n");
		exit(1);
	}
	fscanf(fp,"%d",&score);
	while(!feof(fp))
	{
		grade[i]=score;
		fscanf(fp,"%d",&score);
		i++;

	}
	fclose(fp);
	for(i=0;i<10;i++)
		 printf("%d  ",grade[i]);
	     printf("\n");
	Scoresort(grade);
}


int main()
{
	Initial();
	do
	{
         score=0;
         Wall();
	     Drawmap();
	     Food();
	     Definehead();
	     while(1)
		 {
            Drawsnake();
            Sleep(t);
            Control();
            Move();
            if(Judgedie()==1)
			{
                system("cls");
                printf("Game Over\n");
 	   	 	    printf("Your score is: %d\n",score);
				printf("�� Enter �����¿�ʼ��Ϸ\n");
				Rank();
                break;
			}
			if(bodynode==(M-2)*(N-2))
			{
				system("cls");
                printf("��ϲ��������\n");
 	   	 	    printf("Your score is: %d\n",score);
				printf("�� Enter �����¿�ʼ��Ϸ\n");
                break;
			}
		 }
	}while(getch()=='\x0d');
    return 0;
}
