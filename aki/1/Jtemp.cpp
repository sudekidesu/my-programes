#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,num=0;
    int t;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(t==1)
            num++;
    }
    if(num%3==1||num%3==2)
        printf("Win\n");
    else
        printf("Lose\n");
    // main();
}
