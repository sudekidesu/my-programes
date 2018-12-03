#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int a;
int b;
set<int> A;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int flag1=0,flag2=0,flag=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            A.insert(a);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b);
            if(A.find(b)!=A.end())
                a=b;
        }
        printf("%d\n",a);
        A.clear();
    }
}
