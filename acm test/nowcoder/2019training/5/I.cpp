#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char q[505][505];
int n,m;
void she(pair<int,int> v,char d)
{
    while(v.first>0&&v.first<=n&&v.second>0&&v.second<=m)
    {
        if(q[v.first][v.second]=='.')
        {
            if(d=='d')
                v.first++;
            else if(d=='u')
                v.first--;
            else if(d=='l')
                v.second--;
            else
                v.second++;
        }
        else if(q[v.first][v.second]=='/')
        {
            if(d=='d')
            {
                v.second--;
                d='l';
            }
            else if(d=='u')
            {
                v.second++;
                d='r';
            }
            else if(d=='l')
            {
                v.first++;
                d='d';
            }
            else
            {
                v.first--;
                d='u';
            }
        }
        else if(q[v.first][v.second]=='\\')
        {
            if(d=='d')
            {
                v.second++;
                d='r';
            }
            else if(d=='u')
            {
                v.second--;
                d='l';
            }
            else if(d=='l')
            {
                v.first--;
                d='u';
            }
            else
            {
                v.first++;
                d='d';
            }
        }
    }
    if(v.first>n)
        printf("%d\n",v.second);
    else
        printf("-1\n");
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",q[i]+1);
    for(int i=1;i<=m;i++)
    {
        pair<int,int> v;
        v.first=1;
        v.second=i;
        she(v,'d');
    }
}
