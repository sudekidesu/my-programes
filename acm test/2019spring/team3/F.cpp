#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s,temp='\0';
    int tempi=0;
    bool flag1=true,flag2=true;
    int f=0;
    stack<int> st,flag;
    int numf=0,numk=0;
    int cnt=1;
    while(s=getchar())
    {
        if(s=='\n')
            break;
        else if(s==' ')
            continue;
        else if(s>='a'&&s<='z')
        {
            if(f)
                flag1=false;
            f=true;
        }
        else if(s=='('||s==')')
        {
            if(s=='(')
            {
                numk++;
                if(f)
                    flag1=false;
                f=0;
                st.push(cnt);
            }
            else
            {
                if(!f)
                    flag1=false;
                f=1;
                if(st.size()==0)
                    flag1=false;
                else
                {
                    if((temp==')'&&st.top()==tempi-1)||st.top()==cnt-2)
                        flag2=false;
                    tempi=st.top();
                    st.pop();
                    if(flag.size()!=0)
                        flag.pop();
                }
            }
        }
        else
        {
            if(!f)
                flag1=false;
            f=false;
            numf++;
            if(st.size()!=0)
            {
                if(flag.size()!=0)
                {
                    if(flag.top()==st.top())
                        flag2=false;
                }
                flag.push(st.top());
            }
        }
        temp=s;
        cnt++;
    }
    if(numf!=numk+1&&cnt!=2)
        flag2=false;
    if(st.size()!=0||f==0)
        flag1=false;
    if(!flag1)
        printf("error\n");
    else if(flag2)
        printf("proper\n");
    else
        printf("improper\n");
    return 0;
}
