#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int box[300005];
bool jud[300005]={false};
char s[10];
int main()
{
    int n;
    scanf("%d",&n);
    n*=2;
    int num=0;
    int re=1;
    int ans=0;
    while(n--)
    {
        scanf("%s",s);
        if(s[0]=='a')
        {
            int a;
            scanf("%d",&a);
            box[num]=a;
            num++;
        }
        else
        {
            if(box[num-1]==re&&jud[num]==false)
                num--;
            else if(jud[num]==true)
                ;
            else
            {
                ans++;
                jud[num]=true;
            }
            re++;
        }
    }
    printf("%d\n",ans);
}
