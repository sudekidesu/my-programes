#include<stdio.h>
#include<string.h>
#include<math.h>

int fac(int n)
{
	int i;
	if(n==0) return n;
	for(i=(n-1);i>0;i--)
	{
		if(n%i==0&&i!=1) return i;
	}
	
	return n;
}


int main()
{
	char str[100];
	int n,i,pla;
	
	while(1)
	{
str[0]=getchar();
if(str[0]=='\n')
break;
scanf("%s",str+1);
getchar();
	i=strlen(str)-1;
	n=0;
	pla=0;
	for(i;i>=0;i--)
	{
		if(str[i]>=48&&str[i]<=57)
		{
			n=n+((str[i]-'0')*pow(10,pla));
			pla++;
		}
	}
	printf("%d\n",fac(n));
	
	}
	
	return 0;
}

