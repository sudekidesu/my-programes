#include<iostream>
using namespace std;
int main()
{
	int i,n,sj[10][2];
	string name[10];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>name[i]>>sj[i][0]>>sj[i][1];
	for(i=0;i<n;i++)
	{
		if(sj[i][0]>=15&&sj[i][0]<=20&&sj[i][1]>=50&&sj[i][1]<=70)
			continue;
		cout<<name[i]<<endl;
	}
}
