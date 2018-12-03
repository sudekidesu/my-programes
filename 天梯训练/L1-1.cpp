#include<cstdio>
int main()
{
	int a,i,k=0;
	char b;
	for(i=1;;i++)
	{
		scanf("%d",&a);
		b=getchar();
		if(a==250&&k==0)
			k=i;
		if(b=='\n')
			break;
	}
	printf("%d",k);
}
