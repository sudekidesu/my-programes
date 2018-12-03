#include<stdio.h>
#include<string.h>
int next[100001]={0};
char s[100001];
int main()
{
	int i,cur=0,last=0;
	scanf("%s",s+1);
	for(i=1;i<strlen(s+1);i++)
	{
		if(s[i]=='[')
			cur=0;
		else if(s[i]==']')
			cur=last;
		else
		{
			next[i]=next[cur];
			next[cur]=i;
			if(last==cur)
				last=i;
			cur=i;
		}
	}
	for(i=next[0];i!=0;i=next[i])
		printf("%c",s[i]);
 } 
