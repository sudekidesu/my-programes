#include<iostream>
#include<cstring>
using namespace std;
char s[2005],a[2005],b[2005];
int main()
{
	int T,o,i,j,l,la,lb,k,jud;
	cin>>T;
	for(o=0;o<T;o++)
	{
		jud=1;
		cin>>a>>b>>s;
		i=0;
		j=0;
		l=strlen(s);
		la=strlen(a);
		lb=strlen(b);
		for(i=0;i<la;i++)
			for(;j<l;j++)
				if(a[i]==s[j])
				{
					s[j]='\0';
					break;
				}
		j=0;
		for(i=0;i<lb;i++)
			for(;j<l;j++)
				if(a[i]==s[j])
				{
					s[j]='\0';
					break;
				}
		for(i=0;i<l;i++)
			if(s[i]!='\0')
			{
				jud=0;
				break;
			}
		if(jud==1)
			cout<<"YES,memeda!"<<endl;
		else
			cout<<"Oh,i want memeda!"<<endl;
	}
}
