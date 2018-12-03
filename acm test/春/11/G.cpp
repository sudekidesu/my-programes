#include<bits/stdc++.h>
using namespace std;
int gcd(long long int a,long long int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long k,l,m,n;
		scanf("%lld %lld %lld %lld",&k,&l,&m,&n);
		long long c = gcd(n,m);
		m /= c;
		n /= c;
		long double x,y;
		double a,b;
		x = k * sqrtl((n*1.0)/(m*1.0)) - l;
		y = l * sqrtl((n*1.0)/(m*1.0)) - k;
		a=x;
		b=y;
		printf("%lf %lf\n", a, b);
	}
	return 0;
}
