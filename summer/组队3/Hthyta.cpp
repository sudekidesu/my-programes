#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3fffffff
using namespace std;
int dp[205][205][26];
int table[26][26][2];
int main()
{
  int n;
  while(1)
  {
    int temp;
    char t;
  	cin>>n;
    if(n==0)
      break;
    char alph[27];
    for(int i=0;i<n;i++)
      cin>>alph[i];
    alph[n]='\0';
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      {
        cin>>temp>>t>>t;
        table[i][j][0]=temp;
        table[i][j][1]=t-'a';
      }
    cin>>n;
    while(n--)
    {
      char s[205];
      cin>>s;
      int l=strlen(s);
      memset(dp,-1,sizeof(dp));
      for(int i=0;i<l;i++)
          dp[i][i][s[i]-'a']=0;
      for(int i=1;i<=l;i++)//区间长度
        for(int u=0;u<=l-i;u++)//左端点
        {
          int r=u+i-1;
          for(int m=u;m<=r;m++)
            for(int k=0;alph[k]!='\0';k++)
              if(dp[u][m][alph[k]-'a']!=-1)
                for(int o=0;alph[o]!='\0';o++)
                  if(dp[m+1][r][alph[o]-'a']!=-1)
                    if(dp[u][r][table[k][o][1]]==-1||dp[u][r][table[k][o][1]]>dp[u][m][alph[k]-'a']+dp[m+1][r][alph[o]-'a']+table[k][o][0])
                      dp[u][r][table[k][o][1]]=dp[u][m][alph[k]-'a']+dp[m+1][r][alph[o]-'a']+table[k][o][0];
        }
      temp=INF;
      for(int i=0;alph[i]!='\0';i++)
      	if(dp[0][l-1][alph[i]-'a']!=-1&&dp[0][l-1][alph[i]-'a']<temp)
        {
          temp=dp[0][l-1][alph[i]-'a'];
          t=alph[i];
        }
      printf("%d-%c\n",temp,t);
    }
    printf("\n");
  }
}
