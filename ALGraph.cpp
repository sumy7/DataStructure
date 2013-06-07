/****************************************************************
Copyright:哪有神马版权呀(╯‵□′)╯︵┻━┻
Author:sumy
Date:2013-06-07
Description:图的邻接表存储，只实现了构造与深度、广度优先遍历
*****************************************************************/
#include <iostream>

using namespace std;
const int MaxSize = 10;

template<class T> class ALGraph;
template<class T> class VertexNode;

template<class T>
class ArcNode
{
private:
    int adjvex;
    ArcNode *next;
    friend class VertexNode<T>;
    friend class ALGraph<T>;
};

template<class T>
class VertexNode
{
private:
    T vertex;
    ArcNode<T> *firstedge;
    friend class ALGraph<T>;
};

template<class T>
class ALGraph
{
public:
    ALGraph(T a[],int n,int e);
    ~ALGraph(){}
    T GetVex(int i);
    void PutVex(int i,T value);
    void InsertVex(int i,T value);
    void DeleteVex(int i);
    void InsertArc(int i,int j);
    void DeleteArc(int i,int j);
    void DFSTraverse(int v);
    void BFSTraverse(int v);
private:
    VertexNode<T> adjlist[MaxSize];
    int vertexNum,arcNum;
    int visited[MaxSize];
    void _DFSTraverse(int v);
    void _BFSTraverse(int v);
};

template<class T>
ALGraph<T>::ALGraph(T a[],int n,int e)
{
    ArcNode<T> *s;
    vertexNum=n;arcNum=e;
    for(int i=0;i<vertexNum;i++)
    {
        adjlist[i].vertex=a[i];
        adjlist[i].firstedge=NULL;
    }
    for(int k=0;k<arcNum;k++)
    {
        int u,v;
        cin>>u>>v;
        s=new ArcNode<T>;
        s->adjvex=v;
        s->next=adjlist[u].firstedge;
        adjlist[u].firstedge=s;
    }
}
template<class T>
void ALGraph<T>::DFSTraverse(int v)
{
    for(int i=0;i<MaxSize;i++)
    {
        visited[i]=0;
    }
    _DFSTraverse(v);
}
template<class T>
void ALGraph<T>::_DFSTraverse(int v)
{
    cout<<adjlist[v].vertex;
    visited[v]=1;
    ArcNode<T> *p=adjlist[v].firstedge;
    while(p)
    {
        int j=p->adjvex;
        if(visited[j]==0) _DFSTraverse(j);
        p=p->next;
    }
}
template<class T>
void ALGraph<T>::BFSTraverse(int v)
{
    for(int i=0;i<MaxSize;i++)
    {
        visited[i]=0;
    }
    _BFSTraverse(v);
}
template<class T>
void ALGraph<T>::_BFSTraverse(int v)
{
    int front,rear;
    front=rear=-1;
    int Q[MaxSize];
    ArcNode<T> *p;
    cout<<adjlist[v].vertex;
    visited[v]=1;
    Q[++rear]=v;
    while(front!=rear)
    {
        v=Q[++front];
        p=adjlist[v].firstedge;
        while(p)
        {
            int j=p->adjvex;
            if(visited[j]==0)
            {
                cout<<adjlist[j].vertex;
                visited[j]=1;
                Q[++rear]=j;
            }
            p=p->next;
        }
    }
}
int main()
{
    char a[MaxSize]={'0','1','2','3','4'};
    ALGraph<char> gra(a,4,4);
    gra.BFSTraverse(0);
    cout<<endl;
    gra.DFSTraverse(0);
    cout<<endl;
    return 0;
}
/*
0 3
0 1
1 2
1 3
*/
