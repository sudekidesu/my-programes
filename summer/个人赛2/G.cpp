#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,i,pow=0,a;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(a>=pow)
			pow=a;
	}
	printf("%d",pow);
}
