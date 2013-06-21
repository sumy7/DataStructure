/****************************************************************
Copyright:哪有神马版权呀(╯‵□′)╯︵┻━┻
Author:sumy
Date:2013-06-21
Description:二叉排序树
*****************************************************************/
#include <iostream>

using namespace std;
template<class T>
class BiNode
{
private:
    BiNode<T> *lchild;
    BiNode<T> *rchild;
    T data;
    friend class BiSortTree;
};

class BiSortTree
{
public:
    BiSortTree(int a[],int n);
    ~BiSortTree()
    {
        deleteTree(root);
    }
    void InsertBST(BiNode<int> *&root,BiNode<int> *s);
    void DeleteBST(BiNode<int> *p,BiNode<int> *f);
    BiNode<int> *SearchBST(BiNode<int> *root,int k);
    void OrderTravel()
    {
        _OrderTravel(root);
    }
private:
    BiNode<int> *root;
    void _OrderTravel(BiNode<int> *bt);
    void deleteTree(BiNode<int> *bt);
};

BiSortTree::BiSortTree(int r[],int n)
{
    BiNode<int> *s;
    root=NULL;
    for(int i=0;i<n;i++)
    {
        s=new BiNode<int>;
        s->data=r[i];
        s->lchild=s->rchild=NULL;
        InsertBST(root,s);
    }
}
void BiSortTree::InsertBST(BiNode<int> *&root,BiNode<int> *s)
{
    if(root==NULL) root=s;
    else if(s->data<root->data)
        InsertBST(root->lchild,s);
    else
        InsertBST(root->rchild,s);
}
void BiSortTree::_OrderTravel(BiNode<int> *bt)
{
    if(bt!=NULL)
    {
        _OrderTravel(bt->lchild);
        cout<<bt->data<<" ";
        _OrderTravel(bt->rchild);
    }
}
void BiSortTree::deleteTree(BiNode<int> *bt)
{
    if(bt!=NULL)
    {
        deleteTree(bt->lchild);
        deleteTree(bt->rchild);
        delete bt;
    }
}
int a[]={20,15,3,-9,1,3};
int main()
{
    BiSortTree tree(a,6);
    tree.OrderTravel();
    return 0;
}
