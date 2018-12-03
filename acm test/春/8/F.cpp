#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int dist[65][65];
	int point[65][2];
	int T,o,i,j,n;
	cin>>T;
	for(o=0;o<T;o++)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>point[i][0]>>point[i][1];
			for(j=0;j<=i;j++)
				dist[j][i]=fabs(point[j][0]-point[i][0])+fabs(point[j][1]-point[i][1]);
		}
	}
}
