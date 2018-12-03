#include<cstdio>
int main()
{
	int i,j;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
			printf("%9d",i*i+100000*i+j*j-100000*j+i*j);
		printf("\n\n");
	}
}
