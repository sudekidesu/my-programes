#include<iostream>
#include<cstdio>
#include<algorithm>
const long long maxm = 200000 + 100;//点的数量
long long num[maxm]={0};
long long b[maxm]={0};
long long sum,sumt;
struct tree
{
	 long long left,right;
	 long long n;
	 long long n1;
}t[maxm*2 + 100];
void push_up(long long k)
{
	t[k].n1 = t[k<<1].n1 + t[k<<1|1].n1;
	t[k].n = t[k<<1].n+(t[k<<1|1].right-t[k<<1|1].left+1)*t[k<<1].n1 + t[k<<1|1].n;
}
void refresh(long long k)//点标号
{
  k=b[k]>>1;
  while(k>0)
  {
    push_up(k);
    k=k>>1;
  }
}//快速点更新
void make(long long l,long long r,long long k)//1，n，1
{
		if(l==r)
		{
			t[k].left=t[k].right=l;
			t[k].n=t[k].n1=num[l];
			b[l]=k;//不需要点修改的时候这行可以删掉
			return;
		}
		t[k].left=l;
		t[k].right=r;
		make(l,(l+r)>>1,k<<1);
		make(((l+r)>>1)+1,r,k<<1|1);
		push_up(k);
}//建树
void Query(long long l,long long r,long long k)//左端点，右端点，，1
{
		if(l<=t[k].left&&r>=t[k].right)
		{
			sum+=t[k].n+(r-t[k].right)*t[k].n1;
			return;
		}
		if(l<=(t[k].left+t[k].right)>>1)
			Query(l,r,k<<1);
		if(r>(t[k].left+t[k].right)>>1)
			Query(l,r,k<<1|1);
}//查询段和
int main()
{
    long long n,q;
    scanf("%lld %lld",&n,&q);
    for(long long i=1;i<=n;i++)
	{
        scanf("%lld",&num[i]);
	}
	make(1,n,1);
    long long w,l,r;
    while(q--)
    {
        scanf("%lld %lld %lld",&w,&l,&r);
        if(w==1)
        {
            sum=0;
            Query(l,r,1);
            printf("%lld\n",sum);
        }
        else
        {
            num[l]=r;
            t[b[l]].n=t[b[l]].n1=r;
            refresh(l);
        }
    }
}
