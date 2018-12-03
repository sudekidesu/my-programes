#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
  int n;
  int a[1005];
  int max;
  while(scanf("%d",&n)!=EOF)
  {
    int i,j,k;
    max=-1;
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    sort(a,a+n);
    for(i=n-1;i>=2;i--)
      for(j=i-1;j>=1;j--)
        for(k=j-1;k>=0;k--)
          if(a[j]+a[k]>a[i]&&a[j]+a[k]+a[i]>max)
            max=a[j]+a[i]+a[k];
    printf("%d\n",max);
  }
}
