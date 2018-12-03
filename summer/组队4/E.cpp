#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    int n;
    char s[25001];
    int last[200]={0};
    int last2[200]={0};
    int num[200]={0};
    int save=0;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++)
    {
      num[(int)s[i]]++;
      last[(int)s[i]]=i;
    }
    for(int i=n-1;i>=0;i--)
      if(last[(int)s[i]]!=i)
      {
        int j=i;
        while(s[j]!=s[j+1])
        {
          swap(s[j],s[j+1]);
          j++;
        }
      }
    for(int i=0;i<n;i++)
      last2[(int)s[i]]=i;
    for(int i=0;i<200;i++)
      save+=(last[i]-last2[i])*num[i]*5;
    printf("%d\n",save);
   }
}
