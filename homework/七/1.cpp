#include<stdio.h>
int a[10]={0};
void fun()
{
	float sum=0;
	int i; 
	for(i=0;i<10;i++)
		sum+=a[i];
	sum/=10.0;
	printf("%.2f\n",sum);
	for(i=0;i<10;i++)
		if(a[i]<sum)
			printf("%5d",a[i]);
	for(i=0;i<10;i++)
		if(a[i]>sum)
			printf("%5d",a[i]);
 } 
 int main()
 {
 	int i;
 	for(i=0;i<10;i++)
 		scanf("%d",&a[i]);
 	fun();
 }
