#include<iostream>
#include<cstdio>
#include<set>
#include<cmath>
using namespace std;
int main()
{
    unsigned long long a,b,c,k;
    while(1)
    {
        set<unsigned long long> s;
        unsigned long long ans=0;
        cin>>a>>b>>c>>k;
        if(!(a||b||c||k))
            break;
        k=pow(2,k);
        while(1)
        {
            if(s.find(a)!=s.end())
            {
                printf("FOREVER\n");
                break;
            }
            s.insert(a);
            if(b>=a&&(b-a)%c==0)
            {
                ans+=(b-a)/c;
                ans%=k;
                cout<<ans<<endl;;
                break;
            }
            unsigned long long t=(k-a)/c;
            a+=t*c;
            a=c-(k-a);
            ans+=t+1;
            ans%=k;
        }
    }
}
