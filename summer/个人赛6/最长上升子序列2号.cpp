#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn =300003,INF=0x7f7f7f7f;
int low[maxn],a[maxn];
int n,ans;
int r[200005],j=1;
int binary_search(int *a,int r,int x)
//二分查找，返回a数组中第一个>=x的位置 
{
    int l=1,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(a[mid]<=x)
            l=mid+1;
        else 
            r=mid-1;
    }
    return l;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]); 
        low[i]=INF;//由于low中存的是最小值，所以low初始化为INF 
    }
    low[1]=a[1];
	r[1]=1; 
    ans=1;//初始时LIS长度为1 
    for(int i=2;i<=n;i++)
    {
        if(a[i]==low[ans]+1)//若a[i]>=low[ans]，直接把a[i]接到后面 
        {
        	low[++ans]=a[i];
           	r[j]=i;
           	j++;
		} 
        else //否则，找到low中第一个>=a[i]的位置low[j]，用a[i]更新low[j] 
        {
        	j=binary_search(low,ans,a[i]);
        	r[j]=i;
			low[j]=a[i];
		}
    }
    printf("%d\n",ans);//输出答案 
    printf("%d",r[1]);
    for(int i=2;i<=ans;i++)
    	printf(" %d",r[i]);
    return 0;
}
