#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#include<cstring>
#include<algorithm>
// #include<queue>
//#include<system.h>


#define random(a,b) ((a)+rand()%((b)-(a)+1))


int seed=time(NULL);

#define M 28
#define N 110


int start=0;




void gotoxy(short int i,short int j)
{
    COORD position= {j,i};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
}



class player
{
    public:
        int x,y;
        int bullet;
        int shootingrangex;
        int shootingrangey;
        char direction;
        int life;
        int dmg;
        std::string p;
        player(char d,int x1,int y1,std::string t)
        {
            life=100;
            bullet=10;
            dmg=10;
            shootingrangey=25;
            shootingrangex=10;
            direction=d;
            p=t;
            x=x1;
            y=y1;
        }
        void init(char d,int x1,int y1,std::string t)
        {
            life=100;
            bullet=10;
            dmg=10;
            shootingrangey=25;
            shootingrangex=10;
            direction=d;
            p=t;
            x=x1;
            y=y1;
        }
}p1('d',8,20,"p1"),p2('a',20,80,"p2"),p1t('d',8,20,"p1"),p2t('a',20,80,"p2");



class dougu
{
    public:
        int x,y;
        int type;
        dougu()
        {
            x=2*random(1,13);
            y=2*random(1,54);
            type=random(1,10000);
        }
        void newdougu()
        {
            x=2*random(3,10);
            y=2*random(5,44);
            type=random(10,10000);
            while(type<0)
                type+=9999;
            gotoxy(x+1,y+1);
            if(type%4==0)
                printf("B");
            else if(type%4==1)
                printf("R");
            else if(type%4==2)
                printf("P");
            else if(type%4==3)
                printf("H");
        }
        void print()
        {
            gotoxy(x+1,y+1);
            if(type%4==0)
                printf("B");
            else if(type%4==1)
                printf("R");
            else if(type%4==2)
                printf("P");
            else if(type%4==3)
                printf("H");
        }
}d[3];



void getdougu(player &a)
{
    for(int i=0;i<3;i++)
        if(a.x-d[i].x>=-1&&a.x-d[i].x<=1&&a.y-d[i].y>=-1&&a.y-d[i].y<=1)
        {
            if(d[i].type%4==0)
                a.bullet+=5;
            else if(d[i].type%4==1)
            {
                a.shootingrangex+=5;
                a.shootingrangey+=10;
            }
            else if(d[i].type%4==2)
                a.dmg+=5;
            else if(d[i].type%4==3)
                a.life+=20;
            d[i].newdougu();
        }
}



int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}



void begin();



void hello()
{
    system("cls");
    for(int i=0;i<4;i++)
        printf("==============================================================================================================\n");
    printf("\"w\" and \"s\" to choose, Press \"enter\" to confirm\n");
    printf("\n\n\n\n\n\n\n\n");
    printf("                                               >>1.start game\n");
    printf("                                                 2.help\n");
    printf("                                                 3.exit\n");
    printf("\n\n\n\n\n\n\n\n");
    for(int i=0;i<4;i++)
        printf("==============================================================================================================\n");
}



void help()
{
    system("cls");
    printf("p1 moves by \"wasd\" and shoots by \"g\"\np2 moves by \"1235\" and shoots by \"6\"\n");
    printf("P:damage up\nH:health bag\nB:bullet\nR:shooting range up\n");
    printf("Press any key to return\n");
    while(!kbhit());
    getch();
}



void clearplayer(player &a)
{
    gotoxy(a.x,a.y);
    printf("   ");
    gotoxy(a.x+1,a.y);
    printf("   ");
    gotoxy(a.x+2,a.y);
    printf("   ");
    gotoxy(a.x+3,a.y);
    printf("       ");
}



void printplayer(player &a)
{
    if(a.direction=='a'||a.direction=='d')
    {
        gotoxy(a.x,a.y);
        printf(" o ");
        gotoxy(a.x+1,a.y);
        if(a.direction=='d')
            printf("/|=");
        else
            printf("=|\\");
        gotoxy(a.x+2,a.y);
        printf("/ \\");
    }
    else
    {
        gotoxy(a.x,a.y);
        if(a.direction=='w')
            printf(" # ");
        else
            printf(" o ");
        gotoxy(a.x+1,a.y);
        if(a.direction=='w')
            printf(" o ");
        else
            printf("/ \\");
        gotoxy(a.x+2,a.y);
        if(a.direction=='w')
            printf("/ \\");
        else
            printf(" # ");
    }
    gotoxy(a.x+3,a.y);
    std::cout<<a.p<<" "<<a.life;
}



bool startpage()
{
    printf("\a");
    hello();
    start=0;
    while(1)
    {
        char a;
        if(kbhit())
        {
            a=getch();
            if(a=='w'||a=='s')
            {
                if(a=='s')
                    start++;
                else if(a=='w')
                    start--;
                start+=9;
                start%=3;
                gotoxy(13,47);
                printf("  ");
                gotoxy(14,47);
                printf("  ");
                gotoxy(15,47);
                printf("  ");
                gotoxy(13+start,47);
                printf(">>");
                gotoxy(0,0);
            }

            if(a=='\x0d')
            {
                if(start==0)
                {
                    begin();
                    return true;
                }
                else if(start==1)
                {
                    help();
                    return true;
                }
                else
                    return false;
            }
        }
    }
}



void shooting(player &a)
{
    a.bullet--;
    printf("\a");
    if(a.direction=='a')
    {
        gotoxy(a.x+1,max(a.y-a.shootingrangey+1,0));
        for(int i=max(a.y-a.shootingrangey+1,0);i<a.y;i++)
            printf("-");
        if(p1.x<=a.x+1&&p1.x>=a.x-1&&p1.y<a.y-2&&p1.y>=a.y-a.shootingrangey)
            p1.life-=a.dmg;
        if(p2.x<=a.x+1&&p2.x>=a.x-1&&p2.y<a.y-2&&p2.y>=a.y-a.shootingrangey)
            p2.life-=a.dmg;
        if(p1.life<=0||p2.life<=0)
            return;
        Sleep(50);
        gotoxy(a.x+1,max(a.y-a.shootingrangey+1,0));
        for(int i=max(a.y-a.shootingrangey+1,0);i<a.y;i++)
            printf(" ");
    }
    else if(a.direction=='d')
    {
        gotoxy(a.x+1,a.y+3);
        for(int i=a.y+3;i<110&&i<=a.y+a.shootingrangey+1;i++)
            printf("-");
        if(p1.x==a.x&&p1.y>a.y+2&&p1.y<=a.y+a.shootingrangey)
            p1.life-=a.dmg;
        if(p2.x==a.x&&p2.y>a.y+2&&p2.y<=a.y+a.shootingrangey)
            p2.life-=a.dmg;
        if(p1.life<=0||p2.life<=0)
            return;
        Sleep(50);
        gotoxy(a.x+1,a.y+3);
        for(int i=a.y+3;i<110&&i<=a.y+a.shootingrangey+1;i++)
            printf(" ");
    }
    else if(a.direction=='w')
    {
        gotoxy(a.x-1,a.y+1);
        for(int i=a.x-1;i>=0&&i>=a.x-a.shootingrangex+1;i--)
        {
            gotoxy(i,a.y+1);
            printf("|");
        }
        if(p1.y==a.y&&p1.x>=a.x-a.shootingrangex+1&&p1.x<a.x)
            p1.life-=a.dmg;
        if(p2.y==a.y&&p2.x>=a.x-a.shootingrangex+1&&p2.x<a.x)
            p2.life-=a.dmg;
        if(p1.life<=0||p2.life<=0)
            return;
        Sleep(50);
        gotoxy(a.x-1,a.y+1);
        for(int i=a.x-1;i>=0&&i>=a.x-a.shootingrangex+1;i--)
        {
            gotoxy(i,a.y+1);
            printf(" ");
        }
    }
    else if(a.direction=='s')
    {
        gotoxy(a.x+3,a.y+1);
        for(int i=a.x+3;i<28&&i<=a.x+a.shootingrangex+1;i++)
        {
            gotoxy(i,a.y+1);
            printf("|");
        }
        if(p1.y==a.y&&p1.x<a.x+a.shootingrangex+1&&p1.x>a.x)
            p1.life-=a.dmg;
        if(p2.y==a.y&&p2.x<a.x+a.shootingrangex+1&&p2.x>a.x)
            p2.life-=a.dmg;
        if(p1.life<=0||p2.life<=0)
            return;
        Sleep(50);
        gotoxy(a.x+3,a.y+1);
        for(int i=a.x+3;i<28&&i<=a.x+a.shootingrangex+1;i++)
        {
            gotoxy(i,a.y+1);
            printf(" ");
        }
    }
}



void winner()
{
    if(p1.life<0)
        p1.life=0;
    else if(p2.life<0)
        p2.life=0;
    gotoxy(p1.x+3,p1.y);
    std::cout<<p1.p<<" "<<p1.life<<"  ";
    gotoxy(p2.x+3,p2.y);
    std::cout<<p2.p<<" "<<p2.life<<"  ";
    gotoxy(13,47);
    if(p1.life<=0)
        printf("p2 wins!");
    else
        printf("p1 wins!");
}



void begin()
{
    system("cls");
    p1.init('d',8,20,"p1"),p2.init('a',20,80,"p2"),p1t.init('d',8,20,"p1"),p2t.init('a',20,80,"p2");
    printplayer(p1);
    printplayer(p2);
    for(int i=0;i<3;i++)
        d[i].newdougu();
    while(1)
    {
        if(p1.life<=0||p2.life<=0)
        {
            winner();
            Sleep(1500);
            system("pause");
            break;
        }
        getdougu(p1);
        getdougu(p2);
        char a;
        if(p1.x!=p1t.x||p1.y!=p1t.y||p1.life!=p1t.life)
        {
            clearplayer(p1t);
            printplayer(p1);
            p1t=p1;
        }
        if(p2.x!=p2t.x||p2.y!=p2t.y||p2.life!=p2t.life)
        {
            clearplayer(p2t);
            printplayer(p2);
            p2t=p2;
        }
        if(kbhit())
        {
            a=getch();
            if(a=='a')
            {
                p1.direction='a';
                if(p1.y>=2)
                  p1.y-=2;
            }
            else if(a=='d')
            {
                p1.direction='d';
                if(p1.y<=108)
                     p1.y+=2;
            }
            else if(a=='w')
            {
                p1.direction='w';
                if(p1.x>=2)
                    p1.x-=2;
            }
            else if(a=='s')
            {
                p1.direction='s';
                if(p1.x<=24)
                    p1.x+=2;
            }
            else if(a=='1')
            {
                p2.direction='a';
                if(p2.y>=2)
                    p2.y-=2;
            }
            else if(a=='3')
            {
                p2.direction='d';
                if(p2.y<=108)
                    p2.y+=2;
            }
            else if(a=='5')
            {
                p2.direction='w';
                if(p2.x>=2)
                    p2.x-=2;
            }
            else if(a=='2')
            {
                p2.direction='s';
                if(p2.x<=24)
                    p2.x+=2;
            }
            else if(a=='g'&&p1.bullet)
                shooting(p1);
            else if(a=='6'&&p2.bullet)
                shooting(p2);
            for(int i=0;i<3;i++)
                d[i].print();
        }
        gotoxy(0,0);
    }
}



int main()
{
    srand(seed);
    while(startpage());
    return 0;
}
