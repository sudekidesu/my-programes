#include<iostream>
#include<cstdio>
using namespace std;
int num[1000000]={0};
int main()
{
  int a,n;
  while(scanf("%d",&n)!=EOF)
  {
    for(int i=0;i<1000000;i++)
      num[i]=0;
    for(int i=0;i<n;i++)
    {
      scanf("%d",&a);
      num[a]++;
    }
    for(int i=0;i<1000000;i++)
      if(num[i]>n/2)
      {
        printf("%d\n",i);
        break;
      }
  }
}
