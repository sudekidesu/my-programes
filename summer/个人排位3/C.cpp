#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,x,y,i,num=0;
	scanf("%d %d %d",&n,&x,&y);
	char s[300005];
	s[0]='1';
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
		if(s[i]=='0'&&s[i-1]=='1')
			num++;
	if(x>y)
		printf("%d\n",num*y);
	else
		printf("%d\n",(num-1)*x+y);
}
