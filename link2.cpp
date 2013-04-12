#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
struct node
{
    char data;
    node* next;
};
node *str1;
node *str2;
void printlink(node *p)
{
    while(p)
    {
        cout<<p->data;
        p=p->next;
    }
    cout<<endl;
}
void buildlink()
{
    stack<char> stra;
    stack<char> strb;
    node *strsame,*p,*q;
    char a[100]="loading";
    char b[100]="being";
//    cin>>a;
//    cin>>b;
    while(!stra.empty()) stra.pop();
    while(!strb.empty()) strb.pop();
    int i=0;
    while(a[i])
    {
        stra.push(a[i]);
        i++;
        //cout<<stra.top()<<endl;
    }
    i=0;
    while(b[i])
    {
        strb.push(b[i]);
        i++;
        //cout<<strb.top()<<endl;
    }
    p=NULL;
    q=NULL;
    while(!stra.empty()&&!strb.empty()&&stra.top()==strb.top())
    {
        p=new node;
        p->data=stra.top();
        p->next=q;
        q=p;
        //printlink(p);
        //cout<<stra.top()<<strb.top()<<endl;
        stra.pop();
        strb.pop();
    }
    strsame=q;
    while(!stra.empty())
    {
        p=new node;
        p->data=stra.top();
        p->next=q;
        q=p;
        //printlink(q);
        //cout<<stra.top()<<endl;
        stra.pop();
    }
    str1=new node;
    str1->next=q;
    q=strsame;
    while(!strb.empty())
    {
        p=new node;
        p->data=strb.top();
        p->next=q;
        q=p;
        strb.pop();
    }
    str2=new node;
    str2->next=p;
}

int main()
{
    buildlink();
    printlink(str1->next);
    printlink(str2->next);
    int lenstr1=0;
    int lenstr2=0;
    node *p=str1->next;
    node *q=str2->next;
    while(p)
    {
        lenstr1++;
        p=p->next;
    }
    while(q)
    {
        lenstr2++;
        q=q->next;
    }
    p=str1->next;
    q=str2->next;
    while(1)
    {
        if(lenstr1>lenstr2)
        {
            p=p->next;
            lenstr1--;
        }
        else if(lenstr2>lenstr1)
        {
            q=q->next;
            lenstr2--;
        }
        else
        {
            if(p==q) break;
            lenstr1--;
            lenstr2--;
            p=p->next;
            q=q->next;
        }
    }
    cout<<"pos:"<<p->data<<endl;
    return 0;
}
