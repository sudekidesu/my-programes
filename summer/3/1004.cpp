#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int k;
		scanf("%d",&k);
		if(k==1)
			k=5;
		else
			k+=5; 
		printf("%d\n",k);
	}
	return 0;
 } 
