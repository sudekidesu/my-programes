#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,c;
	int i,j;
	char cube[300][300];
	for(i=0;i<300;i++)
		for(j=0;j<300l;j++)
			cube[i][j]='.';
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d",&a,&b,&c);
		{
			for(i=2*b;i<=2*(c+b);i+=2)
				for(j=0;j<=a*2;j+=2)
					cube[i][j]='+';
			for(i=2*b;i<=2*(c+b);i+=2)
				for(j=1;j<a*2;j+=2)
					cube[i][j]='-';
			for(i=2*b+1;i<2*(c+b);i+=2)
				for(j=0;j<=2*a;j+=2)
					cube[i][j]='|';
		}//正面 
		{
			for(i=0;i<2*b;i+=2)
				for(j=2*b-i;j<=2*b-i+2*a;j+=2)
					cube[i][j]='+';
			for(i=0;i<2*b;i+=2)
				for(j=2*b-i+1;j<=2*b-i+2*a;j+=2)
					cube[i][j]='-';
			for(i=1;i<2*b;i+=2)
				for(j=2*b-i;j<=2*b-i+2*a;j+=2)
					cube[i][j]='/';
		}//上面 
		{
			for(j=2*a;j<=2*(a+b);j+=2)
				for(i=2*(a+b)-j;i<=2*(a+b)-j+2*c;i+=2)
					cube[i][j]='+';
			for(j=2*a;j<=2*(a+b);j+=2)
				for(i=2*(a+b)-j+1;i<=2*(a+b)-j+2*c;i+=2)
					cube[i][j]='|';
			for(j=2*a+1;j<=2*(a+b);j+=2)
				for(i=2*(a+b)-j+2;i<=2*(a+b)-j+2*c;i+=2)
					cube[i][j]='/';
		}//侧面 
		for(i=0;i<=2*(c+b);i++)
		{
			for(j=0;j<=2*(b+a);j++)
			{
				printf("%c",cube[i][j]);
				cube[i][j]='.';
			}
			printf("\n");
		}
	}
}
