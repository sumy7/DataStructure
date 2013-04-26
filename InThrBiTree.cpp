/*************************************************
Copyright:哪有神马版权呀(╯‵□′)╯︵┻━┻
Author:sumy
Date:2013-04-26
Description:中序线索二叉树示例
PS:数据结构课本有好多坑呀
**************************************************/

#include <iostream>
using namespace std;

template<class T> class InThrBiTree;
template<class T>
class ThrNode
{
 private:
    T data;
    ThrNode *lchild;
    ThrNode *rchild;
    int ltag,rtag;
 public:
    friend class InThrBiTree<T>;
    ThrNode()
    {
        lchild=NULL;
        rchild=NULL;
        ltag=0;
        rtag=0;
    }
};

template<class T>
class InThrBiTree
{
public:
    InThrBiTree()
    {
        root=Creat(root);
        pre=NULL;
        ThrBiTree(root);
    }
    ~InThrBiTree()
    {
        Release(root);
    }
    ThrNode<T>* Next(ThrNode<T> *p);
    void InOrder();
private:
    ThrNode<T> *root;
    ThrNode<T> *Creat(ThrNode<T> *bt);
    void Release(ThrNode<T> *bt);
    ThrNode<T> *pre;
    void ThrBiTree(ThrNode<T> *bt);
};

template<class T>
ThrNode<T> *InThrBiTree<T>::Creat(ThrNode<T> *bt)
{
    char ch;
    cin>>ch;
    if(ch=='#') bt=NULL;
    else
    {
        bt=new ThrNode<T>;
        bt->data=ch;
        bt->ltag=0;
        bt->rtag=0;
        bt->lchild=Creat(bt->lchild);
        bt->rchild=Creat(bt->rchild);
    }
    return bt;
}

template<class T>
void InThrBiTree<T>::Release(ThrNode<T> *bt)
{
    if(bt!=NULL)
    {
        if(bt->ltag==0) Release(bt->lchild);
        if(bt->rtag==0) Release(bt->rchild);
        delete bt;
    }
}

template<class T>
void InThrBiTree<T>::ThrBiTree(ThrNode<T> *bt)
{
    if(bt==NULL) return;
    ThrBiTree(bt->lchild);
    if(bt->lchild==NULL)
    {
        bt->ltag=1;
        bt->lchild=pre;
    }
    if(bt->rchild==NULL) bt->rtag=1;
    if(pre!=NULL)
        if(pre->rtag==1) pre->rchild=bt;
    pre=bt;
    ThrBiTree(bt->rchild);
}

template<class T>
ThrNode<T> *InThrBiTree<T>::Next(ThrNode<T> *p)
{
    ThrNode<T> *q;
    if(p->rtag==1) q=p->rchild;
    else
    {
        q=p->rchild;
        while(q->ltag==0)
            q=q->lchild;
    }
    return q;
}

template<class T>
void InThrBiTree<T>::InOrder()
{
    ThrNode<T> *q;
    if(root==NULL) return;
    q=root;
    while(q->ltag==0)
    {
        q=q->lchild;
    }
    cout<<q->data;
    while(q->rchild!=NULL)
    {
        q=Next(q);
        cout<<q->data;
    }
}

int main()
{
    InThrBiTree<char> tre=InThrBiTree<char>();
    tre.InOrder();
    cout<<endl;
    return 0;
}

/*

AB#CE##D######
AB#D##C##

*/
