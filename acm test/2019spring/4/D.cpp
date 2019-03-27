#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    queue<char> q;
    char s[200005];
    scanf("%s",s);
    int numd=0,numr=0;
    int numD=0,numR=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='D')
            numD++;
        else
            numR++;
        q.push(s[i]);
    }
    while(q.size()>1&&numD>0&&numR>0)
    {
        char temp=q.front();
        q.pop();
        if(temp=='D')
        {
            if(numd>0)
            {
                numd--;
                numD--;
                continue;
            }
            numr++;
            q.push('D');
        }
        else
        {
            if(numr>0)
            {
                numr--;
                numR--;
                continue;
            }
            numd++;
            q.push('R');
        }
    }
    printf("%c\n",q.front());
}
