#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    char s[1000000];
    int n,x;
    int ans[26]={0};
    int temp=0;
    char tempc='\0';
    scanf("%d %d",&n,&x);
    scanf("%s",s);
    for(int i=0;i<n;i++)
    {
        if(tempc==s[i])
            temp++;
        else
            temp=1;
        if(temp==x)
        {
            ans[s[i]-'a']++;
            temp=0;
        }
        tempc=s[i];
    }
    printf("%d\n",*max_element(ans,ans+26));
}
