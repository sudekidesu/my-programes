#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a>b;
}
int main()
{
    pair<int,int> a[6];
    while(scanf("%d %d",&a[0].first,&a[0].second)!=EOF)
    {
        if(a[0].second>a[0].first)
            swap(a[0].second,a[0].first);
        for(int i=1;i<6;i++)
        {
            scanf("%d %d",&a[i].first,&a[i].second);
            if(a[i].second>a[i].first)
                swap(a[i].second,a[i].first);
        }
        sort(a,a+6,cmp);
        if(a[0].first==a[1].first&&a[0].first==a[2].first&&a[0].first==a[3].first&&a[1].second==a[0].second&&a[0].second==a[4].first&&a[0].second==a[5].first&&a[2].second==a[3].second&&a[2].second==a[4].second&&a[2].second==a[5].second)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
}
