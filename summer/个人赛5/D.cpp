#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct seat
{
	int width;
	int a;
	int num;
	seat()
	{
		a=0;
	}
}s[300000];
bool cmp(seat a,seat b)
{
	if(a.width<b.width)
		return true;
	else
		return false;
}
int main()
{
	int n,m,i;
	char j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i].width);
		s[i].num=i;
	}
	getchar();
	sort(s+1,s+1+n,cmp);
	m=n*2;
	while(m--)
	{
		scanf("%c",&j);
		if(j=='0')
		{
			for(i=1;i<=n;i++)
				if(s[i].a==0)
				{
					s[i].a++;
					printf("%d",s[i].num);
					break;
				}
		}
		else
		{
			for(i=n;i>0;i--)
				if(s[i].a==1)
				{
					s[i].a++;
					printf("%d",s[i].num);
					break;
				}
		}
		if(m!=0)
			printf(" ");
	}
}
