#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
using namespace std;
set<int> s[101];
set<int> ans;
set<int> d;
int main()
{
    int m,n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        ans.clear();
        for(int i=0;i<101;i++)
            s[i].clear();
        while(scanf("%d",&m)&&m!=0)
        {
            while(getchar()!='\n')
            {
                int b;
                scanf("%d",&b);
                s[m].insert(b);
                s[b].insert(m);
            }
        }
        d.clear();
        for(int i=1;i<=n;i++)
            if(s[i].size()==1)
            {
                d.insert(i);
                // printf("%d ",i);
                // cout<<endl;
            }
        int num=0;
        for(int i=1;i<=n;i++)
            num+=s[i].size();
        num>>=1;
        bool flag=true;
        while(num&&flag)
        {
            flag=false;
            for(int i=1;i<=n;i++)
            {
                if(s[i].size()==1)
                {
                    flag=true;
                    ans.insert(*(s[i].begin()));
                    // printf("%d ",*(s[i].begin()));
                    s[*(s[i].begin())].erase(i);
                    s[i].clear();
                    num--;
                }
            }
        }
        set<int>::iterator i;
        for(i=d.begin();i!=d.end();i++)
        {
            ans.erase(*i);
            // printf("%d ",*i);
        }
        printf("%d\n",ans.size());
    }
}
