#include<iostream>
using namespace std;
double p[17]={2,1,0.5,0,0.25,0,0,0,0.125,0,0,0,0,0,0,0,0.0625};
int main()
{
	int N,i,a;
	double n=0;
	cin>>N;
	for(i=0;i<N;i++)
	{
		cin>>a;
		n+=p[a];
	}
	cout<<n<<endl;
}
