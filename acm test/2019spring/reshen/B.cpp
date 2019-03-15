#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int p1=max(3*a/10,a-a*c/250),p2=max(3*b/10,b-b*d/250);
    printf("%s\n",p1>p2?"Misha":p1==p2?"Tie":"Vasya");
}
