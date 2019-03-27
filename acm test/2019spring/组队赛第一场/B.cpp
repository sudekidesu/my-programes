#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<tr1/unordered_map>
#include<set>
using namespace std::tr1;
unordered_map<int,unordered_map<int,int>> m;
int main()
{
    int num[6000];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    std::sort(num+1,num+n+1);
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            // pair<int,int> temp1,temp2;
            // temp2.first=num[si]-num[j];
            // temp2.second=num[i];
            // temp1.first=num[i]-num[j];
            // temp1.second=num[j];
            // int temp=m[temp2]=m[temp1]+1;
            // map<pair<int,int>,int>::iterator it=m.find(temp1);
            // if(it!=m.end())
            //     m.erase(it);
            int temp=m[num[i]-num[j]][num[j]]+1;
            unordered_map<int,int>::iterator it=m[num[i]-num[j]].find(num[j]);
            if(it!=m[num[i]-num[j]].end())
                m[num[i]-num[j]].erase(it);
            m[num[i]-num[j]][num[i]]=temp;
            ans=std::max(ans,m[num[i]-num[j]][num[i]]);
        }
    }
    printf("%d\n",ans+1);
}
