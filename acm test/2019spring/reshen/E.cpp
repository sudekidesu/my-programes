#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n;
set<int> s;
int num[305];
bool t[305]={false};
char a[305][305];
void search(int x)
{
    s.insert(x);
    t[x]=true;
    for(int i=0;i<n;i++)
        if(a[x][i]=='1'&&t[i]==false)
            search(i);
}
void solve()
{
    int temp[305];
    set<int>::iterator i;
    int j=0;
    for(i=s.begin();i!=s.end();i++,j++)
        temp[j]=num[*i];
    sort(temp,temp+s.size());
    j=0;
    for(i=s.begin();i!=s.end();i++,j++)
        num[*i]=temp[j];
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        if(t[i]==false)
        {
            s.clear();
            search(i);
            solve();
        }
    for(int i=0;i<n;i++)
        printf("%d%c",num[i],i==n?'\n':' ');
}
