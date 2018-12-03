#include<iostream>
#include<cstdio>
using namespace std;
int jud[2000005];
int main()
{
	int i,j;
	int n;
	scanf("%d",&n);
	for(i=0;i<=n+1;i++)
		jud[i]=1000000000;
	jud[1]=0;
	for(i=1;i<=n+1;i++)
	{
		for(j=1;j*i<=n+1;j++)
			jud[i+i*j]=min(jud[i]+j+1,jud[i+i*j]);
		jud[i-1]=min(jud[i-1],jud[i]+1);
		for(j=1;j*i<=n+1;j++)
			jud[(i-1)*j+(i-1)]=min(jud[(i-1)*j+(i-1)],jud[i-1]+j+1);
	}
	printf("%d\n",jud[n]);
}
