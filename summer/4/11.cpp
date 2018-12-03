#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,d=0,l;
		char s[200000];
		int a[200000]={0};
		scanf("%s",s);
		l=strlen(s);
		for(i=0;i<l;i++)
			a[i]=0;
		if(s[0]=='?')
			s[0]='1';
		if((s[0]=='0'&&s[1]!='*'&&s[1]!='+'&&s[1]!='?')||s[0]=='+'||s[0]=='*'||s[l-1]=='+'||s[l-1]=='*')
			d=1;
		for(i=0;i<l-1&&d==0;i++)
		{
			if(s[i+1]=='?')
			{
				if(s[i]=='0'&&i+2<l&&(s[i-1]=='+'||s[i-1]=='*'||i==0))
					s[i+1]='+';
				else
					s[i+1]='1';
			}
			if((s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||a[i]==1)&&s[i+1]=='0')
				a[i+1]=1;
			if(((s[i]=='+'||s[i]=='*')&&(s[i+1]=='+'||s[i+1]=='*'))||(s[i]=='0'&&a[i]==0&&s[i+1]!='+'&&s[i+1]!='*'))
			{
				d=1;
				break;
			}
		}
		if(d==1)
			printf("IMPOSSIBLE\n");
		else
			printf("%s\n",s);
	}
 } 
