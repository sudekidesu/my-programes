#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    pair<int,char> num[26];
    for(int i=0;i<26;i++)
    {
        num[i].first=0;
        num[i].second='a'+i;
    }
    int n;
    char s[1000001];
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++)
        num[s[i]-'a'].first++;
        for(int i=0;i<26;i++)
            while(num[i].first--)
                printf("%c",num[i].second);
    // sort(num,num+26);
    // int i=25;
    // while(num[i-1].first>0)
    // {
    //     while(num[i].first>0&&num[i-1].first>0)
    //     {
    //         printf("%c%c",num[i].second,num[i-1].second);
    //         num[i-1].first--;
    //         num[i].first--;
    //     }
    //     if(num[i].first>0)
    //     {
    //         printf("%c",num[i].second);
    //         num[i].first--;
    //     }
    //     sort(num,num+26);
    // }
    //         for(int i=0;i<26;i++)
    //             while(num[i].first--)
    //                 printf("%c",num[i].second);
    // for(int i=0;i<26;i++)
    //     if(num[i].first>=2)
    //         for(int j=0;j<num[i].first/2;j++)
    //             printf("%c",num[i].second);
    // for(int i=25;i>=0;i--)
    //     if(num[i].first>=2)
    //     {
    //         for(int j=0;j<num[i].first/2;j++)
    //             printf("%c",num[i].second);
    //         num[i].first%=2;
    //     }
    // for(int i=25;i>=0;i--)
    //     if(num[i].first==1)
    //         printf("%c",num[i].second);
    printf("\n");
}
