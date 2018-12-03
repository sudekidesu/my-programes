#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    string s,t;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        cin>>s;
        t=s;
        int l=s.length();
        for(int i=0;i<l;i++)
        {
            if(s[l-1]=='G')
                s="G"+s;
            else if(s[l-1]=='A')
                s="A"+s;
            else if(s[l-1]=='C')
                s="C"+s;
            else if(s[l-1]=='T')
                s="T"+s;
            s=s.substr(0,l);
            if(s<t)
                t=s;
        }
        cout<<t<<endl;
    }
}
