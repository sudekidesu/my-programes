#include<cstdio>
#include<iostream>
// #include<algorithm>
#include<cstring>
using namespace std;
typedef char T;
struct BinaryTreeNode
{
    T Data;
    BinaryTreeNode *LChild,*RChild;
    BinaryTreeNode()
    {
        LChild=NULL;
        RChild=NULL;
    }
}*BinTree;//二叉树结点
BinaryTreeNode *PreCreateTree(BinaryTreeNode *t)
{
    T ch;
    ch=getchar();
    if(ch=='#')
        t=NULL;
    else
    {
        t->Data=ch;
        t->LChild=new BinaryTreeNode;
        t->RChild=new BinaryTreeNode;
        t->LChild=PreCreateTree(t->LChild);
        t->RChild=PreCreateTree(t->RChild);
    }
    return t;
}//先序建树
void PreOrderTransverse(BinaryTreeNode *t)
{
    if(t==NULL)
        return;
    cout<<t->Data;
    PreOrderTransverse(t->LChild);
    PreOrderTransverse(t->RChild);
}//先序遍历
void InOrderTransverse(BinaryTreeNode *t)
{
    if(t==NULL)
        return;
    InOrderTransverse(t->LChild);
    cout<<t->Data;
    InOrderTransverse(t->RChild);
}//中序遍历
void PostOrderTransverse(BinaryTreeNode *t)
{
    if(t==NULL)
        return;
    PostOrderTransverse(t->LChild);
    PostOrderTransverse(t->RChild);
    cout<<t->Data;
}//后序遍历
int CountNode(BinaryTreeNode *t)
{
    if(t==NULL)
        return 0;
    return CountNode(t->LChild)+CountNode(t->RChild)+1;
}//结点计数
int CountLeaf(BinaryTreeNode *t)
{
    if(t==NULL)
        return 0;
    else if(t->LChild==NULL&&t->RChild==NULL)
        return 1;
    else
        return CountLeaf(t->LChild)+CountLeaf(t->LChild);
}//叶节点计数
int Hight(BinaryTreeNode *t)
{
    if(t==NULL)
        return 0;
    else
        return 1+max(Hight(t->LChild),Hight(t->RChild));
}//二叉树求高
void ReverseTree(BinaryTreeNode *t)
{
    if(t==NULL)
        return;
    swap(t->LChild,t->RChild);
    ReverseTree(t->LChild);
    ReverseTree(t->RChild);
}//二叉树左右反转
struct HFMTnode
{
    T data;
    int w;
    HFMTnode /**parent,*/*LChild,*RChild;
    HFMTnode()
    {
        /*parent=*/LChild=RChild=NULL;
    }
}*HFM;//哈夫曼树结点
HFMTnode *CreatHFM()
{
    HFMTnode *HFM;
    int n;
    cin>>n;
    HFM=new HFMTnode[2*n];
    for(int i=0;i<n;i++)
        cin>>HFM[i].data>>HFM[i].w;
    int l=0;
    while(l<n-1)
    {
        for(int i=l;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(HFM[i].w>HFM[j].w)
                    swap(HFM[i],HFM[j]);
        HFM[n].w=HFM[l].w+HFM[l+1].w;
        // HFM[l].parent=HFM[l+1].parent=HFM+n;
        HFM[n].LChild=HFM+l;
        HFM[n].RChild=HFM+l+1;
        n++;
        l+=2;
    }
    return HFM+n-1;
}//哈夫曼建树
char bm[10000];
int n=0;
void HFMB(HFMTnode *t)
{
    if(t==NULL)
        return;
    n++;
    if(t->LChild==NULL&&t->RChild==NULL)
    {
        bm[n]='\0';
        cout<<t->data<<" "<<bm+1<<endl;
    }
    else
    {
        bm[n]='0';
        HFMB(t->LChild);
        bm[n]='1';
        HFMB(t->RChild);
    }
    n--;
}//哈夫曼编码
void HFMJ()
{
    char jm[10000];
    cin>>jm;
    HFMTnode *t=HFM;
    for(int i=0;jm[i]!='\0';i++)
    {
        if(jm[i]=='0')
            t=t->LChild;
        else
            t=t->RChild;
        if(t->LChild==NULL&&t->RChild==NULL)
        {
            cout<<t->data;
            t=HFM;
        }
    }
    cout<<endl;
}//哈夫曼解码
int main()
{
    // BinTree=new BinaryTreeNode;
    // PreCreateTree(BinTree);
    // PreOrderTransverse(BinTree);
    // cout<<endl;
    // InOrderTransverse(BinTree);
    // cout<<endl;
    // PostOrderTransverse(BinTree);
    // cout<<endl;
    // ReverseTree(BinTree);
    // PreOrderTransverse(BinTree);
    // cout<<endl;
    // InOrderTransverse(BinTree);
    // cout<<endl;
    // PostOrderTransverse(BinTree);
    // cout<<endl;
    HFM=CreatHFM();
    HFMB(HFM);
    HFMJ();
}
