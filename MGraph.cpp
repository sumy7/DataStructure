/****************************************************************
Copyright:哪有神马版权呀(╯‵□′)╯︵┻━┻
Author:sumy
Date:2013-06-07
Description:图的邻接矩阵存储，只实现了构造与深度、广度优先遍历
*****************************************************************/

#include <iostream>

using namespace std;

const int MaxSize = 10;

template<class T>
class MGraph
{
public:
    MGraph(T a[],int n,int e);
    ~MGraph(){}
    T GetVex(int i);
    void PutVex(int i,T value);
    void InsertVex(int i,T value);
    void DeleteVex(int i);
    void InsertArc(int i,int j);
    void DeleteArc(int i,int j);
    void DFSTraverse(int v);
    void BFSTraverse(int v);
private:
    T vertex[MaxSize];
    int arc[MaxSize][MaxSize];
    int vertexNum,arcNum;
    int visited[MaxSize];
    void _DFSTraverse(int v);
    void _BFSTraverse(int v);
};

template<class T>
MGraph<T>::MGraph(T a[],int n,int e)
{
    vertexNum=n;
    arcNum=e;
    for(int i=0;i<vertexNum;i++)
    {
        vertex[i]=a[i];
    }
    for(int i=0;i<vertexNum;i++)
    {
        for(int j=0;j<vertexNum;j++)
        {
            arc[i][j]=0;
        }
    }
    for(int k=0;k<arcNum;k++)
    {
        int u,v;
        cin>>u>>v;
        arc[u][v]=1;
        arc[v][u]=1;
    }
}
template<class T>
void MGraph<T>::DFSTraverse(int v)
{
    for(int i=0;i<MaxSize;i++)
    {
        visited[i]=0;
    }
    _DFSTraverse(v);
}
template<class T>
void MGraph<T>::_DFSTraverse(int v)
{
    cout<<vertex[v];
    visited[v]=1;
    for(int j=0;j<vertexNum;j++)
    {
        if(arc[v][j]==1&&visited[j]==0)
            _DFSTraverse(j);
    }
}
template<class T>
void MGraph<T>::BFSTraverse(int v)
{
    for(int i=0;i<MaxSize;i++)
    {
        visited[i]=0;
    }
    _BFSTraverse(v);
}
template <class T>
void MGraph<T>::_BFSTraverse(int v)
{
    int front,rear;
    int Q[MaxSize];
    front=rear=-1;
    cout<<vertex[v];
    visited[v]=1;
    Q[++rear]=v;
    while(front!=rear)
    {
        v=Q[++front];
        for(int j=0;j<vertexNum;j++)
        {
            if(arc[v][j]==1&&visited[j]==0)
            {
                cout<<vertex[j];
                visited[j]=1;
                Q[++rear]=j;
            }
        }
    }
}
template<class T>
void MGraph<T>::PutVex(int i,T value)
{
    vertex[i]=value;
}
int main()
{
    char a[5]={'0','1','2','3'};
    MGraph<char> gra(a,4,4);
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
