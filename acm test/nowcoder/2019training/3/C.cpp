#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int a,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a!=i)
        {
            ans=i;
            i++;
        }
        if(i==n-1&&ans==0)
        {
            ans=n;
            i++;
        }
    }
    printf("%d\n",ans);
}
