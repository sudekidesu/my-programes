#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int a,ans=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        if(a<60)
            ans+=400;
    }
    printf("%d\n",ans);
}
