#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,sum=0;
	int a;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		if(a>=0)
			sum+=a;
		else
			sum-=a;
	}
	printf("%d",sum);
 } 
