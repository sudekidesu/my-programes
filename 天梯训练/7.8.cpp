#include<cstdio>
int main()
{
	int qz[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char dz[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	char sfz[100][19];
	int i,j,d,g,f,k=0;
	scanf("%d",&d);
	for(i=0;i<d;i++)
		scanf("%s",sfz[i]);
	for(i=0;i<d;i++)
	{
		g=0;
		for(j=0;j<17;j++)
		{
			f=sfz[i][j]-'0';
			g+=f*qz[j];
		}
		g%=11;
		if(sfz[i][17]!=dz[g])
		{
			printf("%s\n",sfz[i]);
			k++;
		}
	}
	if(k==0)
		printf("All passed");
}
