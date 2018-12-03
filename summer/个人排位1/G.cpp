#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	string s="0";
	int n,i,j,k;
	scanf("%d",&n);
	for(j=1;j<=n;j++)
	{
		k=pow(2,j-1)-1;
		if(j!=1)
			s+="0";
		while(k--)
			if(s[k]=='0')
				s+="1";
			else
				s+="0";
	}
	cout<<s<<endl;
}
