#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,k;
	int n,num=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			for(k=j;k<j+i&&k<=n;k++)
				if((i^j^k)==0)
				{
					num++;
				//	printf("%d %d %d\n",i,j,k);
				}
	printf("%d",num);
 } 
