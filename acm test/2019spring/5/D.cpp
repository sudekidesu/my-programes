#include<iostream>
#include<cstdio>
using namespace std;
struct trie
{
    char c;
    trie *link[26];
    int num;
    bool cnt;
    trie()
    {
        num=0;
        c='\0';
        for(int i=0;i<26;i++)
            link[i]=NULL;
    }
}t;
int alp[26];
char s[2000];
int k;
int ans=0;
void ins()
{
    for(int i=0;s[i]!='\0';i++)
    {
        trie *T=&t;
        for(int j=i;s[j]!='\0';j++)
        {
            if(T->num==k&&alp[s[j]-'a']==0)
                break;
            if(T->link[s[j]-'a']==NULL)
            {
                trie *temp=new trie();
                temp->c=s[j];
                temp->num=T->num;
                if(alp[s[j]-'a']==0)
                    temp->num++;
                T->link[s[j]-'a']=temp;
                ans++;
            }
            T=T->link[s[j]-'a'];
        }
    }
}
int main()
{
    scanf("%s",s);
    getchar();
    for(int i=0;i<26;i++)
    {
        char c=getchar();
        alp[i]=c-'0';
    }
    scanf("%d",&k);
    ins();
    printf("%d\n",ans);
}
