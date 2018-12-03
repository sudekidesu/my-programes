#include<cstdio>
#include<cstring>
int main()
{
	int a[105]={0},i,j;
	char s[105]={'\0'};
	while(scanf("%s",s+1)!=EOF)
	{
		for(i=0;i<strlen(s+1)+1;i++)
			a[i]=i+1;
		for(i=0;i<strlen(s+1)+10;i++)
		{
			for(j=0;a[j]!=0;j=a[j])
			{
				if(s[a[j]]=='o'&&s[a[a[j]]]=='o')
				{
					s[a[j]]='O';
					a[a[j]]=a[a[a[j]]];
					break;
				}
				else if(s[a[j]]=='O'&&s[a[a[j]]]=='O')
				{
					a[j]=a[a[a[j]]];
					break;
				}
			}
		}
		for(j=0;a[j]!=0;j=a[j])
			printf("%c",s[a[j]]);
		printf("\n");
		for(i=0;i<105;i++)
		{
			s[j]='\0';
			a[i]=0;
		}
	}
 } 
