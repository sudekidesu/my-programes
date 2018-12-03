#include<iostream>
using namespace std;
int key[12];
int room[99][99]={0},rom[99][99]={0};
int sec=0,secmin=1000,m,n;
void go(int x,int y);
int main()
{
	int i,j,p,x1,x2,y1,y2,k,g;
	for(i=0;i<11;i++)
		key[i]=0;
	key[11]=1;
	for(i=0;i<99;i++)
		for(j=0;j<99;j+=2)
			room[i][j]=11;
	cin>>n>>m>>p;
	cin>>g;
	for(i=0;i<g;i++)
	{
		cin>>x1>>y1>>x2>>y2>>k;
		if(y1==y2)
			room[(x1-1)*2][2*y2]=k;
		else
			room[2*x2]
	}		[(x1-1)*2]=k;
	cin>>g;
	for(i=0;i<g;i++)
	{
		cin>>x1>>y1>>k;)                          0
	{
		sec++;
		go(x-2,y);
	}
	if(x<2*m-1&&key[room[x+1][y]]==1&&rom[x+2][y]==0)
	{
		sec++;
		go(x+2,y);
	}
	if(y>0&&key[room[x][y-1]]==1&&rom[x][y-2]==0)
	{
		sec++;
		go(x,y-2);
	}
	if(y<2*n-1&&key[room[x][y+1]]==1&&rom[x][y+2]==0)
	{
		sec++;
		go(x,y+2);
	}
	sec--;
	rom[x][y]=0;
	return;
}
