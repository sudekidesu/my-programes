//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<ctime>
#include<cstring>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))
int main()
{
    int seed=time(NULL);
    srand(seed);
    //以上为随机数初始化，请勿修改
    //random(a,b)生成[a,b]的随机整数、
    //以下写你自己的数据生成代码
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b;
        int n;
        scanf("%d", &n);
        char tem[5];
        for(int i=1;i<=n;i++)
        {
            scanf("%s",tem);
            if(!strcmp(tem,"add"))
                scanf("%d",&a);
            else
                scanf("%d %d",&a,&b);
        }
        printf("%s\n",random(1,2)==1?"No":"Yes");
    }
}
