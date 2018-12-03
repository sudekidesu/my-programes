#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int A[1000005];
int B[1000005];
bool jud[1000005];
int main()
{
    int n,c;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int ans=-1;
        memset(jud,1,sizeof(jud));
        scanf("%d %d",&n,&c);
        for(int i=1;i<n;i++)
            scanf("%d",&A[i]);
        scanf("%d",&A[0]);
        for(int i=1;i<n;i++)
            scanf("%d",&B[i]);
        scanf("%d",&B[0]);
        for(int i=1;i<=n;i++)
        {
            int sum=c;
            for(int j=0;j<i+n;j++)
            {
                sum+=A[(i+j)%n];
                if(sum<0)
                    break;
                sum-=B[(i+j)%n];
                if(sum<0)
                    break;
            }
            if(sum>=0)
            {
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
}
