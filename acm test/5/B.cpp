#include<stdio.h>
int a,b,j;
char t[100][100];
int T[100][100];
void ss(int p,int q)
{
	if(T[p][q]==0&&t[p][q]=='@')
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
			if(t[i][k]=='@'&&T[i][k]==0)
				{
					j++;
					ss(i,k);
				}
}
int main()
{
	for(;;)
	{
		scanf("%d %d",&a,&b);
		getchar();
		if(a==0&&b==0)
			return 0;
		j=0;	
		int m,n;
		for(m=0;m<a;m++)
				scanf("%s",&t[m]);
		bh();
		printf("%d\n",j);
		for(m=0;m<a;m++)
			for(n=0;n<b;n++)
				T[m][n]=0;
	}
 } 
