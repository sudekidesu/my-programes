#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxm = 50000 + 100;//ç‚¹çš„æ•°é‡
int num[maxm];
int b[maxm];
int ma,mi;
struct tree
{
	 int left,right;
	 int maxx,minn;
}t[maxm*3 + 100];
void push_up(int k)
{
		t[k].maxx =max( t[k<<1].maxx, t[k<<1|1].maxx);
		t[k].minn =min( t[k<<1].minn, t[k<<1|1].minn);
}
void make(int l,int r,int k)//1ï¼Œnï¼Œ1
{
		if(l==r)
		{
			t[k].left=t[k].right=l;
			t[k].maxx=t[k].minn=num[l];
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
			ma=max(ma,t[k].maxx);
            mi=min(mi,t[k].minn);
			return;
		}
		if(l<=(t[k].left+t[k].right)>>1)
			Query(l,r,k<<1);
		if(r>(t[k].left+t[k].right)>>1)
			Query(l,r,k<<1|1);
}//æŸ¥è¯¢æ®µå’Œ
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    make(1,n,1);
    while(q--)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        mi=10000001;
        ma=-1;
        Query(l,r,1);
        printf("%d\n",ma-mi);
    }
}
