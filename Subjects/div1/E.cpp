#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int o=0;o<n;o++)
    {
        int num;
        scanf("%d",&num);
        int m=num;
        int m2=num;
        while(m>0)
        {
            m2-=9;
            m/=10;
        }
        m=0;
        for(int i=num;i>=m2;i--)
        {
            int t=i;
            int temp=i;
            while(t>0)
            {
                temp+=t%10;
                t/=10;
            }
            if(temp==num)
                m=i;
        }
        printf("%d\n",m);
    }
}
