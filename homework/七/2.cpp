#include<stdio.h>
int main()
{
	int i,j,arr[10];
	for(i=0;i<10;i++)
		scanf("%d",&arr[i]);
	j=0;
	for(i=0;i<10;i++)
		if(arr[i]<arr[j])
			j=i;
	i=arr[j];
	arr[j]=arr[0];
	arr[0]=i;
	j=0;
	for(i=0;i<10;i++)
		if(arr[i]>arr[j])
			j=i;
	i=arr[j];
	arr[j]=arr[9];
	arr[9]=i;
	for(i=0;i<10;i++)
		printf("%4d",arr[i]);
}
