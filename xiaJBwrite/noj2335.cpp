#include<cstdio>
int main()
{
	long long a[200005]={0};
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		a[i]^=a[i-1];
	}
	while(m--)
	{
		long long temp;
		int L,R;
		scanf("%d %d",&L,&R);
		temp=a[R]^a[L-1];
		if(temp<(long long)(-1)*((((long long)1)<<63)-1))
			printf("9223372036854775808\n");
		else
			printf("%I64d\n",temp>0?temp:-temp);
	}
}
