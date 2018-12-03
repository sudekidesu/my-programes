#include<iostream>
#include<cstdio>
using namespace std;
char a[1000000],b[1000000];
int main()
{
    while(scanf("%s %s",a,b)!=EOF)
    {
        bool flag=false;
        int j=0;
        for(int i=0;a[i]!='\0';i++)
        {
            for(;b[j]!='\0';j++)
                if(b[j]==a[i])
                {
                    j++;
                    if(a[i+1]=='\0')
                        flag=true;
                    break;
                }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
