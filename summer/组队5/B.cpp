#include<iostream>
#include<cstdio>
using namespace std;
string Binary (int x, int len)
{
	string s = "";
	while (x != 0) {
		if (x%2==0)  s = '0' + s;
		else  s = '1' + s;
		x >>= 1;
	}
	while (s.length() < len)  s = '0' + s;
	return s;
}
string TruncatedBinary (int x, int n)
{
	// Set k = floor(log2(n)), i.e., k such that 2^k <= n < 2^(k+1).
	int k = 0, t = n;
	while (t > 1) { k++;  t >>= 1; }

	// Set u to the number of unused codewords = 2^(k+1) - n.
	int u = (1 << k+1) - n;

	if (x < u)  return Binary(x, k); 
        else  return Binary(x+u, k+1);
}
int main()
{
  freopen("binary.in","r",stdin);
  freopen("binary.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    cout<<TruncatedBinary(i,n)<<endl;

}
