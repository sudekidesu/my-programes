#include<bits/stdc++.h>
using namespace std;
int pro[10001][3],stu[31][10002][5];
int main()
{
	int T,i,j,a,b,c,mmm,ss,Extreme[3],Steadfast[3],Solid[2],Relentless[2];
	cin>>T;
	while(T--)
	{
		int n,m,k;
		Extreme[1]=300;
		Steadfast[1]=0;
		Solid[1]=Solid[0]=0;
		Relentless[0]=Relentless[1]=0;
		scanf("%d %d %d",&n,&m,&k);
		for(i=1;i<=n;i++)
		{
			pro[i][0]=0;
			pro[i][1]=pro[i][2]=300;
		}
		for(i=1;i<=m;i++)
			stu[i][10001][0]=stu[i][10001][0]=stu[i][10001][2]=0;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				stu[i][j][0]=stu[i][j][1]=stu[i][j][2]=stu[i][j][3]=stu[i][j][4]=0;
		for(i=0;i<k;i++)
		{
			scanf("%d %d %d %d:%d",&a,&b,&c,&mmm,&ss);
			if(c==1)
			{
				if(mmm<Extreme[1]||(mmm==Extreme[1]&&ss<Extreme[3]))
				{
					Extreme[1]=mmm;
					Extreme[2]=ss;
					Extreme[0]=b;
				}
				if(mmm>Steadfast[1]||(mmm==Steadfast[1]&&ss>Steadfast[3]))
				{
					Steadfast[1]=mmm;
					Steadfast[2]=ss;
					Steadfast[0]=b;
				}
				if(pro[a][1]>mmm||(pro[a][1]==mmm&&pro[a][2]>ss))
				{
					pro[a][1]=mmm;
					pro[a][2]=ss;
					pro[a][0]=b;
				}
				stu[b][a][1]++;
				if(stu[b][a][2]==0&&stu[b][a][3]==0)
					stu[b][a][4]=1;
				if(stu[b][a][0]==0)
					stu[b][10001][0]++;
			}
			else
			{
				stu[b][a][0]++;
				stu[b][a][2]=mmm;
				stu[b][a][3]=ss;
				stu[b][a][4]=0;
			}
		}
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
			{
				if(stu[i][j][1]==1)
					stu[i][10001][1]+=stu[i][j][0];
				stu[i][10001][0]+=stu[i][j][4];
			}
		for(i=1;i<=m;i++)
			if(stu[i][10001][0]>Solid[1])
			{
				Solid[1]=stu[i][10001][0];
				Solid[0]=i;
			}
		for(i=1;i<=m;i++)
			if(stu[i][10001][1]>Relentless[1])
			{
				Relentless[1]=stu[i][10001][1];
				Relentless[0]=i;
			}
		for(i=1;i<=n;i++)
		{
			if(pro[i][0]==0)
				printf("-1");
			else
				printf("%d",pro[i][0]);
			if(i!=n)
				printf(" ");
		}
		printf("\n");
		printf("%d %d %d %d\n",Extreme[0],Steadfast[0],Solid[0],Relentless[0]);
	}
}
