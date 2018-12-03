#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int num[1000005]={0};
int jud[1000005]={0};
int main()
{
  while(1)
  {
    int n;
    memset(jud,0,sizeof(jud));
    scanf("%d",&n);
    if(n==0)
      break;
    for(int i=1;i<=n;i++)
      scanf("%d",&num[i]);
    num[0]=num[n];
    for(int i=n;i>0;i--)
    {
          if(i==1&&num[i]<0)
            jud[0]=1;
          if(num[i]>=0&&num[i-1]<0)
          {
              for(int j=i-1;j!=i;j--)
              {
                  if(j==0)
                    j=n;
                  if(num[j]<0)
                  {
                      int sum=0;
                      while(sum+num[j]<0)
                      {

                          sum+=num[j];
                          jud[j]=1;
                          j--;
                          if(j==0)
                            j=n;
                          if(j==i-1)
                            break;
                      }
                  }
                  if(j==i-1)
                    break;
              }
              break;
          }
     }
    int cnt=0;
    if(jud[0]==0)
        for(int i=1;i<=n;i++)
            if(jud[i]==0)
                cnt++;
    printf("%d\n",cnt);
  }
}
