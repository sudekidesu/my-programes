#include<cstdio>
void chi(int *zi,int i,int j)
int main()
{
	int zi[4][4]={11,10, 9, 8,
				 12, 0, 0, 7,
				  1, 0, 0, 6,
				  2, 3, 4, 5};
	int n,m,i,j,num,dir,p;
	scnaf("%d",&n);
	for(m=0;m<n;m++)
	{
		p=0;
		scanf("%d %d",&num,&dire);
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
				if(zi[i][j]==num)
				{
					switch(dire)
						case 1:i++;
						case 2:i--;
						case 3:j--;
						case 4:j++;
					chi(zi[0],i,j);
					p=1;
					break;
				}
			if(p=1)
				break;
		}
	}
 } 
 void chi(int *zi,int i,int j)
 {
 	if(zi[i][j]>6)
 	{
 		
	 }
 }
