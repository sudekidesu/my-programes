#include<stdio.h>  
#include<string.h>  
#define inf -2100000000  
#define MAXN 1000005  
int a[MAXN],dp[MAXN],tdp[2][MAXN],sum[MAXN];  
inline int max (int a,int b)  
{  
    return a>b?a:b;  
}  
int main()  
{  
    int m,n,i,j,k,res;  
    while (scanf("%d%d",&m,&n)!=EOF)  
    {  
        sum[0]=0;  
        for (i=1; i<=n; ++i)  
        {  
            scanf("%d",&a[i]);  
            sum[i]=sum[i-1]+a[i];  
        }  
        memset(dp,0,sizeof(dp));  
        for (i=0;i<=n;++i) tdp[0][i]=0;  
        for (i=0;i<=n;++i) tdp[1][i]=inf;  
        k=0;  
        for (i=1; i<=m; ++i)  
        {  
            tdp[1-k][i-1]=inf;  
            for (j=i; j<=n; ++j)  
            {  
                if (i==j) dp[j]=sum[j];  
                else  
                {  
                    dp[j]=max(dp[j-1],tdp[k][j-1])+a[j];  
                }  
                tdp[1-k][j]=max(tdp[1-k][j-1],dp[j]);  
            }  
            k=1-k;  //tdp[0]?tdp[1]????  
        }  
        res=inf;  
        for (i=m; i<=n; ++i)  
        {  
            if (dp[i]>res) res=dp[i];  
        }  
        printf("%d\n",res);  
    }  
    return 0;  
} 
