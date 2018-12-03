#include<cstdio>
int main()
{
	int i,t,o;
	char s[130];
	scanf("%d",&t);
	getchar();
	for(o=0;o<t;o++)
	{
		for(i=0;;i++)
		{
			s[i]=getchar(); 
			if(s[i]=='\n')
				break;
			if(s[i]==']'&&s[i-1]=='[')
			{
				s[i]='\0';
				s[i-1]='\0';
				i-=2;
			}
			if(s[i]==')'&&s[i-1]=='(')
			{
				s[i]='\0';
				s[i-1]='\0';
				i-=2;
			}
		}
		if(s[0]=='\n')
			printf("Yes\n");
		else
			printf("No\n");
 	} 
}
