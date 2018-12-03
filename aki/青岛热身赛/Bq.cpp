#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int num[1000001]={0};
        int n;
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++)
        {
            scanf("%d",&a);
            num[a]++;
            if(num[a]>1)
                b=a;
        }
         printf("%d\n",b);
    }
}
