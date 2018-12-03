#include <stdio.h>
int pl(int a,int b)
 {
 	return (a+b);
 }
 int mi(int a,int b)
 {
 return (a-b);
 }
 float mu(float a,float b)
 {
 return (a*b);
 }
 int main()
 {
 	int s,a,b;
 	float consult;
 	printf("加输入1，减输入2，乘输入3，除输入4\n");
 	scanf("%1d",&s);
 	if (s==1)
	{
	 printf("_ + _ = ???\n");
 	scanf("%d%d",&a,&b);
 	consult=pl(a,b);
 	printf("%d + %d = %f \n",a,b,consult);
 	scanf ("%c");
 	return 0;
 	}
 	else if (s==2)
 	{
	 printf("_ - _ = ???\n");
 	scanf("%d%d",&a,&b);
  	consult=mi(a,b);
 	printf("%d - %d = %f \n",a,b,consult);
 	scanf("%c");
 	return 0;
 	}
 	else if (s==3)
 	{
	 printf("_ * _ = ???\n");
 	scanf("%d%d",&a,&b);
 	consult=mu(a,b);
 	printf("%d * %d = %f \n",a,b,consult);
 	scanf("%c");
 	return 0;
 	}
 	else if (s==4)
 	{
 	float c,d;
	printf("_ / _ = ???\n");
 	scanf("%f%f",&c,&d);
 	printf("%f / %f = %f \n",c,d,c/d);
 	scanf("%c");
 	return 0;
 	}
 	else
 	{
 		printf("error\n");
 		scanf("%c");
 		return 0;
	 }
 }
