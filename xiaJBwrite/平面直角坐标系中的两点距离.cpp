#include <stdio.h>
#include <math.h>
int main()
{
int x1,y1,x2,y2,m1,m2;
float m;
	printf("输入第一个点坐标\n");
	scanf ("%d%d",&x1,&y1);
	printf("输入第 二个点坐标\n");
	scanf ("%d%d",&x2,&y2);
	m1=pow((x1-x2),2);
	m2=pow((y1-y2),2);
	m=sqrt(m1+m2);
	printf("%f",m);
	scanf ("%c") ;
	scanf ("%c") ;
	return 0;
}
