#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool ans=false;
void jud(char *s,char *t,int num)
{
    if(num>2)
        return;
    while(*s==*t&&*s!='\0'&&*t!='\0')
    {
        s++;
        t++;
    }
    if(*s==*t&&*s=='\0'&&(num==2||num==0))
    {
        ans=true;
        return;
    }
    if(*t!='\0')
    {
        jud(s,t+1,num+1);
        if(*s!='\0')
            jud(s+1,t+1,num+1);
    }
    if(*s!='\0')
        jud(s+1,t,num+1);
}
int main()
{
    char s[105],t[105];
    scanf("%s",s);
    scanf("%s",t);
    jud(s,t,0);
    printf("%s\n",ans?"YES":"NO");
}
