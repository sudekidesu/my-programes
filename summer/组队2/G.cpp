#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct camera
{
  int num,a,c;
  double b;
  camera()
  {
    num=-1;
    a=b=c=0;
  }
};
int main()
{
  int T;
  scanf("%d",&T);
  getchar();
  while(T--)
  {
	camera temp,best1,best2;
	vector<int> be;
	be.push_back(0);
	vector<int>::iterator i;
    int n,b=0,num;
    char s;
    scanf("%d",&n);
    getchar();
    while(n--)
    { 
  	  b++;
      scanf("%c",&s);
      getchar();
      if(s=='C')
      {
      	num=best1.c>best2.c?best2.num:best1.num;
      	if(best1.c==best2.c)
      		num=best1.num<best2.num?best1.num:best2.num;
        be.push_back(num);
      }
      if(s=='P')
      {
        temp.num=b;
        scanf("%d %lf %d",&temp.a,&temp.b,&temp.c);
        getchar();
        if(temp.a>best1.a)
        	best1=temp;
        if(temp.b>best2.b)
        	best2=temp;
      }
    }
    for(i=be.begin()+1;i!=be.end();i++)
    {
    	if(i!=be.begin()+1)
    		printf(" ");
    	printf("%d",*i);
	}
	printf("\n");
  }
}
