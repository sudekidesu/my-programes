#include<iostream>
#include<cstdio>
using namespace std;
void reverse(char *s)
{
    char *temp=s;
    while(*(temp++));
    temp-=2;
    while(s<temp)
    {
        swap(*s,*temp);
        s++;
        temp--;
    }
}
int main()
{
    char dict[26]={'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C'};
    char dict2[26]={'d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c'};
    char s[10000];
    cin>>s;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            s[i]-='a'-'A';
            s[i]=dict[s[i]-'A'];
        }
        else
        {
            s[i]+='a'-'A';
            s[i]=dict2[s[i]-'a'];
        }
    }
    reverse(s);
    cout<<s<<endl;
}
