#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string s[1005];
	int num[15];
	int n,m,k,i,j,o;
	int nA;
	int T;
	cin>>T;
	for(o=1;o<=T;o++)
	{
		for(i=0;i<15;i++)
			num[i]=0;
		cin>>n>>m>>k;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			for(j=0;j<m;j++)
				if(s[i][j]=='A')
					num[j]++;
		}
		nA=0;
		for(i=0;i<m;i++)
			if(num[i]*(m-num[i])>=k)
				nA++;
		cout<<(pow(2,nA)-1)*pow(2,m-nA)<<endl;
	}
}
