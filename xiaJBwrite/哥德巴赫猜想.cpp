/*��֤��°ͺղ���*/ 
#include<stdio.h>
int judgeprime(int a)//��������������������1�����Ƿ���0 
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
	for(i=4;i<=m;i=i+2)//���4-2000��ż�� 
	{
		for(a=2;a<=i-2;a++)//��ټ����Ƿ���ϴ�����������֮����i 
		{
			x=judgeprime(a); 
			y=judgeprime(i-a);
			if(x==1&&y==1)//���ϼ���ӡ������ѭ�� 
			{
				printf("%d=%d+%d\t",i,a,i-a);
				if(i%4==0)
				printf("\n");
	//			break;
				if(x==0&&a==i-2)//�����ϼ��ñ������� 
				{
					j=0;
					printf("%d=%d+%d",i,a,i-a);//�������ϵ�����ӡ 
				}
			}
		}
		if(j==0)//�����ϱ㲻������� 
		{
			printf("����\n") ;
			break;
		}
	}
	if(j==1)//����ٽ�����Ȼ��ȷ��������ȷ 
	printf("��ȷ\n");
}
 
