#include<stdio.h>
#include<string.h>
#include<memory.h> 
int main()
{
	int a,i,m=1,n=2,k;
	char st[3][100000];
	while(scanf("%s",&st[0])!=EOF)
	{
		a=0;
		for(i=0;i<strlen(st[0]);)
		{
			if(st[0][i]=='[')
			{
				a=0;
				i++;
				for(;;)
				{
					if(st[0][i]=='['||st[0][i]=='\0')
						{
							strcat(st[m],st[n]);
							m=m^n;
							n=n^m;
							m=m^n;
							a=strlen(st[m]);
							memset(st[m],'\0',a);
							break;							
						}
					if(st[0][i]==']'||st[0][i]=='\0')
						{
							strcat(st[m],st[n]);
							m=m^n;
							n=n^m;
							m=m^n;
							a=strlen(st[m]);
							memset(st[m],'\0',a);
							break;							
						}
						st[m][a]=st[0][i];
						i++;
						a++;
				}
			}
			else if(st[0][i]==']')
			{
				i++;
				a=0;
				for(;;)
				{
					if(st[0][i]==']')
						{
							i++;
							continue;
						}	
					if(st[0][i]=='['||st[0][i]=='\0')
						{
							strcat(st[n],st[m]);
							a=strlen(st[m]);
							memset(st[m],'\0',a);
							break;
						}
						st[m][a]=st[0][i];
						i++;
						a++;
				}
			}
			else if(st[0][i]!='\0')
				for(a=0;;)	
				{
					if(st[0][i]=='['||st[0][i]=='\0')
						break;
					if(st[0][i]==']')
						{
							i++;
							continue;
						}
					st[n][a]=st[0][i];
					i++;
					a++;
				}
		}
		printf("%s\n",st[n]);
		a=strlen(st[n]);
		memset(st[n],'\0',a);
	}
 } 
