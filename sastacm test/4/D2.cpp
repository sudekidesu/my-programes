#include<cstdio>
int n,m;
int hfi(int j,long long int ave)
{
	int low1=1,high1=n;
	if(n*n+100000*n+j*j-100000*j+n*j<ave)
		return n;
	if(n*n+100000*n+j*j-100000*j+n*j==ave)
		return n-1;
	if(1+100000+j*j-100000*j+j>ave)
		return 0;
	for(;;)
	{
		long long int ave1=(low1+high1)/2;
		long long int r=ave1*ave1+100000*ave1+j*j-100000*j+ave1*j;
		long long int r1=high1*high1+100000*high1+j*j-100000*j+high1*j;
		if(low1==high1-1)
			return low1; 
		if(r>ave)
			high1=ave1;
		else if(r<ave)
			low1=ave1;
		else if(r==ave)
			return ave1-1;
	}
}
int count(long long int ave)
{
	int j,k=0;
	for(j=1;j<=n;j++)
		k+=hfi(j,ave);
	return k;
}
int hfz()
{
	long long int ave;
	long long int /*low=400000,high=400050;*/low=-9223372036854775807,high=9223372036854775807;
	for(;;)
	{
		ave=(low+high)/2;
		int t1=count(ave);
		int t2=count(ave-1); 
		if(t1>m||t2>=m)
			high=ave;
		else if(t1<=m)
			low=ave;
		if(t1-t2==1)
			return ave;
	}
}
int main()
{
	int o,t,s;
	scanf("%d",&t);
	for(o=0;o<t;o++)
	{
		scanf("%d %d",&n,&m);
		s=hfz();
		printf("%d\n",s);
	}
 } 
