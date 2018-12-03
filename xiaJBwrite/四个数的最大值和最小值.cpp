#include<stdio.h >
int compare(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int compare2(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int main()
{
	int a,b,c,d,k1,k2,k3,m1,m2,m3;
	printf("请输入四个整数\n");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	k1=compare(a,b);
	k2=compare(k1,c);
	k3=compare(k2,d);
	m1=compare2(a,b);
	m2=compare2(m1,c);
	m3=compare2(m2,d);
	printf("最大值为%d\n最小值为%d\n",k3,m3);
	return 0;
}
