#include<cstdio>
int main()
{
	double Y,low,high;
	int o,t;
	scanf("%d",&t);
	for(o=0;o<t;o++)
	{
		low=0;
		high=100;
		scanf("%lf",&Y);
		if(Y<6||Y>807020306)
		{
			printf("No solution!\n");
			continue;
		}
		else
			for(;;)
			{
				double i=(low+high)/2;
				double j=i*(i*(i*(8*i+7)+2)+3)+6;
				if(high-low<0.000001||high<low)
				{
					printf("%.4lf\n",high>low?high:low);
					break;
				}
				else if(j<Y)
					low=(low+high)/2;
				else if(j>Y)
					high=(low+high)/2;
			}
	}
}
