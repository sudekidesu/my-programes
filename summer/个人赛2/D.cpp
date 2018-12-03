#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[1000];
	int n,i;
	cin>>s;
	n=strlen(s);
	for(i=0;i<n-1;i++)
		if(s[i]!='a'&&s[i]!='i'&&s[i]!='u'&&s[i]!='e'&&s[i]!='o'&&s[i]!='n'&&s[i+1]!='a'&&s[i+1]!='i'&&s[i+1]!='u'&&s[i+1]!='e'&&s[i+1]!='o')
		{
			cout<<"NO"<<endl;
			return 0;
		}
	if(s[n-1]!='a'&&s[n-1]!='i'&&s[n-1]!='u'&&s[n-1]!='e'&&s[n-1]!='o'&&s[n-1]!='n')
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
}
