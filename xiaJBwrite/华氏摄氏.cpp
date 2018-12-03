/*Name : 华氏度转摄氏度*/
#include<stdio.h>
int main( )
{
	float a,b;
	printf("请输入华氏度\n");
	scanf("%f",&a) ;
	b=(a-32)*5/9;
	printf("摄氏度: %f\n",b);
	getchar(); 
	getchar(); 
	return 0;
}

