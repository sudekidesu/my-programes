#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char s[10000];
        double sum=0;
        double temp=0;
        double t=0;
        scanf("%s",s);
        int i;
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                sum+=temp*t;
                if(i>0&&s[i-1]>='A'&&s[i-1]<='Z')
                    sum+=temp;
                if(s[i]=='C')
                    temp=12.01;
                else if(s[i]=='H')
                    temp=1.008;
                else if(s[i]=='O')
                    temp=16;
                else
                    temp=14.01;
                t=0;
            }
            else
            {
                t*=10;
                t+=s[i]-'0';
            }
        }
        sum+=temp*t;
        if(s[i-1]>='A'&&s[i-1]<='Z')
            sum+=temp;
        printf("%.3lf\n",sum);
    }
}
