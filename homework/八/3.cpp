#include<stdio.h>
#include<string.h>
int main()
{
	char s[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char a[100];
	int i=0,k;
	scanf("%d",&k);
	for(;k>0;)
	{
		a[i]=s[k%16];
		k/=16;
		i++;
	}
	for(i=strlen(a)-1;i>=0;i--)
		printf("%c",a[i]);
 } 
