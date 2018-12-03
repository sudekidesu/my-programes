#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ss[110][110];
int n,m;
int win=0;
void find(int i,int j,char a)
{
    ss[i][j]=a;
  if(ss[i-1][j]!='.'&&ss[i][j-1]!='.'&&ss[i+1][j]!='.'&&ss[i][j+1]!='.'&&a=='B')
    win=1;
  if(ss[i-1][j]=='.')
    find(i-1,j,a=='A'?'B':'A');
  if(ss[i][j-1]=='.')
    find(i,j-1,a=='A'?'B':'A');
  if(ss[i+1][j]=='.')
    find(i+1,j,a=='A'?'B':'A');
  if(ss[i][j+1]=='.')
    find(i,j+1,a=='A'?'B':'A');
}
int main()
{
    for(int i=0;i<105;i++)
     ss[0][i]=ss[i][0]='X';
    while(scanf("%d %d",&n,&m))
    {
      char ans[2]={'A','B'};
      if(n==0&&m==0)
        break;
      for(int i=1;i<=n;i++)
      {
        scanf("%s",ss[i]+1);
        ss[i][m+1]='X';
      }
      for(int i=0;i<=m+5;i++)
        ss[n+1][i]='X';
      int temp=1;
      win=0;
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
          if(ss[i][j]!='X')
          {
            find(i,j,'A');
            if(win==0)
              swap(ans[0],ans[1]);
            temp=0;
            break;
          }
        if(temp==0)
          break;
      }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
          if(ss[i][j]=='X')
            printf("X");
          else
            printf("%c",ans[ss[i][j]-'A']);
        printf("\n");
      }
    }
}
