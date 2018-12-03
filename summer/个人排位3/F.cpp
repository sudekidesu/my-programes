#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int T;
	int num;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		int i;
		num=0;
		scanf("%d",&n);
		int j=sqrt(n-1);
		for(i=1;i<=j;i++)
			if((n-1)%i==0)
				num++;
		num*=2;
		if(j*j==n-1)
			num--;
		printf("%d\n",num);
	}
}
