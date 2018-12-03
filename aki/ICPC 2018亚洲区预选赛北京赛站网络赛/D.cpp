#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int num[2000005];
bool jud[2000005];
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
        for(int i=0;i<n;i++)
            scanf("%d",&num[2*i]);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[2*i-1]);
            num[2*i-1]=-num[2*i-1];
        }
        int temp=0;
        for(int i=2*n-1;i>=0;i--)
        {
            if((num[i]<=0&&i%2==1)||(c+num[i]<0))
            {
                for(int j=6*n+i;j>i;j--)
                {
                	int t;
                	if(temp>=0)
                		t=j;
                	if(temp==0&&j%2==0&&temp+num[j%(2*n)]>=0)
                		continue;
                    temp+=num[j%(2*n)];
                    if(temp>=0||(j<=t-2*n+1&&temp+c>=0))
                        temp=0;
                    if(temp+c<0)
                        	jud[j%(2*n)]=false;
                }
                break;
            }
        }
        for(int i=0;i<2*n;i+=2)
            if(jud[i]==true)
            {
                ans=i/2+1;
                break;
            }
        printf("%d\n",ans);
    }
}
