#include<stdio.h>
void drawline(int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("-");
	printf("\n");
	return;
 } 
int main()
{
	int n;
	n=30;
	drawline(n);
	return 0;
}
