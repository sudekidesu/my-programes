#include<stdio.h>
int ifprime(int a)
{
	if(a==1||a==2||a==0)
		return 0;	
	int b=1;
		while(b*b<=a)
		{
			b++;
			if(a%b==0)
				return 0;
			if(a<=b*b)
				return 1;
		}
}
int main()
{
	int a,i,k;
	int cases[250]={0};
	for(i=0;;i++)
	{
		scanf("%d",&a);
		if(a<=0)
			break;
		cases[i]=ifprime(a);
	}
	for(k=0;k<i;k++)
	{
		printf("%d: ",k+1);
		if(cases[k]==1)
			printf("yes\n");
		if(cases[k]==0)
			printf("no\n");
	}
}
