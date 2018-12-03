#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string a,b;
int main()
{
    while(cin>>a>>b)
    {
        for(int i=0;i<b.length();i++)
            a="1"+a+"1";
        int flag=a.length()-b.length();
        for(int i=0;i<a.length()-b.length();i++)
            for(int j=0;j<b.length()&&(a[i+j]!='2'||b[j]!='2');j++)
                if(j==b.length()-1||i+j==a.length()-1)
                    flag=min(flag,(int)max(a.size()-b.size(),i+b.size())-min((int)b.size(),i));
        cout<<flag<<endl;
    }
}
