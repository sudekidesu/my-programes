#include<stdio.h>
#include<string.h>
int main()
{
	char a[20];
	char cases[1000][20];
	char search[20];
	int i,k,j;
	for(i=0;;i++)
	{
		scanf("%s",&a);
		strcat(cases[i],a);
		getchar();
		if((cases[i+1][0]=getchar())=='\n')
			break;
	}
	while(scanf("%s",&search)!=EOF)
	{
		j=0;
		for(k=0;k<i+1;k++)
			if(!strncmp(cases[k],search,strlen(search)))
				j++;
		printf("%d\n",j);
	}
}
