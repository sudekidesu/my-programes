#include<iostream>
#include<cstdio>
using namespace std;
long long jud[1000005]={0};
int main()
{
  long long i,j;
  for(i=2;i<=1000000;i++)
    for(j=1;j*i<=1000000;j++)
      jud[i*j]++;
  for(i=0;i<=1000000;i++)
  	jud[i]=i-jud[i];
  int T;
  scanf("%d",&T);
  while(T--)
  {
    long long n,m,p;
	double sum=0;
    scanf("%lld %lld %lld",&n,&m,&p);
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=m;j++)
      {
     //	printf("%lld ",jud[i*j]/jud[i]/jud[j]);
        sum+=1.0*jud[i*j]/jud[i]/jud[j];
      	while(sum>p)
      		sum-=p;
      }
    //  printf("\n");
  	}
    printf("%.0lf\n",sum);
  }
}
