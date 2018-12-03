#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,t,num=0;
	char s[10000];
	char temp;
	cin>>n;
	t=n;
	cin>>s;
	sort(s,s+n);
	int i;
	while(t)
	{
		for(i=0;i<n;i++)
			if(s[i]!='0')
			{
				temp=s[i];
				s[i]='0';
				t--;
				break;
			}
		for(i=0;i<n;i++)
			if(s[i]==temp+1)
			{
				temp=s[i];
				s[i]='0';
				t--;
			}
		num++;
	}
	cout<<num<<endl;
}
