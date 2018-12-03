#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool com(char a, char b)
{
    return a>b;
}
char ans[11]="9876543210";
char s[11];
int main()
{
    int n, pro, m=0;
    bool flag=false;
    while(scanf("%d", &n)!=EOF&&n)
    {
        if(m>0) printf("\n");
        m++;//Êä³ö¼¼ÇÉ
        flag=false;
        for(int i=1234; i<=50000; i++)
        {
            pro=n*i;
            if(pro>98765)  break;
            if(i<10000)
                sprintf(s, "%d%d%d", 0, i, pro);
            else
                sprintf(s, "%d%d", i, pro);
            sort(s, s+10, com);
            if(strcmp(s, ans)==0)
            {
                printf("%d / %05d = %d\n", pro, i, n);
                flag=true;
            }
        }
        if(!flag)
            printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
