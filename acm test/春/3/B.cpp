#include<iostream>
#include<cmath>
using namespace std;
class points
{	
	public:
		int x,y;
		int connect[750];
		void getpoint()
		{
			cin>>x>>y;
		}
};
//////////////////////////////////////////////////
int search(int N);
void searcha(int a,int N);
//////////////////////////////////////////////////
points point[750];
int way[750][750]={0};
//////////////////////////////////////////////////
int main()
{
	int N,M,i,j,a,b,k=0,qdst,qdstmin;
	int ways[750][2]={0};
	cin>>N;
	for(i=0;i<N;i++)
	{
		point[i].getpoint();
		for(j=0;j<N;j++)
			point[i].connect[j]=0;
	}
	cin>>M;
	for(i=0;i<M;i++)
	{
		cin>>a>>b;
		point[a-1].connect[b-1]=1;
		point[b-1].connect[a-1]=1;
	}
	for(i=0;i<N;i++)
			for(j=0;j<N;j++)
			{
				qdst=pow(point[i].x-point[j].x,2)+pow(point[i].y-point[j].y,2);
				way[i][j]=qdst;
			}
	for(k=0;;k++)
	{
		searcha(0,N);
		if(search(N))
			break;
		for(i=0;i<N;i++)
		{
			if(point[0].connect[i]==0)
			{
				j=i;
				break;
			}
		}
		qdst=way[0][j];
		i=0;
		for(M=0;M<N;M++)
		{
			if(way[M][j]<qdst&&way[M][j]>0)
				i=M;
		}
		way[i][j]=-1;
		way[j][i]=-1;
		point[i].connect[j]=1;
		point[j].connect[i]=1;
		ways[k][0]=i+1;
		ways[k][1]=j+1;
	}
	cout<<endl;
	for(i=0;i<k;i++)
		cout<<ways[i][0]<<" "<<ways[i][1]<<endl;
}
///////////////////////////////////////////////////
int search(int N)
{
	int i;
	for(i=1;i<N;i++)
	{
		if(point[0].connect[i]==0)
			return 0;
	}
	return 1;
}
void searcha(int a,int N)
{
	point[0].connect[a]=1;
	int i;
	for(i=a+1;i<N;i++)
	{
		if(point[a].connect[i]==1)
			searcha(i,N);
	}
}
