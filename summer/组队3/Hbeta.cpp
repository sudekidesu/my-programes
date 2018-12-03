#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x7fffffff
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
	scanf("%d",&n);
    if(n==0)
      break;
    char alph[26];
    for(int i=0;i<n;i++)
      cin>>alph[i];
    alph[n]='\0';
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      {
        cin>>temp>>t>>t;
        table[alph[i]-'a'][alph[j]-'a'][0]=temp;
        table[alph[i]-'a'][alph[j]-'a'][1]=t-'a';
      }
    scanf("%d",&n);
    while(n--)
    {
      char s[205];
      scanf("%s",s);
      int l=strlen(s);
     memset(dp,-1,sizeof(dp));
      for(int i=0;i<l;i++)
          dp[i][i][s[i]-'a']=0;
      for(int i=1;i<=l;i++)//åŒºé—´é•¿åº¦
        for(int u=0;u<=l-i;u++)//å·¦ç«¯ç‚¹
          for(int j=1;j<i;j++)//ç¬¬ä¸€å—é•¿åº¦
            for(int k=0;alph[k]!='\0';k++)
             if(dp[u][u+j-1][alph[k]-'a']!=-1)
              for(int o=0;alph[o]!='\0';o++)
                if(dp[u+j][u+i-1][alph[o]-'a']!=-1)
                  if(dp[u][u+i-1][table[alph[k]-'a'][alph[o]-'a'][1]]==-1||dp[u][u+i-1][table[alph[k]-'a'][alph[o]-'a'][1]]>dp[u][u+j-1][alph[k]-'a']+dp[u+j][u+i-1][alph[o]-'a']+table[alph[k]-'a'][alph[o]-'a'][0])
                  dp[u][u+i-1][table[alph[k]-'a'][alph[o]-'a'][1]]=dp[u][u+j-1][alph[k]-'a']+dp[u+j][u+i-1][alph[o]-'a']+table[alph[k]-'a'][alph[o]-'a'][0];
      temp=INF;
      for(int i=0;i<26;i++)
        if(dp[0][l-1][i]<=temp&&dp[0][l-1][i]!=-1)
        {
          temp=dp[0][l-1][i];
          t='a'+i;
        }
      printf("%d-%c\n",temp,t);
    }
    printf("\n");
  }
}
