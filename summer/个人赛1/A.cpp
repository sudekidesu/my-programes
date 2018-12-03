#include<iostream>
using namespace std;
int main()
{
	int n,i,num=0;
	scanf("%d",&n);
	for(i=2;i<=n/2;i++)
		if(n%i==0)
			num++;
	cout<<num+1<<endl;
}
