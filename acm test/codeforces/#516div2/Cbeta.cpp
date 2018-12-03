#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    char s[1000001];
    scanf("%d",&n);
    scanf("%s",s);
    sort(s,s+n);
    printf("%s\n",s);
}
