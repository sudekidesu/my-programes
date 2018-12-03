#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int main()
{
	int a1[1005];
	int a2[1005];
	int num=0;
	set<int> s;
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a1[i]);
		s.insert(a1[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a2[i]);
		s.insert(a2[i]);
	}
	int j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(s.find(a1[i]^a2[j])!=s.end())
				num++;
	printf("%d\n",num%2);
}
