#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i,n,a[2000];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n); 
	cout<<a[(n-1)/2]<<endl;
}
