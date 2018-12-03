#include<stdio.h>
int main()
{
	int a=0,b=0,i,k,d=0;
	int l1[100]={0};
	int l2[100]={0};
	scanf("%d %d",&a,&b);
	if(a==0&&b==0)
		return 0;
	for(i=0;i<a;i++)
		scanf(" %d",&l1[i]);
	for(i=0;i<b;i++)
		scanf(" %d",&l2[i]);
	for(i=0;i<a;i++)
		{
			for(k=0;k<b;k++)
				{
					if(l1[i]==l2[k])
						l1[i]=0;
				}
		}
	for(i=0;i<a-1;i++)
		{
			for(k=0;k<a-1;k++)
				if(l1[k]>l1[k+1])
					{
						d=l1[k];
						l1[k]=l1[k+1];
						l1[k+1]=d;
					}
		 } 
	d=0;
	for(i=0;i<a;i++)
		{
			if(l1[i]!=0)
				{
					printf("%d ",l1[i]);
					d++;
				}
		}
	if(d==0)
		printf("NULL");
	printf("\n");
	main(); 
}
