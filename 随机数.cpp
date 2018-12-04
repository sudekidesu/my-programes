//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<ctime>
#include<cstring>
#include<set>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))
int main()
{
    int seed=time(NULL);
    srand(seed);
    //以上为随机数初始化，请勿修改
    //random(a,b)生成[a,b]的随机整数、
    //以下写你自己的数据生成代码
    int n;
    scanf("%d", &n);
    set<int> s;
    while(n--)
    {
        int a=random(9,32);
        if(s.find(a)!=s.end())
        {
            n++;
            continue;
        }
        s.insert(a);
        printf("B170412%02d\n",a);
    }
}
