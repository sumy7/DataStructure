/*************************************************
Copyright:数据结构课本(╯‵□′)╯︵┻━┻
Author:sumy
Date:2013-04-19
Description:二叉树的相关操作
**************************************************/

#include <iostream>
using namespace std;

template<class T> class BiTree;
template<class T>
class BiNode
{
 private:
    T data;
    BiNode *lchild;
    BiNode *rchild;
 public:
    friend class BiTree<T>;
    BiNode()
    {
        lchild=NULL;
        rchild=NULL;
    }
};

template<class T>
class BiTree
{
public:
    BiTree()
    {
        root=Creat(root);
    }
    ~BiTree()
    {
        Release(root);
    }
    void PreOrder()
    {
        PreOrder(root);
    }
    void InOrder()
    {
        InOrder(root);
    }
    void PostOrder()
    {
        PostOrder(root);
    }
    void LeverOrder();
    int GetHeight()
    {
        if(root==NULL) return 0;
        else return GetHeight(root);
    }
private:
    BiNode<T> *root;
    BiNode<T> *Creat(BiNode<T> *bt);
    void Release(BiNode<T> *bt);
    void PreOrder(BiNode<T> *bt);
    void InOrder(BiNode<T> *bt);
    void PostOrder(BiNode<T> *bt);
    int GetHeight(BiNode<T> *bt);
    static const int maxn=100;
};

template<class T>
void BiTree<T>::PreOrder(BiNode<T> *bt)
{
    if(bt==NULL) return;
    else
    {
        cout<<bt->data;
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

template<class T>
void BiTree<T>::InOrder(BiNode<T> *bt)
{
    if(bt==NULL) return;
    else
    {
        InOrder(bt->lchild);
        cout<<bt->data;
        InOrder(bt->rchild);
    }
}

template<class T>
void BiTree<T>::PostOrder(BiNode<T> *bt)
{
    struct node
    {
        BiNode<T> *r;
        int flag;
    };
    node sta[maxn];
    int top=-1;
    while(bt!=NULL||top!=-1)
    {
        while(bt!=NULL)
        {
            top++;
            sta[top].r=bt;
            sta[top].flag=0;
            bt=bt->lchild;
        }
        while(top!=-1&&sta[top].flag==1)
        {
            bt=sta[top].r;
            top--;
            cout<<bt->data;
        }
        if(top!=-1)
        {
            sta[top].flag=1;
            bt=sta[top].r->rchild;
        }
        else break;
    }
}


template<class T>
void BiTree<T>::LeverOrder()
{
    if(root==NULL) return;
    BiNode<T> *Q[maxn];
    BiNode<T> *q;
    int l=0,r=1;
    Q[l]=root;
    while(l!=r)
    {
        q=Q[l++];
        cout<<q->data;
        if(q->lchild!=NULL) Q[r++]=q->lchild;
        if(q->rchild!=NULL) Q[r++]=q->rchild;
    }
}

template<class T>
BiNode<T> *BiTree<T>::Creat(BiNode<T> *bt)
{
    char ch;
    cin>>ch;
    if(ch=='#') bt=NULL;
    else
    {
        bt=new BiNode<T>;
        bt->data=ch;
        bt->lchild=Creat(bt->lchild);
        bt->rchild=Creat(bt->rchild);
    }
    return bt;
}

template<class T>
void BiTree<T>::Release(BiNode<T> *bt)
{
    if(bt!=NULL)
    {
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
    }
}

template<class T>
int BiTree<T>::GetHeight(BiNode<T> *bt)
{
    if(bt==NULL) return 0;
    int lheight=GetHeight(bt->lchild);
    int rheight=GetHeight(bt->rchild);
    if(lheight>rheight) return lheight+1;
    else return rheight+1;
}
int main()
{
    BiTree<char> tre=BiTree<char>();
    tre.PreOrder();
    cout<<endl;
    tre.InOrder();
    cout<<endl;
    tre.PostOrder();
    cout<<endl;
    tre.LeverOrder();
    cout<<endl;
    cout<<tre.GetHeight()<<endl;
    return 0;
}

/*

AB#CE##D######

*/
