#include<iostream>
#include<cstdio>
#include<vector>
const long long mod=1e9+7;
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
long long sum;
long long n;
long long jc[300005]={1};
struct nood
{
  vector<long long> n;
  vector<long long> l;
  long long num;
  nood()
  {
  	num=0;
    n.clear();
    l.clear();
  }
}d[300005];
void cal(long long k,long long t)
{
  d[k].num++;
  vector<long long>::iterator i;
  for(i=d[k].n.begin();i!=d[k].n.end();i++)
  {
    if(*i==t)
      continue;
    cal(*i,k);
  }
  for(i=d[k].n.begin();i!=d[k].n.end();i++)
  {
    if(*i==t)
      continue;
    sum+=d[*i].num*(n-d[*i].num)%mod*2%mod*jc[n-1]%mod*(*(d[k].l.begin()+(i-d[k].n.begin())))%mod;
    d[*i].num=0;
  }
  d[t].num+=d[k].num;
  d[k].l.clear();
  d[k].n.clear();
}
int main()
{
  // ios::sync_with_stdio(false);
  for(int i=1;i<300005;i++)
  {
  	jc[i]=jc[i-1]*i;
  	jc[i]%=mod;
  }
  // while(scanf("%lld",&n)!=EOF)
  while(/*scan_d(n)*//*cin>>n*/scanf("%lld",&n)!=EOF)
  {
    d[0].n.push_back(1);
    d[0].l.push_back(0);
    sum=0;
    long long b;
    long long t,t2;
    for(long long i=1;i<n;i++)
    {
      // scan_d(t);
      // scan_d(t2);
      // scan_d(b);
      scanf("%lld %lld %lld",&t,&t2,&b);
      // cin>>t>>t2>>b;
      d[t].n.push_back(t2);
      d[t].l.push_back(b);
      d[t2].n.push_back(t);
      d[t2].l.push_back(b);
    }
    cal(0,0);
    // cout<<sum<<endl;
    printf("%lld\n",sum);
  }
}
