#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int t1[10000],t2[10000];
    int num=1;
    while(scanf("%d",&n)&&n!=0)
    {
        printf("Game %d:\n",num++);
        int cnt[10][2];
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)
            scanf("%d",&t1[i]);
        while(1)
        {
            for(int i=0;i<10;i++)
            {
                cnt[i][0]=0;
                cnt[i][1]=0;
            }
            int sum=0;
            int a=0,b=0;
            for(int o=1;o<=n;o++)
            {
                scanf("%d",&t2[o]);
                sum+=t2[o];
                if(t1[o]==t2[o])
                    a++;
                else
                {
                    cnt[t1[o]][0]++;
                    cnt[t2[o]][1]++;
                }
            }
            for(int i=0;i<10;i++)
                b+=min(cnt[i][1],cnt[i][0]);
            if(sum==0)
                break;
            printf("    (%d,%d)\n",a,b);
        }
    }
}
