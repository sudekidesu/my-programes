#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char q[10][10]={0};
int main()
{
    char s[105];
    int n,m;
    scanf("%d %d",&n,&m);
    scanf("%s",s);
    int x=0,y=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='U')
            x--;
        else if(s[i]=='D')
            x++;
        else if(s[i]=='L')
            y--;
        else if(s[i]=='R')
            y++;
        q[x][y]++;
    }
    if((n%2==1&&m%2==1)||n==1||m==1);
    else
    	printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(q[i][j]!=1)
                printf("No");
}
