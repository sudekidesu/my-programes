#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(string a,string b)
{
	if(a.length()<b.length())
		return true;
	else
		return false;
}
int main()
{
	int n,i;
	cin>>n;
	string s[105];
	for(i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n,cmp);
	for(i=1;i<n;i++)
		if(s[i].find(s[i-1])==-1)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	cout<<"YES"<<endl;
	for(i=0;i<n;i++)
		cout<<s[i]<<endl;
}
