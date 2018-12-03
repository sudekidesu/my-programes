#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    int m,n;
    int maxm=0;
    int c;
    int a[3000];
    map<int,int> mp;
    map<int,int> st;
    scanf("%d",&m);
    scanf("%d",&n);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        int temp;
        scanf("%d",&temp);
        for(int j=1;j<=m&&a[j]<temp;j++)
        {
            if(mp[temp-a[j]]!=0)
            {
                j=max(st[temp-a[j]],j);
                if(j==st[temp-a[j]])
                	j++;
            }
            mp[temp-a[j]]++;
            if(mp[temp-a[j]]==maxm)
            {
                maxm=mp[temp-a[j]];
                c=min(temp-a[j],c);
            }
            if(mp[temp-a[j]]>maxm)
            {
                maxm=mp[temp-a[j]];
                c=temp-a[j];
            }
            st[temp-a[j]]=j;
        }
    }
    printf("%d\n",c);
}
