#include<iostream>
using namespace std;
#include<cstdio>
int main()
{
	int l[2000];
	int t[2000];
	int r[2000];
	int n,i;
	scanf("%d",&n);
	t[1]=l[1]=r[1]=0;
	for(i=2;i<=n;i++)
	{
		t[i]=r[i]=0;
		scanf("%d",&l[i]);
		if(r[l[i]]==0)
			t[l[l[i]]]--;
		t[l[i]]++;
		r[l[i]]=1;
	}
	for(i=1;i<=n;i++)
		if(r[i]==1&&t[i]<3)
		{
			cout<<"No"<<endl;
			return 0;
		}
	cout<<"Yes"<<endl;
}
