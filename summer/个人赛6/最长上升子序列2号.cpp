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
//���ֲ��ң�����a�����е�һ��>=x��λ�� 
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
        low[i]=INF;//����low�д������Сֵ������low��ʼ��ΪINF 
    }
    low[1]=a[1];
	r[1]=1; 
    ans=1;//��ʼʱLIS����Ϊ1 
    for(int i=2;i<=n;i++)
    {
        if(a[i]==low[ans]+1)//��a[i]>=low[ans]��ֱ�Ӱ�a[i]�ӵ����� 
        {
        	low[++ans]=a[i];
           	r[j]=i;
           	j++;
		} 
        else //�����ҵ�low�е�һ��>=a[i]��λ��low[j]����a[i]����low[j] 
        {
        	j=binary_search(low,ans,a[i]);
        	r[j]=i;
			low[j]=a[i];
		}
    }
    printf("%d\n",ans);//����� 
    printf("%d",r[1]);
    for(int i=2;i<=ans;i++)
    	printf(" %d",r[i]);
    return 0;
}
