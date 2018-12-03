#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,i,k,d,m=0;
	char A[100000]={0};
	char B[100000]={0};
	while(scanf("%s %s",A,B)!=EOF)
	{
		d=0;
		m=-1;
		a=strlen(A);
		b=strlen(B);
		for(i=0;i<a;i++)
		{
			for(k=m+1;k<b;k++)
			{
				if(A[i]==B[k])
					{
						d++;
						m=k;
						break;
					}
			}
		}
	if(d==a)
		printf("Yes\n");
	else
		printf("No\n");
	}
	return 0; 
 } 
