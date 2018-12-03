#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int s,n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        s=0;
        int k=0;
        char c;
        while((c=getchar())!='\n')
        {
            if(c=='O')
            {
                k++;
                s+=k;
            }
            else
                k=0;
        }
        printf("%d\n",s);
    }
}
