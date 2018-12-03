#include<stdio.h>
#include<string.h>
char s[100001];
int t[100001]={0};
int main()
{
	int i,cur=0,last=0; 
	scanf("%s",s+1);
	for(i=1;i<=strlen(s+1);i++)
	{
		if(s[i]=='[')
			cur=0;
		else if(s[i]==']')
			cur=last;
		else
		{
			t[i]=t[cur];
			t[cur]=i;
			if(cur==last)
				last=i;
			cur=i;
		}
	}
	for(i=t[0];i!=0;i=t[i])
		printf("%c",s[i]);
	return 0;
 }
