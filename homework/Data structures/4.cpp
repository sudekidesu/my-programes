#include<iostream>
#include<cstring>
#include<algorithm>
#include<time.h>
// #pragma GCC optimize(3)
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))
int n,num[100000000],numt[100000000];
void quick_sort(int *l,int *r)
{
    if(l>=--r)
        return;
    swap(*(l+random(0,r-l)),*r);
    int *a=l;
    for(int *i=l;i<r;i++)
        if(*i<*r)
            swap(*i,*(a++));
    swap(*a,*r);
    quick_sort(l,a);
    quick_sort(++a,++r);
}
int g[100000001];
void merge_sort(int *l,int *r)
{
    if(l>=r-1)
        return;
    l--;
    merge_sort(l+1,l+((r-l)>>1)+1);
    merge_sort(l+((r-l)>>1)+1,r);
    for(int i=1;i<r-l;i++)
        g[i]=*(l+i);
    int i=1,j=((r-l)>>1)+1,k=1;
    while(i<((r-l)>>1)+1||j<r-l)
    {
        if(i<((r-l)>>1)+1&&j<r-l)
            if(g[i]<g[j])
                *(l+k++)=g[i++];
            else
                *(l+k++)=g[j++];
        else if(i<((r-l)>>1)+1)
            *(l+k++)=g[i++];
        else if(j<r-l)
            *(l+k++)=g[j++];
    }
}
void bubble_sort(int *l,int *r)
{
    for(int *i=l;i<r;i++)
        for(int *j=i+1;j<r;j++)
            if(*i>*j)
                swap(*i,*j);
}
void selection_sort(int *l,int *r)
{
    int *temp;
    for(int *i=l;i<r;i++)
    {
        temp=i;
        for(int *j=i+1;j<r;j++)
            if(*j<*temp)
                temp=j;
        swap(*i,*temp);
    }
}
void insertion_sort(int *l,int *r)
{
    for(int *i=l;i<r;i++)
    {
        int temp=*i;
        int *j=i;
        while(temp<*(j-1)&&j>l)
        {
            *j=*(j-1);
            j--;
        }
        *j=temp;
    }
}
void Max_heap(int *l,int *r)
{
    l--;
    int n=r-l-1;
    for(int k=n>>1;k>0;k--)
    {
        int t=k;
        while((t<<1)<=n)
        {
            int max=t;
            if(*(l+(t<<1))>*(l+max))
                max=t<<1;
            if(*(l+(t<<1|1))>*(l+max)&&(t<<1)<n)
                max=t<<1|1;
            if(max==t)
                break;
            swap(*(l+t),*(l+max));
            t=max;
        }
    }
}
void heap_sort(int *l,int *r)
{
    int *k=r;
    Max_heap(l,r);
    l--;
    while(--k>l)
    {
        swap(*(l+1),*k);
        int t=1;
        while(l+(t<<1)<k)
        {
            int max=t;
            if(*(l+(t<<1))>*(l+max))
                max=t<<1;
            if(*(l+(t<<1|1))>*(l+max)&&l+(t<<1)+1<k)
                max=t<<1|1;
            if(max==t)
                break;
            swap(*(l+t),*(l+max));
            t=max;
        }
    }
}
int main()
{
    int seed=time(NULL);
    srand(seed);
    scanf("%d",&n);
    if(n>100000000)
        exit(0);
    for(int i=0;i<n;i++)
        numt[i]=random(1,100000000);
    int a;
    for(int i=0;i<n;i++)
        num[i]=numt[i];
    a=clock();
    quick_sort(num,num+n);
    printf("quick_sort_time=%dms\n",clock()-a);
    for(int i=0;i<n;i++)
        num[i]=numt[i];
    a=clock();
    merge_sort(num,num+n);
    printf("merge_sort_time=%dms\n",clock()-a);
    for(int i=0;i<n;i++)
        num[i]=numt[i];
    a=clock();
    heap_sort(num,num+n);
    printf("heap_sort_time=%dms\n",clock()-a);
    for(int i=0;i<n;i++)
        num[i]=numt[i];
    a=clock();
    insertion_sort(num,num+n);
    printf("insertion_sort_time=%dms\n",clock()-a);
    for(int i=0;i<n;i++)
        num[i]=numt[i];
    a=clock();
    selection_sort(num,num+n);
    printf("selection_sort_time=%dms\n",clock()-a);
    for(int i=0;i<n;i++)
        num[i]=numt[i];
    a=clock();
    bubble_sort(num,num+n);
    printf("bubble_sort_time=%dms\n",clock()-a);
    // for(int i=0;i<n;i++)
    //     printf("%d\n",num[i]);
}
