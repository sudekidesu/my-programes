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
		int num[105]={0};
		int a[105];
		int i,j,k,l;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			num[i]=1;
		}
		for(i=n-1;i>0;i--)
			for(j=i-1;j>=0;j--)
				if(a[j]<=a[i])
					num[j]+=num[i];
		for(i=0;i<n;i++)
		{
			printf("%d",num[i]);
			if(i!=n-1)
				printf(" ");
		}
		printf("\n");
	}
}
