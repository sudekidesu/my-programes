#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int ans;
char num[505][8];
int maxx[505];
void input()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",num[i]);
        maxx[i]=*max_element(num,num+7)-'0';
    }
}
void solve(int num,int begin,int end)
{
    for(int i=begin+1;i<end;i++)

}
int main()
{
    input();
    ans=0;
    solve(0,0,n+1);
}
