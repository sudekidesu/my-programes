#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int temp;
int maxl;
template <class T>
inline bool scan_d(T &ret) 
{
    char c;
    int sgn;
    if( c=getchar() , c==EOF ) return 0; //EOF
    while(c != '-' && ( c<'0' || c>'9')) c=getchar();
    sgn = (c=='-') ? -1 : 1;
    ret = (c=='-') ? 0 : (c-'0');
    while( c=getchar(), c>='0'&& c<='9' ) ret = ret*10+(c-'0');
    ret *= sgn;
    return 1;
}
struct number
{
  int n;
  int ml1;
  int ml;
  bool operator<(const number b) const
	{
		return this->ml1<b.ml1&&b.n<temp;
	}
}d[200005];
int main()
{
  int T;
  scan_d(T);
  while(T--)
  {
    maxl=0;
    int n;
    scan_d(n);
    int i;
    scan_d(d[0].n);
    d[0].ml=1;
    d[0].ml1=1;
    scan_d(d[1].n);
    d[1].ml=d[1].n>d[0].n?2:1;
    d[1].ml1=d[1].ml;
    for(i=2;i<n;i++)
    {
      scan_d(d[i].n);
      temp=d[i].n;
      d[i].ml1=max((*max_element(&d[0],&d[i-2]+1)).ml1+1,d[i-1].n<d[i].n?d[i-1].ml1+1:0);
      d[i].ml=d[i-1].n<d[i].n?d[i-1].ml+1:1;
      if(d[i].ml>maxl||d[i].ml1>maxl)
        maxl=max(d[i].ml,d[i].ml1);
    }
    cout<<maxl<<endl;
  }
}//
