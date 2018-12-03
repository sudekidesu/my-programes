#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char str[1005],str1[1005],temp;
	int i,j,l;
	scanf("%s",str+1);
	l=strlen(str+1);
	for(i=1;i<=l+1;i++)
		str1[i]=str[i];
	sort(str+1,str+1+l);
	for(i=l;i>1;i--)
		for(j=i;j>1;j--)
			if(str[j]!=str1[j]||str[j-1]!=str1[j-1])
			{
				temp=str[j-1];
				str[j-1]=str[j];
				str[j]=temp;
				printf("%d %d\n",j,j-1);
			}
}
