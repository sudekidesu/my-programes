#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int main()
{
	int i,j,n,m,temp;
	float l,sim,dif;
	set<int> sta[50];
	set<int>::iterator cur;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>m;
		for(j=0;j<m;j++)
		{
			cin>>temp;
			sta[i].insert(temp);
		}
	}
	cin>>j;
	for(i=0;i<j;i++)
	{
		sim=0;
		dif=0;
		cin>>m>>n;
		for(cur=sta[m-1].begin();cur!=sta[m-1].end();cur++)
			if(sta[n-1].find(*cur)!=sta[n-1].end())
				sim++;
		dif=sta[m-1].size()+sta[n-1].size()-sim; 
		l=sim/dif*100;
		printf("%.2f%%\n",l);
	}
}
