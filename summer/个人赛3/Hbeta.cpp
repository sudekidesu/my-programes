#include<iostream>
using namespace std;
int main()
{
	int n,m,t=0;
	cin>>n>>m;
	for(;;)
	{
		if(n==m)
		{
			cout<<t<<endl;
			return 0;
		}
		else if(m>n)
		{
			if(m%2==1)
			{
				m++;
				t++;
			}
			m/=2;
			t++;
			continue;
		}
		else if(m<n)
		{
			n--;
			t++;
		}
	}
}
