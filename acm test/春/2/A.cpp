#include<cstdio>
void jia(int *a);
int doxor(int *a,int *b,int *c);
int main()
{
	int a[11]={0},b[11]={0},c[11]={0};
	int i,j,k,n,num=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		jia(a);
		for(j=0;j<11;j++)
			b[j]=0;
		for(j=0;j<i;j++)
		{
			jia(b);
			for(k=0;k<11;k++)
				c[k]=0;
			for(k=0;k<j;k++)
			{
				jia(c);
				if ((a[0]==b[0])==c[0]&&k<j-1)
				{
					jia(c);
					k++;
				}
				if(i<j+k&&!doxor(a,b,c))
					num++;
			}
		}
	}
	printf("%d",num);
 }
void jia(int *m)
{
	int i;
	m[0]++;
	for(i=0;i<11;i++)
		if(m[i]==2)
		{
			m[i+1]++;
			m[i]--;
			m[i]--;
		}
}
int doxor(int *a,int *b,int *c)
{
	int i;
	for(i=0;i<11;i++)
	{
		if(!(a[i]==b[i])==c[i]&&i==10)
			return 0;
		if(!(a[i]==b[i])==c[i])
			continue;
		return 1;
	}
}
