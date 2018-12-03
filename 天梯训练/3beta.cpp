#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[10000];
	char a;
	int i,b,jud[256]={0};
	for(i=0;;i++)
	{
		str[i]=getchar();
		if(str[i]=='\n')
		{
			str[i]='\0';
			break;
		}
	}
	b=strlen(str);
	for(i=0;;i++)
	{
		a=getchar();
		if(a=='\n')
			break;
		else
			jud[(int)a]=1;
	}
	for(i=0;i<b;i++)
		if(jud[str[i]]==0)
			cout<<str[i];
}
