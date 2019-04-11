#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int road[600][600];
int path[600][600];
int t[600];
int main()
{
    for(int i=0;i<600;i++)
        for(int j=0;j<600;j++)
            path[i][j]=0x3f3f3f3f;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&t[i]);
    while(m--)
    {
        int a,c,b;
        scanf("%d %d %d",&a,&b,&c);
        path[a][b]=path[b][a]=c;
    }
    scanf("%d",&m);
    int k=0;
    while(m--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        while(t[k]<=c&&k<n)
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(path[i][k]+path[k][j]<path[i][j])
                        path[i][j]=path[i][k]+path[k][j];
            k++;
        }
        printf("%d\n",path[a][b]==0x3f3f3f3f||a>=k||b>=k?-1:path[a][b]);
    }
}
