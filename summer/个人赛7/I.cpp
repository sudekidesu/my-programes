#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int i,j,k,n,jud=0;
	string s="<3";
	char c[300005];
	string a;
	scanf("%d",&n);
	while(n--)
	{
		cin>>a;
		s+=a+"<3";
	}
	scanf("%s",c);
	i=0;
	j=0;
	k=s.length();
	n=strlen(c);
	for(;i<k&&j<n;)
	{
		if(s[i]==c[j])
			i++;
		j++;
	}
	printf("%s\n",i==k?"yes":"no");
}

