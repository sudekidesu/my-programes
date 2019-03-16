#include<iostream>
#include<cstdio>
using namespace std;
struct trie
{
    int num;
    trie *link[2];
    trie()
    {
        num=0;
        link[0]=NULL;
        link[1]=NULL;
    }
}t;
void ins(int a)
{
    int num[32];
    for(int i=0;i<32;i++)
    {
        // printf("%d",a&1);
        num[i]=a&1;
        a>>=1;
    }
    trie *T=&t;
    for(int i=31;i>=0;i--)
    {
        if(T->link[num[i]]==NULL)
        {
            trie *temp=new trie();
            temp->num=num[i];
            T->link[num[i]]=temp;
        }
        T=T->link[num[i]];
    }
}
void dfs(trie *T,string s)
{
    if(T==NULL)
        return;
    cout<<s;
    printf("%d\n",T->num);
    dfs(T->link[0],s+" ");
    dfs(T->link[1],s+" ");
}
int ans[33];
int an=0;
void search(trie *T1,trie *T2,int w)
{
    // printf("dbg");
    // printf("%d %d\n",T1,T2);
    if(T1==NULL||T2==NULL||w<0)
    {
        if(w<0)
        {
            int temp=0;
            for(int i=31;i>=0;i--)
            {
                temp<<=1;
                temp+=ans[i];
            }
            an=max(an,temp);
        }
        return ;
    }
    if(T1->num!=T2->num)
        ans[w]=1;
    else
        ans[w]=0;
    if(T1==T2)
    {
        if(T1->link[0]!=NULL&&T2->link[1]!=NULL)
            search(T1->link[0],T2->link[1],w-1);
        else
        {
            search(T1->link[1],T2->link[1],w-1);
            search(T1->link[0],T2->link[0],w-1);
        }
    }
    else
    {
        if((T1->link[0]!=NULL&&T2->link[1]!=NULL)||(T1->link[1]!=NULL&&T2->link[0]!=NULL))
        {
            search(T1->link[0],T2->link[1],w-1);
            search(T1->link[1],T2->link[0],w-1);
        }
        else
        {
            search(T1->link[1],T2->link[1],w-1);
            search(T1->link[0],T2->link[0],w-1);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        ins(a);
    }
    search(&t,&t,32);
    // dfs(&t,"");
    printf("%d\n",an);
}
