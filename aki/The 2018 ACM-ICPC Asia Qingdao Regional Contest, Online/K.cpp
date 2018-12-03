#include<iostream>
#include<cstdio>
using namespace std;
int a[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int max=0;
        int n;
        int num=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            int b=0;
            while(a[i]>0)
            {
            	b++;
            	a[i]>>=1;
			}
			a[i]=b;
        }
        for(int i=1;i<n;i++)
        {
        	if(a[i]==a[i-1])
        		num++;
        	else
        	{
        		if(num>max)
        			max=num;
        		num=0;
			}
		}
        printf("%d\n",max);
    }
}
