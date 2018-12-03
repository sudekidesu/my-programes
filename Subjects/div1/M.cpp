#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int T;
    char DNA[60][2000];
    char ans[2000];
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        int num=0;
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++)
            scanf("%s",DNA[i]);
        for(int i=0;i<n;i++)
        {
            int cnt[4]={0};
            char temp;
            for(int j=0;j<m;j++)
            {
                if(DNA[j][i]=='A')
                    cnt[0]++;
                if(DNA[j][i]=='C')
                    cnt[1]++;
                if(DNA[j][i]=='G')
                    cnt[2]++;
                if(DNA[j][i]=='T')
                    cnt[3]++;
            }
            int c=max(cnt[0],max(cnt[1],max(cnt[2],cnt[3])));
            if(cnt[0]==c)
                temp='A';
            else if(cnt[1]==c)
                temp='C';
            else if(cnt[2]==c)
                temp='G';
            else if(cnt[3]==c)
                temp='T';
            ans[i]=temp;
            for(int j=0;j<m;j++)
                if(DNA[j][i]!=temp)
                    num++;
        }
        ans[n]='\0';
        printf("%s\n%d\n",ans,num);
    }
}
