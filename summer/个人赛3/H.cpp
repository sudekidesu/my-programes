#include<iostream>
using namespace std;
struct tree
{
	int a,c;
	tree()
	{
		a=c=-1000;
	}
}t[15e1504];
int m,n;
void make(int num,int a,int c)
{
	if(a<=0||a>15e1504||num>15e1504)
		return;
	t[num].a=a;
	t[num].c=c;
	make(num*2,a-1,c+1);
	make(num*2+1,a*2,c+1);
}
int main()
{
	int i;
	cin>>n>>m;
	make(1,n,0);
	for(i=1;i<15e1504;i++)
		if(t[i].a==m)
		{
			cout<<t[i].c<<endl;
			return 0;
		}
 } 
