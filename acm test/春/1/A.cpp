#include<cstdio>
#include<cstring>
void judge(char A[100000],char B[100000]);
char  A[100000],B[100000];
int main()
{
	int t,o; 
	scanf("%d",&t);
	for(o=0;o<t;o++)
	{
		scanf("%s %s",A,B);
		judge(A,B);
	}
 } 
 void judge(char *A,char *B)
 {
 	int i,j,m=strlen(A),n=strlen(B);
 	if(m<n)
 	{
 		printf("Bob\n");
 		return;
	 }
 	for(i=0;i<=m-n;i++)
 	{
 		if(A[i]==B[0])
 		{
 			for(j=0;j<n;j++)
 			{
 				if(j==n-1&&A[i+j]==B[j])
 				{
 					printf("Alice\n");
 					return;
				 }
				 if(A[i+j]==B[j])
 					continue;
 				if(j!=n-1)
 					break;
			 }
		 }
	 }
	 for(i=m-1;i>=n-1;i--)
 	 {
 		if(A[i]==B[0])
		{
 			for(j=0;j<n;j++)
 			{
 				if(j==n-1&&A[i-j]==B[j])
 				{
 					printf("Alice\n");
 					return;
				 }
				if(A[i-j]==B[j])
				 	continue;
 				if(j!=n-1)
 					break;
			 }
		 }
		 if(j==n-1&&A[i+j]==B[j])
	  		break;
	 }
	 printf("Bob\n");
 }
