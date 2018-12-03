#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
map<char,char> mmp;
int main()
{
    mmp['0']='0';
    mmp['9']=' ';
    mmp['8']='8';
    mmp['7']=' ';
    mmp['6']=' ';
    mmp['5']='Z';
    mmp['4']=' ';
    mmp['3']='E';
    mmp['2']='S';
    mmp['1']='1';
    mmp['P']=' ';
    mmp['O']='O';
    mmp['I']='I';
    mmp['U']='U';
    mmp['Y']='Y';
    mmp['T']='T';
    mmp['R']=' ';
    mmp['E']='3';
    mmp['W']='W';
    mmp['L']='J';
    mmp['K']=' ';
    mmp['J']='L';
    mmp['H']='H';
    mmp['G']=' ';
    mmp['F']=' ';
    mmp['D']=' ';
    mmp['S']='2';
    mmp['M']='M';
    mmp['N']=' ';
    mmp['B']=' ';
    mmp['V']='V';
    mmp['C']=' ';
    mmp['X']='X';
    mmp['Q']=' ';
    mmp['A']='A';
    mmp['Z']='5';
    string s,t;
    while(cin>>s)
    {
        t=s;
        reverse(t.begin(),t.end());
        bool flag=(s==t);
        bool fl=true;
        for(int i=0;i<s.length();i++)
            if(mmp[s[i]]!=t[i])
                fl=false;
        if(flag&&fl)
            cout<<s<<" -- is a mirrored palindrome."<<endl<<endl;
        if(flag&&!fl)
            cout<<s<<" -- is a regular palindrome."<<endl<<endl;
        if(!flag&&fl)
            cout<<s<<" -- is a mirrored string."<<endl<<endl;
        if(!flag&&!fl)
            cout<<s<<" -- is not a palindrome."<<endl<<endl;
    }
}
