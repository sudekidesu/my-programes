#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,k,i,sum=0;
	int rob[110000];
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&rob[i]);
	for(i=0;sum+i+1<k;)
	{
		i++;
		sum+=i;
	}
	printf("%d",rob[k-sum-1]);
}
