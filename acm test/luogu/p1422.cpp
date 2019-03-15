#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    double n;
    cin>>n;
    double ans;
    ans+=0.4463*min(n,(double)150);
    if(n>150)
        ans+=0.4663*(min(n,(double)400)-150);
    if(n>400)
        ans+=0.5663*(n-400);
    printf("%.1f",ans);
}
