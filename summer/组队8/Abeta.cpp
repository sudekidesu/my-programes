#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int num[10005];
bool d[10005][10005];
bool k[10005];
int main()
{
    // freopen("a.in","r",stdin);
    while(scanf("%d",&num[1])!=EOF)
    {
        int jud=0;
        int n=1;
        while(n++&&getchar()!='\n')
            scanf("%d",&num[n]);
        n--;
        memset(d,0,sizeof(d));
        for(int i=1;i<=n&&jud==0;i++)
        {
            while(num[i]--)
            {
                int *x=max_element(num+i+1,num+n+1);
                if((*x)==0)
                {
                    jud=1;
                    break;
                }
                else
                {
                    d[i][x-num]=d[x-num][i]=true;
                    (*x)--;
                }
            }
        }
        if(jud==0)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    if(d[i][j])
                        putchar('1');
                    else
                        putchar('0');
                    if(j!=n)
                        putchar(' ');
                    else
                        putchar('\n');
                }
        else
            printf("fail\n");
    }
}
