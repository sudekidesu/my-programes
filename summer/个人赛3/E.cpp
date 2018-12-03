#include<iostream>
#include<cstdio>
using namespace std;
int a[2000000]={1,1,2,3,4,5,6,7,8,9};
int b[2000000]={0,1,2,3,4,5,6,7,8,9};
struct number
{
	int a[10];
	number()
	{
		a[1]=a[2]=a[3]=a[4]=a[5]=a[6]=a[7]=a[8]=a[9]=0;
	}
}nu[2000000];
int main()
{
	int n,i,w=1;
	for(i=1;i<=1000000;i++)
	{
		if(i/w>=10)
			w*=10;
		a[i]=i/w*a[i%w];
		b[i]=b[a[i]];
		nu[i]=nu[i-1];
		nu[i].a[b[i]]++;
	}
	int l,r,x;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d",&l,&r,&x);
		printf("%d\n",nu[r].a[x]-nu[l-1].a[x]);
	}
 } 
