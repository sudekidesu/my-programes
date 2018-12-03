#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int a[3];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    sort(a,a+3);
    printf("%d\n",a[2]<a[0]+a[1]?0:a[2]-a[0]-a[1]+1);
}
