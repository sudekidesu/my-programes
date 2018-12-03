#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	set<char> str;
	char s[100005];
	char se[100005];
	int l,n,m,i,j,k;
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	j=0;
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(str.find(s[i])==str.end())
		{
			str.insert(s[i]);
			se[j]=s[i];
			j++;
		}
	}
	sort(se,se+j);
	if(m>n)
	{
		printf("%s",s);
		for(i=0;i<m-n;i++)
			printf("%c",se[0]);
		printf("\n");
	}
	else
	{
		s[m]='\0';
		for(i=m-1;i>=0;i--)
			if(s[i]==se[j-1])
				s[i]=se[0];
			else
				break;
		for(k=j-1;k>=0;k--)
			if(se[k]==s[i])
			{
				s[i]=se[k+1];
				break;
			}
		printf("%s\n",s);
	}
}
