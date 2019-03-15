#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    int num[20];
    scanf("%d",&n);
    scanf("%d",&num[0]);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&num[i]);
        num[i]+=num[i-1];
    }
    if(n==1||(n==2&&num[0]*2==num[1]))
        printf("-1\n");
    else
        for(int i=0;i<n;i++)
        {
            if(num[i]*2!=num[n-1])
            {
                printf("%d\n",i+1);
                for(int j=0;j<=i;j++)
                {
                    printf("%d%c",j+1,j==i?'\n':' ');
                }
                break;
            }
        }
}//
