#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
  map<char,string> mmp;
  mmp['a']="@";
  mmp['b']="8";
  mmp['c']="(";
  mmp['d']="|)";
  mmp['e']="3";
  mmp['f']="#";
  mmp['g']="6";
  mmp['h']="[-]";
  mmp['i']="|";
  mmp['j']="_|";
  mmp['k']="|<";
  mmp['l']="1";
  mmp['m']="[]\\/[]";
  mmp['n']="[]\\[]";
  mmp['o']="0";
  mmp['p']="|D";
  mmp['q']="(,)";
  mmp['r']="|Z";
  mmp['s']="$";
  mmp['t']="']['";
  mmp['u']="|_|";
  mmp['v']="\\/";
  mmp['w']="\\/\\/";
  mmp['x']="}{";
  mmp['y']="`/";
  mmp['z']="2";
  char s[10005];
  int i;
  for(i=0;;i++)
  {
    s[i]=getchar();
    if(s[i]=='\n')
    {
      s[i]='\0';
      break;
    }
  }
  for(i=0;s[i]!='\0';i++)
  {
    if(s[i]>='A'&&s[i]<='Z')
      s[i]+=32;
    if(s[i]>='a'&&s[i]<='z')
      cout<<mmp[s[i]];
    else
      printf("%c",s[i]);
  }
}
