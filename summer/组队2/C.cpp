#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
  	getchar();
    char p[101]={'\0'},temp='\0',t='\0';
    char s[1000005];
    int i,j,o=0,k=0,l=0,len;
    set<char> f[40];
    set<char> g[40];
    for(i=0;;i++)
    {
      temp=getchar();
      if (temp=='[')
      {
        k++;
        t='\0';
        for(;t!=']';)
        {
          scanf("%c",&t);
          f[k].insert(t);
        }
        f[k].erase(']');
        p[i]='1';
        continue;
      }
      if(temp=='{')
      {
        l++;
        t='\0';
        for(;t!='}';)
        {
          scanf("%c",&t);
          g[l].insert(t);
        }
        g[l].erase('}');
        p[i]='2';
        continue;
      }
      p[i]=temp;
      if(p[i]=='\n')
      	break;
    }
    scanf("%s",s+1);
    len=strlen(s+1);
    for(i=1;i<=len;i++)
    {
      k=0;
      l=0;
      for(j=0;p[j]!='\n';j++)
      {
        if(i+j>len)
          break;
        if(p[j]=='1')
        {
          k++;
          if(f[k].find(s[i+j])==f[k].end())
            break;
        }
        else if(p[j]=='2')
        {
          l++;
          if(g[l].find(s[i+j])!=g[l].end())
            break;
        }
        else if(s[i+j]!=p[j]&&p[j]!='?')
          break;
        if(p[j+1]=='\n')
        {
          o++;
          if(o!=1)
            printf(" ");
          printf("%d",i);
        }
      }
    }
    if(o==0)
      printf("no match");
    printf("\n");
  }
}
