#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ans[300][400];
int cnt[300];
int main()
{
    ans[0][0]='2';
    for(int i=1;i<=200;i++)
    {
        int up=0;
        for(int j=0;!(ans[i-1][j]=='\0'&&up==0);j++)
        {
            int temp=i*(ans[i-1][j]=='\0'?0:(ans[i-1][j]-'0'))+up;
            ans[i][j]='0'+temp%10;
            up=temp/10;
            if(ans[i-1][j+1]=='\0'&&up==0)
                cnt[i]=j;
        }
    }
    int N;
    while(scanf("%d",&N)&&N!=-1)
    {
        printf("N=%d:\n",N);
        for(int i=cnt[N];i>=0;i--)
        {
            if(ans[N-1][i]=='\0')
                continue;
            printf("%c",ans[N-1][i]);
        }
        printf("\n");
    }
}
