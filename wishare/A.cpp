#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,o,i,num[3],c,j;
	cin>>n;
	for(o=0;o<n;o++)
	{
		c=0;
		cin>>num[0]>>num[1]>>num[2];
		for(i=0;num[0]!=num[1]||num[1]!=num[2];i++)
		{
			sort(num,num+3,greater<int>());
			if(num[0]-num[2]>=2)
			{
				j=(num[0]-num[2])/2;
				c+=j;
				num[2]+=j*2;
			}
			if(num[0]-num[1]>=2)
			{
				j=(num[0]-num[1])/2;
				c+=j;
				num[1]+=j*2;
			}
			if(num[0]-1==num[1]&&num[1]==num[2])
			{
				num[1]++;
				num[2]++;
				c++;
			}
			if(num[0]==num[1]&&num[1]-num[2]==1)
			{
				num[2]++;
				c+=2;
			}
		}
		cout<<c<<endl;
	}
}
