#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  int n,m;
  char temp;
  char s[200];
  freopen("ascii.in","r",stdin);
  freopen("ascii.out","w",stdout);
  while(scanf("%d %d",&n,&m)==2)
  {
	  int num1=0,num2=0;
	  for(int i=0;i<n;i++)
	  {
	  	scanf("%s",s);
	    for(int j=0;j<m;j++)
	    {
	      temp=s[j];
	      if(temp=='\\'||temp=='/')
	        num1++;
	      if(temp=='.'&&num1%2)
	        num2++;
	    }
	  }
	  printf("%d\n",num1/2+num2);
  }
}
