#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
char s[1000001];
bool num[40000];
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int ans=0;
        memset(num,0,sizeof(num));
        int no[40000]={0};
        printf("%d/%d = %d.",a,b,a/b);
        a%=b;
        int c;
        for(int i=0;i<1000000;i++)
        {
            a*=10;
            c=a;
            s[i]='0'+a/b;
            a%=b;
            if(num[c]==true)
            {
                ans=i-no[c];
                s[i]='\0';

                break;
            }
            else
            {
                num[c]=true;
                no[c]=i;
            }
        }
        for(int i=0;s[i]!='\0'&&i<no[c]+50;i++)
            if(i==no[c])
                printf("(%c",s[i]);
            else
                printf("%c",s[i]);
        if(ans<=50)
            printf(")\n");
        else
            printf("...)\n");
        printf("   %d = number of digits in repeating cycle\n\n",ans);
    }
}
