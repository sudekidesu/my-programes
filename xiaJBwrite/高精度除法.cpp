#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,d;
	int c,e,i,f,n,n2;
	printf("�����ʽ��������<�ո�>����<�ո�>��ȷλ��\n�������ֶ�Ϊ0ʱ��������\n");
	while(scanf("%lf %lf %d",&a,&b,&c)!=EOF)
	{
		if(a==0&&b==0&&c==0)
			return 0;
		if(b==0)
			{
				printf("��������Ϊ0\n");
				continue;
			}
		if(a>=b)
			{
				e=d=a/b;
				printf("%d",e);
				f=b+0.5;
				e=a;
				e=e%f*10;
			 }
		else
			{
				printf("0");
				e=a*10;
			}
		printf(".");
		for(i=0;i<c;i++)
		{
			if(e<b)
			{
				printf("0");
				e*=10;
			 }
			else
			{
				d=e/b;
				n=d;
				printf("%d",n);
				f=b+0.5;
				e=e%f*10;
			}
		 } 
		d=e/b;
		n2=d;
		if(n2>=5)
			{
				printf("\b%d\n",n+1);
			}
		else
			printf("\n");
	}
	 return 0;
 }
