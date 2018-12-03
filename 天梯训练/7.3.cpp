#include<cstdio>
#include<cstring>
int jug(char *str,char a,char *lett);
int main()
{
	int i=0,t;
	char str[10000],lett[10000],a;
	while((a=getchar())!='\n')
	{
		str[i]=a;
		i++;
	}
	i=0;
	scanf("%s",lett);
	t=strlen(str);
	for(i=0;i<t;i++)
	{
		if(str[i]!='\0'&&jug(str,str[i],lett))
			continue;
		printf("%c",str[i]);
	}
}
int jug(char *str,char a,char *lett)
{
	int t=strlen(lett),j;
	for(int i=0;i<t;i++)
		if(a==lett[i])
		{
			for(j=0;j<t;j++)
				if(str[j]==a)
					str[j]='\0';
			return 1;
		}
	return 0;
}
