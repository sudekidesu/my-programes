#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int a[4];
	int n,numa,numb,numc,num=0;
	scanf("%d %d %d %d",&n,&a[1],&a[2],&a[3]);
	sort(a+1,a+4);
	int i,j;
	if(n%a[1]==0)
	{
		printf("%d",n/a[1]);
		return 0;
	}
	for(numa=n/a[1];numa>=0;numa--)
		for(numb=(n-numa*a[1])/a[2];numb>=0;numb--)
			for(numc=(n-numa*a[1]-numb*a[2])/a[3];numc>=0;numc--)
				if(a[1]*numa+a[2]*numb+a[3]*numc==n&&numa+numb+numc>num)
					num=numa+numb+numc;
	printf("%d",num);
}
