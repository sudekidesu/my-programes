#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int T,n,k;
    long long dot[105][2];
    long long ans[200000];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%lld %lld",&dot[i][0],&dot[i][1]);
        int cnt=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int l=j+1;l<n;l++)
                {
                    ans[cnt]=dot[i][0]*dot[j][1]+dot[j][0]*dot[l][1]+dot[l][0]*dot[i][1]-dot[i][0]*dot[l][1]-dot[j][0]*dot[i][1]-dot[l][0]*dot[j][1];
                    if(ans[cnt]<0)
                        ans[cnt]=-ans[cnt];
                    if(ans[cnt]==0)
                        cnt--;
                    cnt++;
                }
        nth_element(ans,ans+cnt-k,ans+cnt);
        printf("%lld%s\n",ans[cnt-k]/2,ans[cnt-k]%2?".50":".00");
    }
}
