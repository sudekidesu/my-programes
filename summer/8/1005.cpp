#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin>>T;
  char s[3][3];
  char a[3],temp;
  while(T--)
  {
    int n,i,j;
    cin>>n;
    for(i=0;i<3;i++)
      for(j=0;j<3;j++)
        cin>>s[i][j];
    while(n--)
    {
      cin>>a;
      if(a[0]=='1')
        i=j=0;
      if(a[0]=='2')
      {
        i=0;
        j=1;
      }
      if(a[0]=='3')
      {
        i=1;
        j=0;
      }
      if(a[0]=='4')
        i=j=1;
      if(a[1]=='C')
      {
        temp=s[i][j];
        s[i][j]=s[i+1][j];
        s[i+1][j]=s[i+1][j+1];
        s[i+1][j+1]=s[i][j+1];
        s[i][j+1]=temp;
      }
      if(a[1]=='R')
      {
        temp=s[i][j];
        s[i][j]=s[i][j+1];
        s[i][j+1]=s[i+1][j+1];
        s[i+1][j+1]=s[i+1][j];
        s[i+1][j]=temp;
      }
    }
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
        cout<<s[i][j];
      cout<<endl;
    }
  }
}
