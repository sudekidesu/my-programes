#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF)
	{
		int j[6]={0,0,0,0,0,0},i,k; 
		j[a-1]=j[b-1]=j[c-1]=1;
		if(j[0]==j[5]&&j[0]==0)
			cout<<1<<endl;
		else if(j[1]==j[4]&&j[1]==0)
			cout<<2<<endl;
		else if(j[2]==j[3]&&j[2]==0)
			cout<<3<<endl;
		else
			cout<<0<<endl;
	}
	return 0;
}
