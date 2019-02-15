#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
char q[1005][1005];
int ans=0;
queue<pair<pair<int,int>,pair<int,int> > > qu;
int main()
{
    int r,c,x,y;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&r,&c);
    scanf("%d %d",&x,&y);
    for(int i=0;i<n;i++)
        scanf("%s",q[i]);
    pair<pair<int,int>,pair<int,int> > temp;
    temp.first.first=r-1;
    temp.first.second=c-1;
    temp.second.first=x;
    temp.second.second=y;
    qu.push(temp);
    while(qu.size())
    {
        temp=qu.front();
        qu.pop();
        if(q[temp.first.first][temp.first.second]!='.')
            continue;
        q[temp.first.first][temp.first.second]='+';
        ans++;
        if(temp.first.first>0&&q[temp.first.first-1][temp.first.second]=='.')
        {
            temp.first.first--;
            qu.push(temp);
            temp.first.first++;
        }
        if(temp.first.first<n-1&&q[temp.first.first+1][temp.first.second]=='.')
        {
            temp.first.first++;
            qu.push(temp);
            temp.first.first--;
        }
        if(temp.first.second>0&&temp.second.first>0&&q[temp.first.first][temp.first.second-1]=='.')
        {
            temp.first.second--;
            temp.second.first--;
            qu.push(temp);
            temp.first.second++;
            temp.second.first++;
        }
        if(temp.first.second<m-1&&temp.second.second>0&&q[temp.first.first][temp.first.second+1]=='.')
        {
            temp.first.second++;
            temp.second.second--;
            qu.push(temp);
            temp.first.second--;
            temp.second.second++;
        }
    }
    printf("%d\n",ans);
    // for(int i=0;i<n;i++)
    //     printf("%s\n",q[i]);
}
