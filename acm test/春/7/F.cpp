#include<iostream>
using namespace std;
int main()
{
	int i,n;
	double x1,x2,x3,y1,y2,y3,a,k,b;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		a=(y2-y1)/(x2-x1)/(x2-x1);
		k=(y2-y1)/(x2-x1);
		b=y2-k*x2;
		printf("%.2f\n",a*x3*x3*x3/3-a*x1*x3*x3-k*x3*x3/2+(a*x1*x1+y1-b)*x3-a*x2*x2*x2/3+a*x1*x2*x2+k*x2*x2/2-(a*x1*x1+y1-b)*x2);
	}
}
