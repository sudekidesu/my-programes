#include<iostream>
#include<cstdio>
using namespace std;
template <class T>
inline bool scan_d(T &ret)
{
    char c;
    long long sgn;
    if( c=getchar() , c==EOF ) return 0; //EOF
    while(c != '-' && ( c<'0' || c>'9')) c=getchar();
    sgn = (c=='-') ? -1 : 1;
    ret = (c=='-') ? 0 : (c-'0');
    while( c=getchar(), c>='0'&& c<='9' ) ret = ret*10+(c-'0');
    ret *= sgn;
    return 1;
}
long long num[5000005];
int main()
{
    long long n,b;
    while(1)
    {
      scanf("%lld %lld",&n,&b);
      // scan_d(n);
      // scan_d(b);
      if(n==-1)
      	break;
      long long sum=0;
      for(long long i=0;i<n;i++)
      {
        // scan_d(num[i]);
        scanf("%lld",&num[i]);
        sum+=num[i];
      }
      long long k;
      while(n>1)
      {
        k=0;
        int k2=0;
        long long s=sum;
        long long b1=0;
        for(long long i=0;i<n&&k2<n;i++)
          if(num[i]*(b*num[i]/sum)<=sum/b+(sum%b?1:0))
          {
            s-=num[i];
            b1+=b*num[i]/sum+(b*num[i]%sum==0?0:1);
            k2++;
          }
          else
          {
            num[k]=num[i];
            k++;
          }
        sum=s;
        b-=b1;
        n=k;
      }
      printf("%lld\n",sum/b+(sum%b==0?0:1));
    }
}
