#include<iostream>
#include<cstdio>
#include<cstring>
// #include<time.h>
using namespace std;
int main()
{
    int a,b,c,d;
    int T=0;
    while(scanf("%d %d %d %d",&a,&b,&c,&d),++T)
    {
        if(a==-1)
            break;
        a%=23;
        b%=28;
        c%=33;
        for(int i=d+1;i<=42504;i++)
            if((i%23==a)&&(i%28==b)&&(i%33==c))
            {
                printf("Case %d: the next triple peak occurs in %d days.\n",T,i-d);
                break;
            }
    }
}
