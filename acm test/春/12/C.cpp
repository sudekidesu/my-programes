#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int T,i,red=0,sum=0,max=0;
	char str[10];
	cin>>T;
	for(i=0;i<T;i++)
	{
		scanf("%s",str);
		if(str[0]=='r')
		{
			sum+=1;
			red+=1;
			if(1>max)
				max=1;
		}
		if(str[0]=='y')
		{
			sum+=2;
			if(2>max)
				max=2;
		}
		if(str[0]=='g')
		{
			sum+=3;
			if(3>max)
				max=3;
		}
		if(str[0]=='b'&&str[1]=='r')
		{
			sum+=4;
			if(4>max)
				max=4;
		}
		if(str[0]=='b'&&str[1]=='l'&&str[2]=='u')
		{
			sum+=5;
			if(5>max)
				max=5;
		}
		if(str[0]=='p')
		{
			sum+=6;
			if(6>max)
				max=6;
		}
		if(str[0]=='b'&&str[1]=='l'&&str[2]=='a')
		{
			sum+=7;
			if(7>max)
				max=7;
		}
	}
	sum+=red*max;
	if(red==T)
		sum=1;
	printf("%d",sum);
}
