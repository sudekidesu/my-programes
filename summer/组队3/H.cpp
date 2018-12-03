#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#define INF 0xfffffff
using namespace std;
int main()
{
  char temp;
  int t;
  int n;
  while(1)
  {
    map<char,int> alph;
    alph['!']=0;
    int table1[27][27]={0};
    char table2[27][27];
    char s[205];
    scanf("%d",&n);
    getchar();
    if(n==0)
      break;
    int i;
    for(i=1;i<=n;i++)
    {
      scanf("%s",s);
      getchar();
      alph[s[0]]=i;
      table2[0][i]=s[0];
    }
    int j;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
      {
        scanf("%d-%c",&t,&temp);
        table1[i][j]=t;
        table2[i][j]=temp;
      }
    scanf("%d",&n);
    while(n--)
    {
      int time[205];
      time[0]=0;
      time[1]=0;
      for(i=2;i<205;i++)
        time[i]=INF;
      char piece[205]={'!'};
      scanf("%s",s+1);
      s[0]='!';
      piece[1]=s[1];
      for(i=2;s[i]!='\0';i++)
      {
        if(time[i-2]+table1[alph[s[i-1]]][alph[s[i]]]+table1[alph[piece[i-2]]][alph[table2[alph[s[i-1]]][alph[s[i]]]]]<time[i-1]+table1[alph[piece[i-1]]][alph[s[i]]]&&time[i-2]+table1[alph[s[i-1]]][alph[s[i]]]+table1[alph[piece[i-2]]][alph[table2[alph[s[i-1]]][alph[s[i]]]]]<=time[i])
        {
          time[i]=time[i-2]+table1[alph[s[i-1]]][alph[s[i]]]+table1[alph[piece[i-2]]][alph[table2[alph[s[i-1]]][alph[s[i]]]]];
          piece[i]=table2[alph[piece[i-2]]][alph[table2[alph[s[i-1]]][alph[s[i]]]]];
        }
        else if(time[i-2]+table1[alph[s[i-1]]][alph[s[i]]]+table1[alph[piece[i-2]]][alph[table2[alph[s[i-1]]][alph[s[i]]]]]>time[i-1]+table1[alph[piece[i-1]]][alph[s[i]]]&&time[i-1]+table1[alph[piece[i-1]]][alph[s[i]]]<=time[i])
        {
          time[i]=time[i-1]+table1[alph[piece[i-1]]][alph[s[i]]];
          piece[i]=table2[alph[piece[i-1]]][alph[s[i]]];
        }
        else
        {
          time[i]=time[i-2]+table1[alph[s[i-1]]][alph[s[i]]]+table1[alph[piece[i-2]]][alph[table2[alph[s[i-1]]][alph[s[i]]]]];
          piece[i]=table2[alph[piece[i-2]]][alph[table2[alph[s[i-1]]][alph[s[i]]]]];
          for(int j=1;j<=5&&s[i+j]!='\0';j++)
            if(time[i+j-2]+table1[alph[s[i+j-1]]][alph[s[i+j]]]+table1[alph[piece[i+j-2]]][alph[table2[alph[s[i+j-1]]][alph[s[i+j]]]]]<time[i+j-1]+table1[alph[piece[i+j-1]]][alph[s[i+j]]]&&time[i+j-2]+table1[alph[s[i+j-1]]][alph[s[i+j]]]+table1[alph[piece[i+j-2]]][alph[table2[alph[s[i+j-1]]][alph[s[i+j]]]]]<time[i+j])
            {
              time[i+j]=time[i+j-2]+table1[alph[s[i+j-1]]][alph[s[i+j]]]+table1[alph[piece[i+j-2]]][alph[table2[alph[s[i+j-1]]][alph[s[i+j]]]]];
              piece[i+j]=table2[alph[piece[i+j-2]]][alph[table2[alph[s[i+j-1]]][alph[s[i+j]]]]];
            }
            else if(time[i+j-1]+table1[alph[piece[i+j-1]]][alph[s[i+j]]]<time[i+j])
            {
              time[i+j]=time[i+j-1]+table1[alph[piece[i+j-1]]][alph[s[i+j]]];
              piece[i+j]=table2[alph[piece[i+j-1]]][alph[s[i+j]]];
            }
       	  time[i]=time[i-1]+table1[alph[piece[i-1]]][alph[s[i]]];
       	  piece[i]=table2[alph[piece[i-1]]][alph[s[i]]];
        }
      }
      printf("%d-%c\n",time[i-1],piece[i-1]);
    }
    printf("\n");
  }
}
