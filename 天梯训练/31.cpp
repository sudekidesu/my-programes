#include<cstdio>
#include<cstring>
#include<cmath>
int main()
{
	char a[10],b[10];
	int m=0,n=0,la,lb,ja=1,jb=1;
	int i;
	scanf("%s %s",a,b);
	la=strlen(a);
	lb=strlen(b);
	for(i=0;i<la;i++)
		if(a[i]<'0'||a[i]>'9')
			ja=0;
	if(ja==1)
		for(i=0;i<la;i++)
			m+=(a[la-i-1]-'0')*pow(10,i);
	for(i=0;i<lb;i++)
		if(b[i]<'0'||b[i]>'9')
			jb=0;
	if(jb==1)
		for(i=0;i<lb;i++)
			n+=(b[lb-i-1]-'0')*pow(10,i);
	if(la<=3&&m>0)
		printf("%d + ",m);
	else
		printf("? + ");
	if(lb<=3&&n>0)
		printf("%d = ",n);
	else
		printf("? = ");
	if(la<=3&&m>0&&lb<=3&&n>0)
		printf("%d",m+n);
	else
		printf("?");
 } 
