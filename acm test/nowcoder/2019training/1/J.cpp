#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int maxm = 100000 + 100;//点的数量
int num[maxm]={0};
int b[maxm];
int sum;
set<int> s[100005];
struct tree
{
	 int left,right;
	 int n;
}t[maxm*3 + 100];
void push_up(int k)
{
		t[k].n = t[k<<1].n ^ t[k<<1|1].n;
}
void make(int l,int r,int k)//1，n，1
{
		if(l==r)
		{
			t[k].left=t[k].right=l;
			t[k].n=num[l];
			b[l]=k;//不需要点修改的时候这行可以删掉
            s[l].clear();
			return;
		}
		t[k].left=l;
		t[k].right=r;
		make(l,(l+r)>>1,k<<1);
		make(((l+r)>>1)+1,r,k<<1|1);
		push_up(k);
}//建树
void Add(int l,int r,int k,int x)//左端点，右端点，1，加x
{
		if(t[k].left==t[k].right)
		{
            set<int>::iterator it = s[t[k].left].find(x);
            if (it == s[t[k].left].end())
            {
                s[t[k].left].insert(x);  //这里是删除其中的一个x;  删除的是一个位置  而arase是删除所有位置
    			t[k].n^=x;
            }
			return;
		}
		if(l<=(t[k].left+t[k].right)>>1)
				Add(l,r,k<<1,x);
		if(r>(t[k].left+t[k].right)>>1)
				Add(l,r,k<<1|1,x);
		push_up(k);
}//段加法
void Sub(int l,int r,int k,int x)//左端点，右端点，1，减x
{
		if(t[k].left==t[k].right)
		{

            set<int>::iterator it = s[t[k].left].find(x);
            if (it != s[t[k].left].end())
            {
                s[t[k].left].erase(x);  //这里是删除其中的一个x;  删除的是一个位置  而arase是删除所有位置
    			t[k].n^=x;
            }
			return;
		}
		if(l<=(t[k].left+t[k].right)>>1)
				Sub(l,r,k<<1,x);
		if(r>(t[k].left+t[k].right)>>1)
				Sub(l,r,k<<1|1,x);
		push_up(k);
}//段减法
void Query(int l,int r,int k)//左端点，右端点，，1
{
		if(l<=t[k].left&&r>=t[k].right)
		{
			sum^=t[k].n;
			return;
		}
		if(l<=(t[k].left+t[k].right)>>1)
			Query(l,r,k<<1);
		if(r>(t[k].left+t[k].right)>>1)
			Query(l,r,k<<1|1);
}//查询段和


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    make(1,n,1);
    int opt,l,r,x;
    while(m--)
    {
        scanf("%d %d %d %d",&opt,&l,&r,&x);
        if(opt==1)
            Add(l,r,1,x);
        if(opt==2)
            Sub(l,r,1,x);
        if(opt==3)
        {
            sum=0;
            Query(l,r,1);
            printf("%d\n",sum);
        }
    }
}
