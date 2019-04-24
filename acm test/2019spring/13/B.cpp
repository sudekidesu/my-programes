#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ans=0;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int l,c;
        scanf("%d %d",&l,&c);
        l-=c;
        if(l<0)
            l=-l;
        ans^=l;
    }
    if(ans==0)
        printf("N\n");
    else
        printf("Y\n");
}
