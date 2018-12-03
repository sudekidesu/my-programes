#include<stdio.h>
int A[2006]={1};
int B[2006]={1};
int C[2006]={1};
int D[2006]={1};
void fun(int *a,int c)
{
	extern int A[2006];
	extern int B[2006];
	extern int C[2006];
	extern int D[2006];
	int i;
	for(i=0;i<=c;i++)
	{
		*(a+i)=A[i]+B[i]+C[i]+D[i];
		if(*(a+i)>=10)
		{
			*(a+i+1)+=*(a+i)/10;
			*(a+i)%=10;
		}
	}
 } 
 int main()
 {
 	extern int A[2006];
	extern int B[2006];
	extern int C[2006];
	extern int D[2006];
	int num,i,k,s;
	while(scanf("%d",&num)!=EOF)
	{
	if(num<=4)
		{
			printf("1");
		}
	else
	{
	for(i=5;i<=num;i++)
		{
			switch(i%4)
				{
					case 1:fun(A,2*(i-3)/7+3);
							break;
					case 2:fun(B,2*(i-3)/7+3);
							break;
					case 3:fun(C,2*(i-3)/7+3);
							break;
					case 0:fun(D,2*(i-3)/7+3);
				}
		}
	switch(num%4)
				{
					case 1:for(i=0;i<=2*(num-3)/7+3;i++)
							{
								if(A[2*(num-3)/7+3-i])
									{
										for(k=2*(num-3)/7+3-i;k>=0;k--)
											{
												printf("%d",A[k]);
												if(k)
													A[k]=B[k]=C[k]=D[k]=0;
												else
													A[k]=B[k]=C[k]=D[k]=0;
											}
										break; 
									}
							}
							break;
					case 2:for(i=0;i<=2*(num-3)/7+3;i++)
							{
								if(B[2*(num-3)/7+3-i])
									{
										for(k=2*(num-3)/7+3-i;k>=0;k--)
											{
												printf("%d",B[k]);
												if(k)
													A[k]=B[k]=C[k]=D[k]=0;
												else
													A[k]=B[k]=C[k]=D[k]=0;
											}
										break; 
									}
							}
							break;
					case 3:for(i=0;i<=2*(num-3)/7+3;i++)
							{
								if(C[2*(num-3)/7+3-i])
									{
										for(k=2*(num-3)/7+3-i;k>=0;k--)
											{
												printf("%d",C[k]);
												if(k)
													A[k]=B[k]=C[k]=D[k]=0;
												else
													A[k]=B[k]=C[k]=D[k]=0;
											}
										break; 
									}
							}
							break;
					case 0:for(i=0;i<=2*(num-3)/7+3;i++)
							{
								if(D[2*(num-3)/7+3-i])
									{
										for(k=2*(num-3)/7+3-i;k>=0;k--)
											{
												printf("%d",D[k]);
												if(k)
													A[k]=B[k]=C[k]=D[k]=0;
												else
													A[k]=B[k]=C[k]=D[k]=0;
											}
										break; 
									}
							}
				}
			}
			printf("\n");
	}
}
