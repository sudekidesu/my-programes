#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a;
        scanf("%d",&a);
        int num=1;
        do
        {
            if(a%2==1)
                num*=2;
            a>>=1;
        } while(a>0);
        printf("%d\n",num);
    }
}
