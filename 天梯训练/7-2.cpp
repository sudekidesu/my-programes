#include<cstdio>
int main()
{
	int hh,mm,i;
	scanf("%d:%d",&hh,&mm);
	if(hh<12||(hh==12&&mm==0))
	{
		printf("Only %02d:%02d.  Too early to Dang.",hh,mm);
		return 0;
	}
	else
	{
		if(mm>0)
			hh++;
		hh-=12;
		for(i=0;i<hh;i++)
			printf("Dang");
	}
}
