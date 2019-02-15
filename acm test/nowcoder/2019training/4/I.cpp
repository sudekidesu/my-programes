#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int n;
    bool ans=false;
    char s[100005];
    scanf("%s",s);
    char *a=s,*b=s+strlen(s)-1;
    while(a<b&&*a==*b)
    {
        a++;
        b--;
    }
    if(a>=b)
        ans=true;
    else
    {
        char *at=a,*bt=b;
        a++;
        bt--;
        while(at<b&&*at==*bt)
        {
            at++;
            bt--;
        }
        while (a<b&&*a==*b)
        {
            a++;
            b--;
        }
        if(a>=b||at>=bt)
            ans=true;
    }
    if(ans)
        printf("Yes\n");
    else
        printf("No\n");
}
