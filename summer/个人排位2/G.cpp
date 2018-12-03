#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,j,k;
	scanf("%d",&n);
	printf("%d\n",(n%8||n%8||n%8||n==14||n==15)?2:1);
}
