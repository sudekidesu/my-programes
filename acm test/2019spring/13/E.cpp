#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s1[10005];
char s2[10005];
int main()
{
    scanf("%s",s1);
    scanf("%s",s2);
    int l1=strlen(s1),l2=strlen(s2);
    int ans=l1-l2+1;
    for(int i=0;i<=l1-l2;i++)
        for(int j=0;j<l2;j++)
            if(s1[i+j]==s2[j])
            {
                ans--;
                break;
            }
    printf("%d\n",ans);
}
