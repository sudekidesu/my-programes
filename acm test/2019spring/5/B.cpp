#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
deque<long long> q;
int main()
{
    int n;
    scanf("%d",&n);
    char s1[2000],s2[2000];
    scanf("%s%s",s1,s2);
    sort(s1,s1+n);
    sort(s2,s2+n);
    int t1=n-1,t2=n-1;
    int num=0;
    while(t1>=0&&t2>=0)
    {
        while(s1[t1]>s2[t2]&&t1>=0)
            t1--;
        if(t1>=0)
            num++;
        t1--;
        t2--;
    }
    printf("%d\n",n-num);
    t1=n-1;
    t2=n-1;
    num=0;
    while(t1>=0&&t2>=0)
    {
        while(s1[t1]>=s2[t2]&&t1>=0)
            t1--;
        if(t1>=0)
            num++;
        t1--;
        t2--;
    }
    printf("%d\n",num);
}
