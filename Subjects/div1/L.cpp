#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int m,n;
    char s[20][20];
    int no[20][20];
    for(int i=0;i<20;i++)
        s[0][i]=s[i][0]='*';
    int T=1;
    while(cin>>m&&m!=0)
    {
        cin>>n;
        if(T!=1)
            printf("\n");
        printf("puzzle #%d:\n",T++);
        for(int i=1;i<=m;i++)
            scanf("%s",s[i]+1);
        int num=1;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if((s[i][j-1]=='*'||s[i-1][j]=='*')&&s[i][j]!='*')
                    no[i][j]=num++;
        printf("Across\n");
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(s[i][j-1]=='*'&&s[i][j]!='*')
                {
                    printf("%3d.",no[i][j]);
                    for(;s[i][j]!='*'&&j<=n;j++)
                        printf("%c",s[i][j]);
                    printf("\n");
                }
            }
        printf("Down\n");
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(s[i-1][j]=='*'&&s[i][j]!='*')
                {
                    printf("%3d.",no[i][j]);
                    for(int k=i;s[k][j]!='*'&&k<=m;k++)
                        printf("%c",s[k][j]);
                    printf("\n");
                }
            }
    }
}
