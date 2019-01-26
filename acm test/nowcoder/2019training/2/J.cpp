#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int t=0;
    int j=0;
    bool ans=true;
    pair<int,int> k[100005];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&k[i].second);
    for(int i=0;i<n;i++)
        scanf("%d",&k[i].first);
    sort(k,k+n);
    while(j<n)
    {
        if(k[j].first-t<k[j].second)
        {
            ans=false;
            break;
        }
        else
        {
            t+=k[j].second+2;
            j++;
        }
    }
    printf("%s\n",ans?"YES":"NO");
}
