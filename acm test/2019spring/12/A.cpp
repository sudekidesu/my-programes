#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    n=min(n,m);
    if(n%2==0)
        printf("Malvika\n");
    else
        printf("Akshat\n");
}
