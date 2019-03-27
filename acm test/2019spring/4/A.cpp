#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    stack<int> s;
    int cnt=1;
    int ans=0;
    for(int i=0;i<(n<<1);i++)
    {
        char c[10];
        scanf("%s",c);
        if(c[0]=='a')
        {
            int temp;
            scanf("%d",&temp);
            s.push(temp);
        }
        else
        {
            if(s.size()==0)
                cnt++;
            else if(s.top()==cnt)
            {
                cnt++;
                s.pop();
            }
            else
            {
                ans++;
                cnt++;
                while(s.size()!=0)
                    s.pop();
            }
        }
    }
    printf("%d\n",ans);
}
