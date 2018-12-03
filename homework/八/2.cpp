#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char s1[100],s2[100];
	scanf("%s",s1);
	for(i=0;i<strlen(s1);i++)
		s2[strlen(s1)-i-1]=s1[i];
	printf("%s",s2);
}
