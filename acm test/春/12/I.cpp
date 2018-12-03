#include<iostream>
using namespace std;
int main()
{
	int H[25];
	int N,i,j,T,k;
	cin>>N;
	for(i=1;i<=N;i++)
		cin>>H[i];
	cin>>T;
	j=T;
	for(i=1;i<=N;i++)
		if(T%H[i]<j)
		{
			j=T%H[i];
			k=i;
		}
	cout<<H[k]<<endl;
	return 0;
 } 
