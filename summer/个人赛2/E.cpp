#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n,i,t=0;
	string temp1,temp2;
	char s[1000005];
	cin>>n>>s;
	temp1=s[0];
	temp2=temp1+s[1];
	if(temp1+temp1==temp2)
			t=0;
	for(i=1;2*i+1<n;i++)
	{
		temp1+=s[i];
		temp2+=s[2*i];
		temp2+=s[2*i+1];
		//cout<<temp1<<" "<<temp2<<endl;
		if(temp1+temp1==temp2)
			t=i;
	}
	printf("%d\n",n-t);
}
