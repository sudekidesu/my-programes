#include<iostream>
#include<cstdio>
#include<cmath>
#define Pi 3.14159265358
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%.6lf\n",(double)2*b+Pi*a);
	}
 } 
