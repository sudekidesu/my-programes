#include<iostream>
#include<cstdio>
using namespace std;
typedef int Elemtype;
pair<int,int> a;
typedef struct
{
    int n;
    int maxm;
    Elemtype *Element;
    void Init(int m)
    {
        n=0;
        maxm=m;
        Element=(Elemtype*)malloc(sizeof(Elemtype)*m);
    }
    bool Insert(int a)
    {
        if(n==maxm-1)
            return false;
        else
        {
            int i;
            for(i=n;Element[i-1]>a;i--)
                Element[i]=Element[i-1];
            Element[i]=a;
            n++;
            return true;
        }
    }//插入O(n)
    bool Find(int i,Elemtype *a)
    {
        if(i<0||i>=n)
            return false;
        else
        {
            *a=Element[i];
            return true;
        }
    }//查找O(1)
    bool Delete(int a)
    {
        if(a<0||a>=n)
            return false;
        else
        {
            for(int i=a;i<n-1;i++)
                Element[i]=Element[i+1];
            n--;
            return true;
        }
    }//删除元素，O(n);
    bool print()
    {
        if(n==0)
            return false;
        for(int i=0;i<n;i++)
            printf("%d%c",Element[i],i==n-1?'\n':' ');
        return true;
    }//输出
    void free()//释放
    {
        n=0;
        maxm=0;
        delete Element;
    }
}Seqlist;//线性表
typedef struct Node
{
    Elemtype element;
    Elemtype p;
    struct Node *link;
    struct Node *pre;
}Node;//节点
typedef struct
{
    int n;
    struct Node *first;
    void Init()
    {
        n=0;
        first=NULL;
    }
    bool Insert(int a,int e,int b=0)
    {
        if(a<0&&a>=n)
            return false;
        Node *p=new Node;
        p->element=e;
        p->p=b;
        Node *t=first;
        int i=0;
        while((a--)>1)
            t=t->link;
        if(n==0)
        {
            p->link=t;
            first=p;
        }
        else
        {
            p->link=t->link;
            t->link=p;
        }
        n++;
        return true;
    }//插入O(n)
    bool Delete(int a)
    {
        if(a<0&&a>=n)
            return false;
        else
        {
            Node *t;
            a--;
            while(a--)
                t=t->link;
            t->link=t->link->link;
            return true;
        }
    }//删除元素O(n)
    bool print()
    {
        if(n==0)
            return false;
        else
        {
            Node *t;
            t=first;
            for(int i=0;i<n;i++)
            {
                t=t->link;
                printf("%d%c",t->element,i==n-1?'\n':' ');
                return true;
            }
        }
    }//输出O(n)
    bool Reverse()
    {
        if(n==0)
            return false;
        Node *t=first;
        Node *p;
        for(int i=0;i<n;i++)
        {
            p=t->link;
            t->link=t;
            t=p;
        }
        first=t;
        return true;
    }//反转O(n)
    bool Sort()
    {
        Node *t=first;
        for(int i=0;i<n-1;i++)
            for(int j=0;j<n-1;j++)
                if(t->element>t->link->element)
                {
                    Elemtype temp=t->element;
                    t->element=t->link->element;
                    t->link->element=temp;
                    temp=t->p;
                    t->p=t->link->p;
                    t->link->p=temp;
                }
    }//排序O(n^2)
    void free()
    {
        Node *t=first;
        while(t!=NULL)
        {
            t=t->link;
            delete first;
            first=t;
        }
    }//释放O(n)
}Singlelist;//单链表
typedef struct
{
    int n;
    struct Node *first;
    void Init()
    {
        n=0;
        first=new struct Node;
        first->link=NULL;
    }
    bool Insert(int a,int e)
    {
        if(a<0&&a>=n)
            return false;
        Node *p=new struct Node;
        p->element=e;
        Node *t=first->link;
        int i=0;
        a--;
        while(a--)
            t=t->link;
        p->link=t;
        t=p;
        n++;
        return true;
    }//插入O(n)
    bool Delete(int a)
    {
        if(a<0&&a>=n)
            return false;
        else
        {
            Node *t;
            a--;
            while(a--)
                t=t->link;
            t->link=t->link->link;
            return true;
        }
    }//删除O(n)
    bool print()
    {
        if(n==0)
            return false;
        else
        {
            Node *t;
            t=first->link;
            for(int i=0;i<n;i++)
            {
                t=t->link;
                printf("%d%c",t->element,i==n-1?'\n':' ');
                return true;
            }
        }
    }//输出O(n)
    void free()
    {
        Node *t;
        while(n-->0)
        {
            t=first->link->link;
            delete first->link;
            first->link=t;
        }
    }//释放
}Headerlist;//带表头的单链表
typedef struct
{
    int n;
    struct Node *first;
    void Init()
    {
        n=0;
        first=NULL;
    }
    bool Insert(int a,int e)
    {
        if(a<0&&a>=n)
            return false;
        Node *p=new struct Node;
        p->element=e;
        Node *t=first;
        int i=0;
        a--;
        while(a--)
            t=t->link;
        p->link=t->link;
        t->link=p;
        t=t->link->link;
        p->pre=t->pre;
        t->pre=p;
        n++;
        return true;
    }//插入O(n)
    bool Delete(int a)
    {
        if(a<0&&a>=n)
            return false;
        else
        {
            Node *t;
            a--;
            while(a--)
                t=t->link;
            t->link=t->link->link;
            t=t->link;
            t->pre=t->pre->pre;
            return true;
        }
    }//删除O(n)
    bool print()
    {
        if(n==0)
            return false;
        else
        {
            Node *t;
            t=first;
            for(int i=0;i<n;i++)
            {
                t=t->link;
                printf("%d%c",t->element,i==n-1?'\n':' ');
                return true;
            }
        }
    }//输出O(n)
    void free()
    {
        Node *t;
        while(n--)
        {
            t=first->link;
            delete first;
            first=t;
        }
    }//释放O(n)
}Duelist;//双向链表
struct Polynominal
{
    Singlelist *L;
    Polynominal()
    {
        L=new Singlelist;
        L->Init();
    }
    void multi(Polynominal &T)
    {
        Singlelist *D=new Singlelist();
        Node *t=L->first;
        for(;t!=NULL;t=t->link)
        {
            Node *d=T.L->first;
            for(;d!=NULL;d=d->link)
            {
                Node *temp=new Node;
                temp->element=t->element+d->element;
                temp->p=t->p*d->p;
                D->Insert(D->n,temp->element,temp->p);
            }//逐项相乘
        }
        D->Sort();
        t=L->first;
        for(;t->link!=NULL;t=t->link)
        {
            while(t->element==t->link->element)
            {
                t->p+=t->link->p;
                t->link=t->link->link;
            }
        }//合并同次
        L->free();
        L=D;
    }//乘法
    void print()
    {
        Node *t=L->first;
        for(;t!=NULL;t=t->link)
            printf("%dx^%d%c",t->p,t->element,t->link==NULL?'\n':'+');
    }
};//多项式
int main()
{
    int n;
    scanf("%d",&n);
    Polynominal D,T;
    for(int i=0;i<n;i++)
    {
        int a,p;
        scanf("%d %d",&a,&p);
        D.L->Insert(D.L->n,p,a);
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,p;
        scanf("%d %d",&a,&p);
        T.L->Insert(T.L->n,p,a);
    }
    T.multi(D);
    T.print();
    getchar();
}
