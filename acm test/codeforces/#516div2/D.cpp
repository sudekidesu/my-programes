#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
char s[3000][3000];
pair<int,int> num[3000][3000];
queue<pair<int,int>> q;
set<pair<int,int>> st;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int x,y;
    int x0,y0;
    scanf("%d %d",&x0,&y0);
    scanf("%d %d",&x,&y);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            num[i][j].first=num[i][j].second=0;
    pair<int,int> temp;
    temp.first=x0;
    temp.second=y0;
    q.push(temp);
    st.insert(temp);
    while(q.size()>0)
    {
        if(s[temp.first-1][temp.second]=='.')
        {
            temp.first--;
            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                q.push(temp);
            }
            temp.first++;
        }
        if(s[temp.first+1][temp.second]=='.')
        {
            temp.first++;
            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                q.push(temp);
            }
            temp.first--;
        }
        if(s[temp.first][temp.second+1]=='.')
        {
            temp.second++;
            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                q.push(temp);
            }
            temp.second--;
        }
        if(s[temp.first][temp.second+1]=='.')
        {
            temp.second--;
            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                q.push(temp);
            }
            temp.second++;
        }
    }
}
