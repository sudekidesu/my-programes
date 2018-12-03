#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
	string s;
    while(T--)
    {
        cin>>s;
        int i;
        int n=0;
            for(int j=1;j<=s.length();j++)
            {
                if(s.length()%j==0)
                {
                    string temp=s.substr(0,j);
                    string t=temp;
                    while(s.length()>temp.length())
                    	temp+=t;
                    if(temp==s)
                    	n=j;
                }
                if(n)
                    break;
            }
      	printf("%d\n",n);
      	if(T)
      		printf("\n");
    }
}
