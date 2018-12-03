#include<stdio.h>
#define m1 31
#define m2 28
#define m3 31
#define m4 30
#define m5 31
#define m6 30
#define m7 31
#define m8 31
#define m9 30
#define m10 31
#define m11 30
#define m12 31
int main()
{
  int y,m,d,e,f;
  while(scanf("%4d %2d %2d",&y,&m,&d)!=EOF)
  {
  		if(y<=0||y>=10000||m<=0||m>=13||d<=0||d>=32)
  			{
  				printf("illegal\n");
  				break;
  			}
  		else if(y%4==0&&m==2&&d>=30)
  			{
  				printf("illegal\n");
  				break;
  			}
  		else if(y%4!=0&&m==2&&d>=29)
  			{
  				printf("illegal\n");
  				break;
  			}
  		f=(y-2007)/4;
  		e=6+(y-2007)*365+f;
  		e=e%7;
  		printf("%d\n",e);
  }
}
