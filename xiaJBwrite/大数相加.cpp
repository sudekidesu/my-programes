#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,i,k;
	char A1[1000];
	char B1[1000];
	int A[1000]={0};
	int B[1000]={0};
	int S[1001]={0};
	printf("第一个加数：");
	scanf("%s",&A1);
	printf("               +\n第二个加数：");
	scanf("%s",&B1);
	printf("\n           =");
	a=strlen(A1);
	b=strlen(B1);
	for(i=0;i<a;i++)
		A[i]=A1[a-i-1]-'0';
	for(i=0;i<b;i++)
		B[i]=B1[b-i-1]-'0';
	if(a<b)
	{
		a=a^b;
		b=b^a;
		a=a^b;
	}
	for(i=0;i<=a;i++)
	{
		S[i]+=A[i]+B[i];
		if(S[i]>=10)
		{
			S[i]-=10;
			S[i+1]++;
		}
	}
	for(i=0;i<=a;i++)
	{
		if(S[a-i])
			{
				for(k=a-i;k>=0;k--)
					printf("%d",S[k]);
				break; 
			}
	}
	printf("\n\n");
	main();
 } 
