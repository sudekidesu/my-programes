#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<functional>
using namespace std;
int n;
bool jud[64]={0};
int st[64];
int sum=0;
int ans;
bool solve(int k,int l,int x)
{
    if(l==ans)
    {
        k++;
        l=0;
    }
    if(l==0)
        x=-1;
    if(k*ans==sum)
        return true;
    for(int i=x+1;i<n;i++)
        if(jud[i]==false&&st[i]+l<=ans)
        {
            jud[i]=true;
            bool r=solve(k,l+st[i],i);
            jud[i]=false;
            if(r==true)
                return r;
            else
                while(st[i+1]==st[i]&&i<n)
                    i++;
        }
    return false;
}
int main()
{
    while(scanf("%d",&n)&&n!=0)
    {
        sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&st[i]);
            sum+=st[i];
        }
        sort(st,st+n,greater<int>());
        bool flag=false;
        for(ans=st[0]+1;ans<=sum&&!flag;ans++)
            if(sum%ans==0)
                flag=solve(0,0,-1);
        if(flag)
            printf("%d\n",ans-1);
        else
            printf("-1\n");
    }
}
