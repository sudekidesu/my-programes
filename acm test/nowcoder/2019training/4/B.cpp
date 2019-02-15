#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    int a,ans=0;
    scanf("%d %d",&n,&m);
    if(n==1&&m==2)
        printf("RL\n");
    else if(n==2&&m==1)
        printf("DU\n");
    else if((n%2==1&&m%2==1)||n==1||m==1)
        printf("-1\n");
    else
    {
        if(n%2==0)
        {
            for(int i=0;i<n-1;i++)
                printf("D");
            printf("R");
            for(int i=0;i<n/2;i++)
            {
                if(i!=0)
                    printf("U");
                for(int i=0;i<m-2;i++)
                    printf("R");
                printf("U");
                for(int i=0;i<m-2;i++)
                    printf("L");
            }
            printf("L\n");
        }
        else
        {
            for(int i=0;i<m-1;i++)
                printf("R");
            printf("D");
            for(int i=0;i<m/2;i++)
            {
                if(i!=0)
                    printf("L");
                for(int i=0;i<n-2;i++)
                    printf("D");
                printf("L");
                for(int i=0;i<n-2;i++)
                    printf("U");
            }
            printf("U\n");
        }
    }
}
