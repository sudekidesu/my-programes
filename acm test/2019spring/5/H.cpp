#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
string name[2000005];
map<string,int> m;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        cin>>name[i];
    for(int i=n-1;i>=0;i--)
        if(m[name[i]]==0)
        {
            cout<<name[i]<<endl;
            m[name[i]]=1;
        }
}
