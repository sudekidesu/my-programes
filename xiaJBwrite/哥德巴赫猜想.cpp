/*验证哥德巴赫猜想*/ 
#include<stdio.h>
int judgeprime(int a)//检验质数，是质数返回1，不是返回0 
{
	int b=1 ;
		while(b*b<=a)
		{
			b++;
			if(a%b==0)
				return 0;
			if(a<=b*b)
				return 1;
		}
}
int main()
{
	int m,a,i,x=1,y=1,j=1;
	m=10000;
	for(i=4;i<=m;i=i+2)//穷举4-2000的偶数 
	{
		for(a=2;a<=i-2;a++)//穷举检验是否符合存在两个质数之和是i 
		{
			x=judgeprime(a); 
			y=judgeprime(i-a);
			if(x==1&&y==1)//符合即打印并跳出循环 
			{
				printf("%d=%d+%d\t",i,a,i-a);
				if(i%4==0)
				printf("\n");
	//			break;
				if(x==0&&a==i-2)//不符合即用变量标明 
				{
					j=0;
					printf("%d=%d+%d",i,a,i-a);//将不符合的数打印 
				}
			}
		}
		if(j==0)//不符合便不继续穷举 
		{
			printf("错误\n") ;
			break;
		}
	}
	if(j==1)//若穷举结束仍然正确即猜想正确 
	printf("正确\n");
}
 
