#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int num[200005][26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char s[200005];
int main()
{
	char a;
	int T,i,n,m,j,k,o,l;
	scanf("%d",&T);
	for(o=1;o<=T;o++)
	{
		printf("Case #%d:\n",o);
		scanf("%d %d",&n,&m);
		scanf("%s",s+1);
		for(i=1;i<=n;i++)
		{
			num[i][0]=num[i-1][0];
			num[i][1]=num[i-1][1];
			num[i][2]=num[i-1][2];
			num[i][3]=num[i-1][3];
			num[i][4]=num[i-1][4];
			num[i][5]=num[i-1][5];
			num[i][6]=num[i-1][6];
			num[i][7]=num[i-1][7];
			num[i][8]=num[i-1][8];
			num[i][9]=num[i-1][9];
			num[i][10]=num[i-1][10];
			num[i][11]=num[i-1][11];
			num[i][12]=num[i-1][12];
			num[i][13]=num[i-1][13];
			num[i][14]=num[i-1][14];
			num[i][15]=num[i-1][15];
			num[i][16]=num[i-1][16];
			num[i][17]=num[i-1][17];
			num[i][18]=num[i-1][18];
			num[i][19]=num[i-1][19];
			num[i][20]=num[i-1][20];
			num[i][21]=num[i-1][21];
			num[i][22]=num[i-1][22];
			num[i][23]=num[i-1][23];
			num[i][24]=num[i-1][24];
			num[i][25]=num[i-1][25];
			num[i][s[i]-'A']++;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&j,&k);
			for(l=0;l<26;l++)
				if(num[k][l]-num[j-1][l]>0)
				{
					printf("%d\n",num[k][l]-num[j-1][l]);
					break;
				}
		}
	}
 }
