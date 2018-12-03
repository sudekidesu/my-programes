#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,n,j,num;
		char smin[10];
		char temp;
		scanf("%s %d",smin,&n);
		int n2=n;
		char smax[10];
		for(i=0;i<10;i++)
			smax[i]=smin[i];
		for(i=0;i<n;i++)
		{	
			if(smin[i]=='\0')
				break;
			temp=smin[i];
			num=i;
			for(j=i+1;smin[j]!='\0';j++)
			{
				if(i==0&&smin[j]=='0')
					continue;
				if(smin[j]<=temp)
				{
					temp=smin[j];
					num=j;
				}
			}
			smin[num]=smin[i];
			smin[i]=temp;
			if(smin[i]==smin[num])
				n++;
		}
		for(i=0;i<n2;i++)
		{
			if(smax[i]=='\0')
				break;
			temp=smax[i];
			num=i;
			for(j=i+1;smax[j]!='\0';j++)
				if(smax[j]>=temp)
				{
					temp=smax[j];
					num=j;
				}
			smax[num]=smax[i];
			smax[i]=temp;
			if(smax[i]==smax[num])
				n2++;
		}
		printf("%s %s\n",smin,smax);
	}
}
