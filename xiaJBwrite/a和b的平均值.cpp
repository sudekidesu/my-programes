#include<stdio.h>
int main()
{
	float a,b;
	float ave;
	printf("a=");
		scanf("%f",&a);
	printf("b=");
		scanf("%f",&b);
	ave=(a+b)/2;
	printf("a/2=%.1f\n"
		   "b/2=%.1f\n"
		   "a+b=%.1f\n"
		   "(a+b)/2=%.1f\n"
		   "\n"
		   ,a/2,b/2,a+b,ave);
	main();
	getchar();
	getchar();
	return 0;
 }
