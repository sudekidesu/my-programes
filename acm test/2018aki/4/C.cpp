#include<iostream>
#include<cstdio>
using namespace std;
char num[2][7000];
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    scanf("%s",num[0]);
    scanf("%s",num[1]);
    if((num[0][0]=='>'&&num[0][m-1]=='<'&&num[1][0]=='^'&&num[1][n-1]=='v')||(num[0][0]=='<'&&num[0][m-1]=='>'&&num[1][0]=='v'&&num[1][n-1]=='^'))
        printf("YES\n");
    else
        printf("NO\n");
}
