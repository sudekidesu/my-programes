#include<cstdio>
int fadong(int *pai,int n,int j)
{
	int i,dmg=0;
	for(i=n;i>n-j;i--)
	{
		if(*(pai+(i*3)+1)==1)
			dmg+=*(pai+(i*3)+2);
		if(*(pai+(i*3)+1)==2)
			dmg+=*(pai+(i*3)+2)*(j+i-n);
		if(*(pai+(i*3)+1)==3)
			break;
		if(*(pai+(i*3)+1)==4)
			i--;
	}
	return dmg;
}
int main()
{
	int pai[1000][3],n,i,j=1,dmg=0;
	while(scanf("%d",&n)!=EOF)
	{
		j=1;
		dmg=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&pai[i][0],&pai[i][1]);
			if(pai[i][1]==1||pai[i][1]==2)
				scanf("%d",&pai[i][2]);
		}
		for(i=0;i<n;i++)
		{
			if(pai[i][0]<=pai[i+1][0]&&i!=n-1)
			{
				j++;
				continue;
			}
			dmg+=fadong(pai[0],i,j);
			j=1;
		}
		printf("%d\n",dmg);
	}
}
