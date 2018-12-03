#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        if(a%2==0||b%2==0||c%2==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
