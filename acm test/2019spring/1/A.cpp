#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<time.h>
using namespace std;
int ans[1<<25];
void init()
{
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<(1<<25);i++)
    {
        int num[25];
        int cnt=0;
        int k=i;
        for(int l=0;l<25;l++)
        {
            if(k&1)
                cnt++;
            num[l]=k&1;
            k>>=1;
        }
        if(cnt>6)
            continue;
        int temp=0,tem=0;
        for(int j=0;j<25;j++)
        {
            temp=0;
            if(num[j]==1)
                temp++;
            if(j>4&&num[j-5]==1)
                temp++;
            if(j%5>0&&num[j-1]==1)
                temp++;
            if(j<20&&num[j+5]==1)
                temp++;
            if(j%5<4&&num[j+1]==1)
                temp++;
            tem+=((temp&1)<<j);
        }
        if(ans[tem]==-1||ans[tem]>cnt)
            ans[tem]=cnt;
    }
}
int main()
{
    int n;
    int a=clock();
    init();
    printf("Init Finished, Time used=%dms\n",clock()-a);
    scanf("%d",&n);
    while(n--)
    {
        int t=0;
        for(int i=0;i<25;i++)
        {
            char c=' ';
            while(c!='0'&&c!='1')
                c=getchar();
            t<<=1;
            t+=c-'0'==1?0:1;
        }
        printf("%d\n",ans[t]);
    }
}
