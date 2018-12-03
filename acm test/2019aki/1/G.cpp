#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    char s[2][105];
    int num=0;
    scanf("%s",s[0]);
    scanf("%s",s[1]);
    for(int i=0;s[0][i+1]!='\0';i++)
    {
        if(s[0][i]=='0'&&s[1][i]=='0'&&s[0][i+1]=='0')
        {
            s[0][i]='X';
            s[1][i]='X';
            s[0][i+1]='X';
            num++;
        }
        if(s[0][i]=='0'&&s[1][i]=='0'&&s[1][i+1]=='0')
        {
            s[0][i]='X';
            s[1][i]='X';
            s[1][i+1]='X';
            num++;
        }
        if(s[0][i]=='0'&&s[1][i+1]=='0'&&s[0][i+1]=='0')
        {
            s[0][i]='X';
            s[1][i+1]='X';
            s[0][i+1]='X';
            num++;
        }
        if(s[1][i+1]=='0'&&s[1][i]=='0'&&s[0][i+1]=='0')
        {
            s[1][i+1]='X';
            s[1][i]='X';
            s[0][i+1]='X';
            num++;
        }
    }
    printf("%d",num);
}
