#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
    int n,m,p;
    char b[1003][1003];
    int ans[10]={0};
    int speed[10];
    pair<int,int> f[10];
    pair<int,int> temp;
    queue<pair<int,int>> q;
    scanf("%d %d %d",&n,&m,&p);
    for(int i=1;i<=p;i++)
        scanf("%d",&speed[i]);
    for(int i=0;i<n;i++)
        scanf("%s",b[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(b[i][j]!='.'&&b[i][j]!='#')
            {
                temp.first=i;
                temp.second=j;
                f[b[i][j]-'0']=temp;
            }
    for(int i=1;i<=p;i++)
        q.push(f[i]);
    while(q.size())
    {
        queue<pair<int,pair<int,int>>> qt;
        temp=q.front();
        while(b[q.front().first][q.front().second]==b[temp.first][temp.second])
        {
            pair<int,pair<int,int>> t;
            t.second=q.front();
            t.first=1;
            qt.push(t);
            q.pop();
        }
        while(qt.size())
        {
            ans[b[temp.first][temp.second]-'0']++;
            if(qt.front().first>speed[b[qt.front().second.first][qt.front().second.second]-'0'])
            {
                q.push(qt.front().second);
                qt.pop();
                continue;
            }
            temp=qt.front().second;
            if(temp.first>0&&b[temp.first-1][temp.second]=='.')
            {
                pair<int,pair<int,int>> t;
                t.second.first=temp.first-1;
                t.second.second=temp.second;
                t.first=qt.front().first+1;
                qt.push(t);
                b[t.second.first][t.second.second]=b[temp.first][temp.second];
            }
            if(temp.first>0&&b[temp.first][temp.second-1]=='.')
            {
                pair<int,pair<int,int>> t;
                t.second.first=temp.first;
                t.second.second=temp.second-1;
                t.first=qt.front().first+1;
                qt.push(t);
                b[t.second.first][t.second.second]=b[temp.first][temp.second];
            }
            if(temp.first>0&&b[temp.first+1][temp.second]=='.')
            {
                pair<int,pair<int,int>> t;
                t.second.first=temp.first+1;
                t.second.second=temp.second;
                t.first=qt.front().first+1;
                qt.push(t);
                b[t.second.first][t.second.second]=b[temp.first][temp.second];
            }
            if(temp.first>0&&b[temp.first][temp.second+1]=='.')
            {
                pair<int,pair<int,int>> t;
                t.second.first=temp.first;
                t.second.second=temp.second+1;
                t.first=qt.front().first+1;
                qt.push(t);
                b[t.second.first][t.second.second]=b[temp.first][temp.second];
            }
            qt.pop();
        }
    }
    for(int i=1;i<=p;i++)
        printf("%d%c",ans[i],i==p?'\n':' ');
}
