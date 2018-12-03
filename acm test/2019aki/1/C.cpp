#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int t[1005]={0};
    scanf("%d",&n);
    int temp;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        t[temp]++;
    }
    for(int i=1;i<1005;i++)
        t[i]+=t[i-1];
    int T;
    scanf("%d",&T);
    int num=0;
    for(int i=1+T;i<1005;i++)
        if(t[i]-t[i-T-1]>num)
            num=t[i]-t[i-T-1];
    printf("%d\n",num);
}
