//by sumy
#include <iostream>

template<typename T> class LinkSeq;
template<typename T>
class Node
{
    private:
        T Data;
        Node<T> *next;
        friend class LinkSeq<T>;
};

template<typename T>
class LinkSeq
{
    private:
        Node<T> *first;
        friend class Node<T>;
    public:

        LinkSeq();
        LinkSeq(T a[],int n);
        void Insert(T a,int n);
        void Delete(int n);
        void Printlink();
        void Reversal();
        T GetAt(int n);
        ~LinkSeq();

};
template<typename T>
LinkSeq<T>::LinkSeq()
{
    first=new Node<T>;
    first->Data=0;
    first->next=NULL;
}

template<typename T>
LinkSeq<T>::LinkSeq(T a[],int n)
{
    first=new Node<T>;
    first->Data=0;
    Node<T> *p=first;
    for(int i=0;i<n;i++)
    {
        Node<T> *q=new Node<T>;
        q->Data=a[i];
        p->next=q;
        p=q;
    }
    p->next=NULL;
}

template<typename T>
void LinkSeq<T>::Insert(T a,int n)
{
    int Count=0;
    Node<T> *p=first;
    while(Count<n&&p->next)
    {
        p=p->next;
        Count++;
    }
    if(p)
    {
        Node<T> *q=new Node<T>();
        q->Data=a;
        q->next=p->next;
        p->next=q;
    }
}

template<typename T>
void LinkSeq<T>::Delete(int n)
{
    int Count=0;
    Node<T> *p=first;
    while(Count<n-1&&p)
    {
        p=p->next;
        Count++;
    }
    if(p->next)
    {
        Node<T> *q=p->next;
        p->next=q->next;
        delete q;
    }
    else
    {
        throw "É¾³ýÊ§°Ü¡£";
    }
}

template<typename T>
void LinkSeq<T>::Printlink()
{
    Node<T> *p=first->next;
    std::cout<<"LinkPrint:";
    while(p)
    {
        std::cout<<p->Data<<" ";
        p=p->next;
    }
    std::cout<<std::endl;
}

template<typename T>
void LinkSeq<T>::Reversal()
{
    Node<T> *p=first->next,*q,*r;
    //first->next=NULL;
    if(p) q=p->next;
    else q=NULL;
    p->next=NULL;
    while(q)
    {
        r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    //if(q) q->next=p;
    first->next=p;
}

template<typename T>
T LinkSeq<T>::GetAt(int n)
{
    int Count=0;
    Node<T> *p=first;
    while(Count<n&&p)
    {
        p=p->next;
        Count++;
    }
    if(p) return p->Data;
    else throw "位置。";
}

template<typename T>
LinkSeq<T>::~LinkSeq()
{
    Node<T> *p;
    while(first)
    {
        p=first;
        first=first->next;
        delete p;
    }
}
using namespace std;

int main()
{
    int number[10]={1,3,5,9,6,5,7,8,2,3};
    LinkSeq<int> link(number,1);
    link.Printlink();
    link.Insert(10,9);
    //link.Delete(10);u
    //link.Reversal();
    //cout<<link.GetAt(1)<<endl;
    link.Printlink();
    return 0;
}
