#include<iostream>
#include<cstdio>
using namespace std;
char s[5][6];
int ju[2];
void judge(char a,int jud)
{
  int i,j;
  for(i=0;i<5;i++)
    for(j=0;j<3;j++)
      if(s[i][j]==s[i][j+1]&&s[i][j]==s[i][j+2]&&s[i][j]==a)
        ju[jud]=1;
  for(i=0;i<3;i++)
    for(j=0;j<5;j++)
      if(s[i][j]==s[i+1][j]&&s[i][j]==s[i+2][j]&&s[i][j]==a)
        ju[jud]=1;
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      if(s[i][j]==s[i+1][j+1]&&s[i][j]==s[i+2][j+2]&&s[i][j]==a)
        ju[jud]=1;
  for(i=0;i<3;i++)
    for(j=2;j<5;j++)
      if(s[i][j]==s[i+1][j-1]&&s[i][j]==s[i+2][j-2]&&s[i][j]==a)
        ju[jud]=1;
}
int main()
{
  ios::sync_with_stdio(false);
  int Z;
  cin>>Z;
  while(Z--)
  {
    int i;
    for(i=0;i<5;i++)
      cin>>s[i];
    ju[0]=ju[1]=0;
    judge('A',0);
    judge('B',1);
    if(ju[0]==1&&ju[1]==0)
      printf("A wins\n");
    if(ju[0]==0&&ju[1]==1)
      printf("B wins\n");
    else if(ju[0]==ju[1])
      printf("draw\n");
  }
}
