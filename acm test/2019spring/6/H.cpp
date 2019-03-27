#include<iostream>
#include<cstdio>
using namespace std;
struct trie
{
    int link[10];
    bool ifend;
}t[100005];
int cnt=1;
char s[15];
bool ans;
void ins()
{
    int k=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(t[k].ifend==true)
            ans=false;
        if(t[k].link[s[i]-'0']==-1)
        {
            cnt++;
            t[cnt].ifend=false;
            for(int j=0;j<10;j++)
                t[cnt].link[j]=-1;
            t[k].link[s[i]-'0']=cnt;
        }
        else if(s[i+1]=='\0')
            ans=false;
        k=t[k].link[s[i]-'0'];
        if(s[i+1]=='\0')
            t[k].ifend=true;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ans=true;
        t[0].ifend=false;
        for(int i=0;i<10;i++)
            t[0].link[i]=-1;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            cnt=0;
            scanf("%s",s);
            ins();
        }
        printf("%s\n",ans?"YES":"NO");
    }
}
