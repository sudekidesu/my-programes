#include<iostream>
using namespace std;
int main()
{
	int i,n,sj[20][2];
	float bz,bzmax,bzmin;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>sj[i][0]>>sj[i][1];
	for(i=0;i<n;i++)
	{
		bz=(sj[i][0]-100)*1.8;
		bzmax=bz*1.1;
		bzmin=bz*0.9;
		if(sj[i][1]>=bzmax)
			cout<<"You are tai pang le!"<<endl;
		else if(sj[i][1]<=bzmin)
			cout<<"You are tai shou le!"<<endl;
		else
			cout<<"You are wan mei!"<<endl;
	}
}
