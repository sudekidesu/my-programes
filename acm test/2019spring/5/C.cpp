#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
deque<long long> q;
int main()
{
    long long n,k,maxx=-1;
    scanf("%I64d %I64d",&n,&k);
    if(k>n)
    {
        while(n--)
        {
            long long temp;
            scanf("%I64d",&temp);
            if(maxx<temp)
                maxx=temp;
        }
        printf("%I64d\n",maxx);
    }
    else
    {
        long long cnt=0;
        for(long long i=1;i<=n;i++)
        {
            long long temp;
            scanf("%I64d",&temp);
            q.push_back(temp);
        }
        while(cnt<k)
        {
            long long a=q.front();
            q.pop_front();
            long long b=q.front();
            q.pop_front();
            q.push_front(max(a,b));
            q.push_back(min(a,b));
            if(a>b)
                cnt++;
            else
                cnt=1;
        }
        printf("%I64d\n",q.front());
    }
}
