#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,t;
    scanf("%d %d",&n,&t);
    int a[30005]={0};
    for(int i=1;i<n;i++)
        scanf("%d",&a[i]);
    int i=1;
    while(i<t)
        i+=a[i];
    if(i==t)
        printf("YES\n");
    else
        printf("NO\n");
}
