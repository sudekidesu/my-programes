#include<stdio.h>
int main()
{
	int i,k,j=8,a=2;
	long long int l1[53]={1,2,3,4,5,6,8};
	for(i=2;i<50;i++)
	{
		for(k=0;k<3;k++)
		{
			l1[j]=l1[i]*l1[i+k]
		}
	}
	printf("%d",l1[49]*l1[52]);
}
