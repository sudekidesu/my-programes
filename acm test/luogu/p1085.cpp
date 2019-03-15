#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int ans=0;
    int temp=0;
    for(int i=1;i<=7;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a+b-8>temp)
        {
            ans=i;
            temp=a+b;
        }
    }
    printf("%d\n",ans);
}
