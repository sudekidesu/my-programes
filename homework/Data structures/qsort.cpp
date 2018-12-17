#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int num[10000];
void qsort(int l,int r)
{
    if(l>r)
        return;
    int a=l-1;
    for(int i=l+0;i<r;i++)
        if(num[i]<num[r])
            swap(num[i],num[++a]);
    swap(num[a+1],num[r]);
    qsort(l,a);
    qsort(a+2,r);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    qsort(0,n-1);
    for(int i=0;i<n;i++)
        printf("%d\n",num[i]);
}
