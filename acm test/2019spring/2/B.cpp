#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
char num[2][1000005];
int main()
{
    int n,q;
    scanf("%d",&n);
    scanf("%s",num[0]+1);
    scanf("%s",num[1]+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(num[0][i]!=num[1][i]&&num[0][i+1]!=num[1][i+1]&&num[0][i]!=num[0][i+1]&&i!=n)
        {
            ans++;
            i++;
        }
        else if(num[0][i]!=num[1][i])
            ans++;
    }
    printf("%d\n",ans);
}
