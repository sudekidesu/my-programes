#include<iostream>
#include<cstdio>
#include<cstring>
// #include<time.h>
using namespace std;
int main()
{
    char s[1000000];
    unsigned long long n;
    while(scanf("%s",&s))
    {
        if(s[0]=='0'&&s[1]=='\0')
            break;
        n=0;
        for(int i=0;s[i]!='\0';i++)
            n+=s[i]-'0';
        while(n>=10)
        {
            unsigned long long temp=0;
            while(n>0)
            {
                temp+=n%10;
                n/=10;
            }
            n=temp;
        }
        printf("%I64d\n",n);
    }
}
