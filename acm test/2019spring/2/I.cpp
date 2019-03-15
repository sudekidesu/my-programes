#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
char s[1000005];
int num[30]={0};
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    scanf("%s",s);
    int ans=1000005;
    for(int i=0;i<n;i++)
        num[s[i]-'A']++;
    for(int i=0;i<q;i++)
        ans=min(ans,num[i]);
    printf("%d\n",ans*q);
}
