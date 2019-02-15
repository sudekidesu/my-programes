#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
pair<int ,int> a[20];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    n--;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&a[i].second,&a[i].first);
        a[i].first-=a[i].second;
    }
    printf("%d\n",ans[n]!=0?ans[n]:-1);
}
