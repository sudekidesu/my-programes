#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int num[10]={0};
        for(int i=1;i<=n;i++)
        {
            int t=i;
            while(t>0)
            {
                num[t%10]++;
                t/=10;
            }
        }
        for(int i=0;i<9;i++)
            printf("%d ",num[i]);
        printf("%d\n",num[9]);
    }
}
