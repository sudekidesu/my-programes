#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int num[300];
    int B;
    int n;
    scanf("%d %d",&n,&B);
    int a=0,b=0;
    bool flag=false;
    vector<int> s;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        if(flag)
        {
            s.push_back(num[i]>num[i-1]?num[i]-num[i-1]:num[i-1]-num[i]);
            flag=false;
        }
        if(num[i]%2)
            a++;
        else
            b++;
        if(a==b)
            flag=true;
    }
    sort(s.begin(),s.begin()+s.size());
    int ans=0;
    vector<int>::iterator i;
    i=s.begin();
    while(i!=s.end()&&B>0)
    {
        if(*i<=B)
        {
            ans++;
            B-=*i;
        }
        i++;
    }
    printf("%d\n",ans);
}
