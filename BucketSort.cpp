/****************************************************************
Copyright:哪有神马版权呀(╯‵□′)╯︵┻━┻
Author:sumy
Date:2013-07-05
Description:桶式排序的简单实现。发现数据结构课本上有好多错误呀
*****************************************************************/

#include <iostream>

using namespace std;
const int maxQueue=500;
const int maxNode=500;
struct Node
{
    int key;
    int next;
};
struct QueueNode
{
    int front;
    int rear;
};
void Distribute(Node r[],int n,QueueNode q[],int m,int first)
{
    int i=first;
    while(i!=-1)
    {
        int k=r[i].key;
        if(q[k].front==-1) q[k].front=i;
        else r[q[k].rear].next=i;
        q[k].rear=i;
        i=r[i].next;
    }
}
void Collect(Node r[],int n,QueueNode q[],int m,int &first)
{
    int k=0;
    while(q[k].front==-1&&k<m)
    {
        k++;
    }
    first=q[k].front;
    int last=q[k].rear;
    while(k<m)
    {
        k++;
        if(q[k].front!=-1)
        {
            r[last].next=q[k].front;
            last=q[k].rear;
            //cout<<k<<"---"<<q[k].rear<<"---"<<last<<endl;
        }
    }
    r[last].next=-1;
}
int BucketSort(Node r[],int n,int m)
{
    QueueNode q[maxQueue];
    for(int i=0;i<n;i++)
    {
        r[i].next=i+1;
    }
    r[n-1].next=-1;
    int first=0;
    for(int i=0;i<=m;i++)
    {
        q[i].front=q[i].rear=-1;
    }
    Distribute(r,n,q,m,first);
    Collect(r,n,q,m,first);
    return first;
}

Node r[maxNode]={{12,0},{25,0},{3,0},{6,0},{8,0}};
int main()
{
    int p=BucketSort(r,5,30);
    cout<<"head-index:"<<p<<endl;
    while(p!=-1)
    {
        cout<<r[p].key<<endl;
        p=r[p].next;
    }
    return 0;
}
