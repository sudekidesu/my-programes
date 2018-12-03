#include<iostream>
#include<cstring>
using namespace std;
char str[35];
int n,l;
int swa()
{
    int i;
    char a;
    for(i=l-1;i>0;i--)
        if(str[i]=='D'&&str[i-1]=='S')
        {
            a=str[i];
            str[i]=str[i-1];
            str[i-1]=a;
            n++;
            return 0;
        }
    return 1;
}
int dsum()
{
    int i,sum=0,a=1,k;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='S')
            sum+=a;
        if(str[i]=='D')
            a*=2;
    }
    return sum;
}
int main()
{
    int T,k;
    cin>>T;
    while(T--)
    {
        int maxx;
        n=0;
        k=0;
        cin>>maxx>>str;
        l=strlen(str);
        while(dsum()<maxx)
        {
            k=swa();
            if(k==1)
            {
                cout<<"IMPOSSIBLE"<<endl;
                break;
            }
        }
        if(k!=1)
            cout<<n<<endl;
    }
}
