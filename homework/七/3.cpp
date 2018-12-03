#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	int *num=(int*)calloc(n+1,sizeof(int));
	for(i=1;i<n+1;i++)
		num[i]=i+1;
	num[n]=1;
	int j=1;
	for(;;)
	{
		for(i=0;i<m-2;i++)
			j=num[j];
		num[j]=num[num[j]];
		j=num[j];
		if(j==num[j])
			break;
	}
	printf("%d",j);
 } 
