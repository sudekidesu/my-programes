#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	long long i,j,a,b,k,num; 
	while(T--)
	{
		num=0;
		cin>>a>>b;
		k=a*b;
		for(i=1,j=k-1;;)
		{
			if(i>j)
				break;
			if(i*j<k&&i!=a&&j!=a)
			{
				num++;
				i++;
				j--;
			}
			else if(i==a)
				i++;
			else
				j--;
		}
		for(i=1,j=k-1;;)
		{
			if(i>=j)
				break;
			if(i*j<k&&i!=b&&j!=b)
			{
				num++;
				i++;
				j--;
			}
			else if(i==b)
				i++;
			else
				j--;
		}
		cout<<num<<endl;
	}
	return 0;
}
