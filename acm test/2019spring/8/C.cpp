#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char s[3][300];
char temp[300];
int ans=0x3f3f3f3f;
void jud(int cnt)
{
    if(cnt>2*n)
        return;
    else
    {
        for(int i=0;i<n;i++)
        {
            temp[2*i]=s[1][i];
            temp[2*i+1]=s[0][i];
        }
        bool a=true;
        for(int i=0;i<2*n;i++)
            if(s[2][i]!=temp[i])
                a=false;
        if(a==true)
        {
            ans=min(ans,cnt);
            return;
        }
        for(int i=0;i<n;i++)
        {
            s[1][i]=temp[n+i];
            s[0][i]=temp[i];
        }
        jud(cnt+1);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int an=1;
    while(T--)
    {
        ans=0x3f3f3f3f;
        scanf("%d",&n);
        for(int i=0;i<3;i++)
            scanf("%s",s[i]);
        jud(1);
        if(ans==0x3f3f3f3f)
            printf("%d -1\n",an++);
        else
            printf("%d %d\n",an++,ans);
    }
}
