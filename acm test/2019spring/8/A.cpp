#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
//我也不知道时间复杂度
#include<cstring>
#define maxm (int)1e4
bool ifprime[maxm];//true为素数，false为和数
struct point
{
    int s;
    vector<int> e;
}v[10000];
void prime()
{
	memset(ifprime,1,sizeof(ifprime));
	ifprime[0]=ifprime[1]=false;
	for(int i=2;i<maxm;i++)
		if(ifprime[i])
			for(int k=2;k*i<maxm;k++)
				if(ifprime[k*i])
					ifprime[k*i]=false;
    for(int i=1000;i<10000;i++)
        for(int j=i+1;j<10000;j++)
            if(ifprime[i]&&ifprime[j]&&(i%1000==j%1000||(i/1000==j/1000&&i%100==j%100)||(i/100==j/100&&j%10==i%10)||i/10==j/10))
            {
                v[i].e.push_back(j);
                v[j].e.push_back(i);
            }
 }

int main()
{
    prime();
    int n;
    scanf("%d",&n);
    while(n--)
    {
        for(int i=1000;i<10000;i++)
            v[i].s=0x3f3f3f3f;
        int a,b;
        scanf("%d %d",&a,&b);
        priority_queue<int> q;
        q.push(a);
        v[a].s=0;
        while(q.size()!=0)
        {
            //printf("%d ",q.size());
            int a=q.top();
            q.pop();
            for(int i=0;i<v[a].e.size();i++)
            {
                if(v[v[a].e[i]].s>1+v[a].s)
                {
                    q.push(v[a].e[i]);
                    v[v[a].e[i]].s=1+v[a].s;
                }
            }
        }
        printf("%d\n",v[b].s);
    }
}
