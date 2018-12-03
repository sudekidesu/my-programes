#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,i,sum,T,t;
	int j[50];
	char s[50];
	scanf("%d",&T);
	for(b=0;b<T;b++)
	{
		sum=0;
		i=0;
		scanf("%s",&s[0]);
		t=strlen(s);
		for(a=0;a<t;a++)
			{
				if(s[a]==79)
					i++;
				else
					i=0;
				sum+=i;
				}
		printf("%d\n",sum);
	}
	return 0;
 } 
