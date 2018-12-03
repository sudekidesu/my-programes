#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
struct ren
{
  int father,mother;
  int mito;
  int dead;
  vector<int> g;
  char sex[2];
  ren()
  {
    father=mother=0;
    dead=0;
    mito=-1;
    sex[0]='\0';
  }
}r[200005];
void refresh()
{
  vector<int>::iterator k;
  for(int i=n;i>0;i--)
    if(r[i].mito!=-1)
        r[r[i].mother].mito=r[i].mito;
  for(int i=1;i<=n;i++)
    if(r[i].sex[0]=='F'&&r[i].mito!=-1)
      for(k=r[i].g.begin();k!=r[i].g.end();k++)
        r[*k].mito=r[i].mito;
}
int main()
{
  freopen("eve.in","r",stdin);
  freopen("eve.out","w",stdout);
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%s",r[i].sex);
  n++;
  int m;
  scanf("%d",&m);
  int a;
  for(int i=0;i<m;i++)
  {
    scanf("%d",&a);
    if(a>0)
    {
      scanf("%d %s",&r[n].mother,r[n].sex);
      r[n].father=a;
      r[r[n].mother].g.push_back(n);
      n++;
    }
    else
      r[-a].dead=1;
  }
  n--;
  scanf("%d",&m);
  for(int i=0;i<m;i++)
  {
    scanf("%d",&a);
    scanf("%d",&r[a].mito);
  }
  if(m==0)
    for(int i=n;i>0;i++)
      if(r[i].dead==0)
      {
        r[i].mito=-2;
        break;
      }
  refresh();
  int temp=-1;
  int is1=1;
  int is2=1;
  for(int i=1;i<=n;i++)
  {
    if(r[i].dead==1)
      continue;
    if(temp==-1&&r[i].mito!=-1)
      temp=r[i].mito;
    else if(r[i].mito!=-1&&r[i].mito!=temp)
      is1=0;
    if(r[i].mito==-1)
      is2=0;
  }
  if(is1==0)
    printf("NO\n");
  else if(is2==0)
    printf("POSSIBLY\n");
  else
    printf("YES\n");
}
