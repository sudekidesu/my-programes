#include<stdio.h>
#include<math.h>
int main()
{
	int m,t/*tΪ������*/;
	float k,s,a,b;
	s=0;
	scanf("%d",&m);
	for(t=1;t<=m;t++)
	{
	b=1;//�׳�
	for(a=1;a<=t;a++)
	{
		
		b*=a;
	}//�׳� 
	k=pow(m,t)/b;//ÿһ�� 
	s-=k*pow(-1,t);
	}
	printf("%f",s);
	return 0;
}
