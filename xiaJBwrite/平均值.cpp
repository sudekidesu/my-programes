#include<stdio.h>
int main()
{
	int a[20];
	int i,k,sum=0,s,t;
	double ave;
	for(i=0;i<20;i++)
		scanf("%d",&a[i]);
	for(i=0;i<19;i++)
		for(k=i+1;k<20;k++)
			if(a[i]>a[k])
				{
					s=a[k];
					a[k]=a[i];
					a[i]=s;
				}
	for(i=1;i<20;i++)
		if(a[i]!=a[i-1])
			{
				s=i;
				break;
			}
	for(i=18;i>=0;i--)
		if(a[i]!=a[i+1])
			{
				t=i;
				break;
			}
	for(i=s;i<=t;i++)
		sum+=a[i];
	ave=sum/((t-s+1)*1.0);
	printf("count=%d,average=%.2f\n",t-s+1,ave);
}
