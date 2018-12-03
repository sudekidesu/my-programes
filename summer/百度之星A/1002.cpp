#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;
int d,u,v,w,val;
deque<int> q[150005];
int main()
{
  int n;
  int Q;
  scanf("%d %d",&n,&Q);
  while(Q--)
  {
    deque<int>::iterator i;
    scanf("%d",&d);
    if(d==1)
    {
      scanf("%d %d %d",&u,&w,&val);
      if(w==1)
        q[u].push_back(val);
      else
      {
        q[u].push_back(1);
        for(i=q[u].end()-1;i>q[u].begin();i--)
          *i=*(i-1);
        *i=val;
      }
    }
    else if(d==2)
    {
      scanf("%d %d",&u,&w);
      if(q[u].size()==0)
        printf("-1\n");
      else if(w==0)
      {
        printf("%d\n",q[u].front());
        for(i=q[u].begin();i<q[u].end()-2;i++)
          *i=*(i+1);
        q[u].pop_back();
      }
      else
      {
        printf("%d\n",q[u].back());
        q[u].pop_back();
      }
    }
    else if(d==3)
    {
      scanf("%d %d %d",&u,&v,&w);
      if(w==0)
      {
        for(i=q[v].begin();i!=q[v].end();i++)
          q[u].push_back(*i);
        q[v].clear();
      }
      else
      {
        for(i=q[v].end()-1;i>=q[v].begin();i--)
          q[u].push_back(*i);
        q[v].clear();
      }
    }
  }
}
