#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    string s;
    int k=0;
    while(getline(cin,s))
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='"')
            {   if(k%2==0)
                    printf("``");
                else
                    printf("''");
                k++;
            }
            else
                printf("%c",s[i]);
        }
        printf("\n");
    }
}
