#include<cstdio>
#include<cstdlib> 
#include<algorithm>
using namespace std;
int main()
{
	int o,t;
	long long int *a=NULL;
	scanf("%d",&t);
	for(o=1;o<=t;o++)
	{
		printf("\n");
		a=NULL;
		int m,n,i,j;
		scanf("%d %d",&n,&m);
		for(;a==NULL;)
			a=(long long int*)calloc(n*n,sizeof(long long int));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				*(a+i*n+j)=((i+1)+(j+1))*((i+1)+(j+1))+100000*((i+1)-(j+1))-(i+1)*(j+1);
		sort(a,a+n*n);
		printf("%d\n",*(a+m-1));
		free(a);
	}
 }
