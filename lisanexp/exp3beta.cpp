#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
int main()
{
    int n;
    printf("输入一个正整数：\n");
    scanf("%d",&n);
    printf("\n");
    vector<int> f;
    for(int i=n;i>0;i--)
        if(n%i==0)
            f.push_back(i);
    printf("因子：\n");
    for(vector<int>::iterator i=f.begin();i!=f.end();i++)
        printf("%d\n",*i);
    printf("\n");
    vector<vector<bool>> m;
    for(vector<int>::iterator i=f.begin();i!=f.end();i++)
    {
        vector<bool> line;
        for(vector<int>::iterator j=f.begin();j!=f.end();j++)
            line.push_back((*i%*j)==0);
        m.push_back(line);
    }
    printf("盖住关系：\n");
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<f.size();j++)
        {
            if(i==j||!m[i][j])
                continue;
            bool flag=true;
            for(int k=0;k<f.size();k++)
            {
                if(k==i||k==j)
                    continue;
                if(m[i][k]&&m[k][j])
                    flag=false;
            }
            if(flag)
                printf("%d盖住%d\n",f[i],f[j]);
        }
    }
    printf("\n");
    bool flag2=true;
    for(int i=0;i<m.size();i++)
    {
        bool flag=false;
        for(int j=0;j<f.size();j++)
            flag=flag||(gcd(f[i],f[j])==1&&lcm(f[i],f[j])==n);
        flag2=flag2&&flag;
    }
    if(flag2)
        printf("是有补格\n");
    else
        printf("不是有补格\n");
}
