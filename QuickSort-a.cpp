/****************************************************************
Copyright:哪有神马版权呀(╯‵□′)╯︵┻━┻
Author:sumy
Date:2013-06-21
Description:快速排序的一种写法，第一次学快速排序就是用的这个
*****************************************************************/
#include <iostream>

using namespace std;

void quicksort(int a[],int first,int last)
{
    int l=first,r=last;
    int mid=a[(l+r)/2];
    while(l<=r)
    {
        while(a[l]<mid) l++;
        while(a[r]>mid) r--;
        if(l<=r)
        {
            swap(a[l],a[r]);
            l++;
            r--;
        }
    }
    if(first<r) quicksort(a,first,r);
    if(l<last) quicksort(a,l,last);
}

int num[100]={10,5,2,3,9,55,-4,6};
int main()
{
    quicksort(num,0,7);
    for(int i=0;i<8;i++)
        cout<<num[i]<<" ";
    cout<<endl;
    return 0;
}
