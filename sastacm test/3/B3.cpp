#include<stdio.h>
#include<string.h>
int main()
{
	int i,k;
	char A1[101][101];
	char B1[101][101];
	int A[101][101]={0};
	int B[101][101]={0};
	int T,o;
	scanf("%d",&T);
	for(o=0;o<T;o++)
	{
		printf("\n");
		scanf("%s",&A1[o]);
		if(A1[o][0]=='0'&&strlen(A1[o])==1)
		{
			A[o][0]=10;
			continue;
		}
		for(i=0;i<strlen(A1[o]);i++)
				A[o][i]=A1[o][strlen(A1[o])-i-1]-'0';
		for(;;)
		{
			scanf("%s",&B1[o]);
			if(B1[o][0]=='0'&&strlen(B1[o])==1)
				break;
			for(i=0;i<strlen(B1[o]);i++)
				B[o][i]=B1[o][strlen(B1[o])-i-1]-'0';
			for(i=0;i<=100;i++)
			{
				A[o][i]+=B[o][i];
				B[o][i]=0;
				B1[o][i]='\0';
				if(A[o][i]>=10)
				{
					A[o][i]-=10;
					A[o][i+1]++;
				}
			}
		}

	}
	for(o=0;o<T;o++)
	{
		if(o!=0)
			printf("\n");
		printf("\n"); 
		for(i=0;i<=100;i++)
		{
			if(A[o][0]==10)
				{
					printf("0");
					break;
				}
			if(A[o][100-i])
				{				
					for(k=100-i;k>=0;k--)
						printf("%d",A[o][k]);
					break; 
				}
		}
	}
}
