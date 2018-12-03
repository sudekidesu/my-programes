#include<stdio.h>
int main()
{
	int n,h1,h2,m1,m2,s1,s2,i,hs,ms,ss;
	scanf("%d",&n);
  	for(i=0;i<n;i++)
 		 {
 		 	scanf("%d %d %d %d %d %d",&h1,&m1,&s1,&h2,&m2,&s2);
 		 	hs=h1+h2;
 		 	ms=m1+m2;
 		 	ss=s1+s2;
 		 	while(ss>=60)
 		 		{
 		 			ms++;
 		 			ss-=60;
				  }
			while(ms>=60)
				{
					hs++;
					ms-=60;
				}
			printf("%d %d %d\n",hs,ms,ss);
		  }
	return 0;
}
