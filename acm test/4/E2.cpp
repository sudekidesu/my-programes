#include<stdio.h>
#include<string.h>
int main()
{
	int a[4][4]={0};
	int b[4][4]={0};
	int T,o;
	if(scanf("%d",&T)!=EOF)
	{
	for(o=0;o<T;o++)
	{
		int i,k,m=0,n=0,p,q;
		char s[16],t[16];
		scanf("%s",&s);
		scanf("%s",&t);
		if(s[0]=='f')
				{
					for(p=0;p<4;p++)
						{
							for(q=0;q<4;q++)
								{
									a[p][q]=1;
								}
						}
				}
		if(s[0]!='f'&&s[0]!='e')
		for(i=1;i<strlen(s);i++)
		{
			if(s[i]=='e')
					a[m][0]=a[m][1]=a[m][2]=a[m][3]=0;
			else if(s[i]=='f')
					a[m][0]=a[m][1]=a[m][2]=a[m][3]=1;
			else if(s[i]=='p')
				{
					for(k=0;k<4;k++)
					{
						i++;
						if(s[i]=='e')
							a[m][k]=0;
						else if(s[i]=='f')
							a[m][k]=1;
					}
				}
			m++;
		}
		m=0;
		if(t[0]=='f')
				{
					for(p=0;p<4;p++)
						{
							for(q=0;q<4;q++)
								{
									b[p][q]=1;
								}
						}
				}
		if(t[0]!='f'&&t[0]!='e')
		for(i=1;i<strlen(t);i++)
		{
			if(t[i]=='e')
					b[m][0]=b[m][1]=b[m][2]=b[m][3]=0;
			else if(t[i]=='f')
					b[m][0]=b[m][1]=b[m][2]=b[m][3]=1;
			else if(t[i]=='p')
				{
					for(k=0;k<4;k++)
					{
						i++;
						if(t[i]=='e')
							b[m][k]=0;
						else if(t[i]=='f')
							b[m][k]=1;
					}
				}
			m++;
		}
		for(i=0;i<4;i++)
		{
			for(k=0;k<4;k++)
				{
					if(a[i][k]||b[i][k])
						n+=64;
				}
		}
		printf("There are %d black pixels.\n",n);
	}
	}
 } 
