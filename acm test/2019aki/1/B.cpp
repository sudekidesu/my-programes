#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    double a,b,c,d,ans;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    if(b-a==c-b&&d-c==c-b)
        ans=d+d-c;
    else if(a==0||b==0||c==0||d==0)
        ans=42;
    else if(b/a==c/b&&c/b==d/c)
    {
        ans=d*d/c;
        if(ans!=(int)ans)
            ans=42;
    }
    else
        ans=42;
    printf("%d\n",(int)ans);
}
