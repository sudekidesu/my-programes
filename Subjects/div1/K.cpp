#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n=0;
    while(++n)
    {
        string s;
        char str[5][5];
        int x,y;
        for(int i=0;i<5;i++)
        {
            getline(cin,s);
            if(i==0&&n!=1&&(s.length()!=1||s[0]!='Z'))
                printf("\n");
            if(s.length()==1&&s[0]=='Z')
                return 0;
            for(int j=0;j<5;j++)
            {
                str[i][j]=s[j];
                if(s[j]=='\0')
                	str[i][j]=' ';
                if(str[i][j]==' ')
                {
                    x=i;
                    y=j;
                }
            }
        }
        bool flag=true;
        while(1)
        {
            getline(cin,s);
            for(int i=0;i<s.length();i++)
            {
                if(s[i]=='A')
                {
                    if(x==0)
                    {
                        flag=0;
                        break;
                    }
                    else
                    {
                        str[x][y]=str[x-1][y];
                        str[x-1][y]=' ';
                        x--;
                    }
                }
                if(s[i]=='B')
                {
                    if(x==4)
                    {
                        flag=0;
                        break;
                    }
                    else
                    {
                        str[x][y]=str[x+1][y];
                        str[x+1][y]=' ';
                        x++;
                    }
                }
                if(s[i]=='L')
                {
                    if(y==0)
                    {
                        flag=0;
                        break;
                    }
                    else
                    {
                        str[x][y]=str[x][y-1];
                        str[x][y-1]=' ';
                        y--;
                    }
                }
                if(s[i]=='R')
                {
                    if(y==4)
                    {
                        flag=0;
                        break;
                    }
                    else
                    {
                        str[x][y]=str[x][y+1];
                        str[x][y+1]=' ';
                        y++;
                    }
                }
            }
            if(s[s.length()-1]=='0')
                break;
        }
        printf("Puzzle #%d:\n",n);
        if(!flag)
            printf("This puzzle has no final configuration.\n");
        else
            for(int i=0;i<5;i++)
                for(int j=0;j<5;j++)
                    printf("%c%c",str[i][j],j==4?'\n':' ');
    }
}
