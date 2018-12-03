#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<sstream>
using namespace std;
pair<int ,int> num[10005];
bool d[10005][10005];
int main()
{
    string str;
    //freopen("a.in","r",stdin);
    while(getline(cin,str))
    {
        stringstream s;
        s<<str;
        int jud=0;
        int n=0;
        while(++n&&s>>num[n].first)
            num[n].second=n;
        n--;
        num[1].second=1;
        memset(d,0,sizeof(d));
        for(int i=1;i<n&&jud==0;i++)
        {
			sort(num+i,num+n+1);
        	reverse(num+i,num+n+1);
            if(num[i].first==0)
                continue;
      	    for(int j=i+1;j<=i+num[i].first&&jud==0;j++)
      	    {
                if(num[j].first==0)
                    jud=1;
      	    	num[j].first--;
      	    	d[num[i].second][num[j].second]=d[num[j].second][num[i].second]=true;
			}
            num[i].first=0;
        }
        if(jud==0)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    if(d[i][j])
                        putchar('1');
                    else
                        putchar('0');
                    if(j!=n)
                        putchar(' ');
                    else
                        putchar('\n');
                }
        else
            printf("fail\n");
        putchar('\n');
    }
}
