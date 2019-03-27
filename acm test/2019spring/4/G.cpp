#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxm = 1000000 + 100;//ç‚¹çš„æ•°é‡
int num[maxm];
int Max,Min,sum;
struct tree
{
    int left,right;
    int maxx,minn;
    int sum;
}t[maxm*3 + 100];
void push_up(int k)
{
    t[k].maxx =max( t[k<<1].maxx, t[k<<1|1].maxx);
    t[k].minn =min( t[k<<1].minn, t[k<<1|1].minn);
    t[k].sum =t[k<<1].sum+t[k<<1|1].sum;
}
void make(int l,int r,int k)//1ï¼Œnï¼Œ1
{
    if(l==r)
    {
        t[k].left=t[k].right=l;
        t[k].maxx=t[k].minn=t[k].sum=num[l];
        return;
    }
    t[k].left=l;
    t[k].right=r;
    make(l,(l+r)>>1,k<<1);
    make(((l+r)>>1)+1,r,k<<1|1);
    push_up(k);
}//å»ºæ ‘
void Query(int l,int r,int k)//å·¦ç«¯ç‚¹ï¼Œå³ç«¯ç‚¹ï¼Œï¼Œ1
{
    if(l<=t[k].left&&r>=t[k].right)
    {
        Max=max(Max,t[k].maxx);
        Min=min(Min,t[k].minn);
        sum+=t[k].sum;
        return;
    }
    if(l<=(t[k].left+t[k].right)>>1)
        Query(l,r,k<<1);
    if(r>(t[k].left+t[k].right)>>1)
        Query(l,r,k<<1|1);
}//æŸ¥è¯¢æ®µå’Œ
int ans[1000005][2];
int main()
{
    int n,w;
    scanf("%d %d",&n,&w);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    make(1,n,1);
    for(int i=1;i+w-1<=n;i++)
    {
        Min=0x3f3f3f3f;
        Max=-0x3f3f3f3f;
        Query(i,i+w-1,1);
        ans[i][0]=Min;
        ans[i][1]=Max;
    }
    for(int i=1;i+w-1<=n;i++)
        printf("%d%c",ans[i][0],i+w-1==n?'\n':' ');
    for(int i=1;i+w-1<=n;i++)
        printf("%d%c",ans[i][1],i+w-1==n?'\n':' ');
}
