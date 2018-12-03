#include<iostream>
#include<cstdio>
using namespace std;
int a[1000000];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int flag1=0,flag2=0,flag=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=2;i<=n;i++)
            if(a[i]>a[i-1]&&flag2==0)
                flag1++;
            else if(a[i]<a[i-1]&&flag1>0)
                flag2++;
            else
                flag=1;
        if(flag==1||flag2==0)
            printf("No\n");
        else
            printf("Yes\n");
    }
}
