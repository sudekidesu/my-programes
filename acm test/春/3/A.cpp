#include<stdio.h>
int a,b,j;
char t[100][100]={'\n'};
int T[100][100]={0};
void ss(int p,int q)
{
	if(T[p][q]==0&&t[p][q]=='W')
	{
		T[p][q]=j;
		if(p-1>=0&&q-1>=0)
			ss(p-1,q-1);
		if(p-1>=0)
			ss(p-1,q);
		if(p-1>=0&&q+1<b)
			ss(p-1,q+1);
		if(q-1>=0)
			ss(p,q-1);
		if(q+1<b)
			ss(p,q+1);
		if(p+1<a&&q-1>=0)
			ss(p+1,q-1);
		if(p+1<a)
			ss(p+1,q);
		if(p+1<a&&q+1<b)
			ss(p+1,q+1);
	}
}
void bh()
{
	int i,k;
	for(i=0;i<a;i++)
		for(k=0;k<b;k++)
			if(t[i][k]=='W'&&T[i][k]==0)
				{
					j++;
					ss(i,k);
				}
}
int main()
{
		scanf("%d %d",&a,&b);
		getchar();
		j=0;	
		int m,n;
		for(m=0;m<a;m++)
				scanf("%s",&t[m]);
		bh();
		printf("%d",j);
	}
