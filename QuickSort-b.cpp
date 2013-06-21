/****************************************************************
Copyright:哪有神马版权呀(╯‵□′)╯︵┻━┻
Author:sumy
Date:2013-06-21
Description:现在比较流行的快速排序的写法
*****************************************************************/
#include <iostream>

using namespace std;
int partition(int a[],int first,int last)
{
    int l=first,r=last;
    while(l<r)
    {
        while(l<r&&a[l]<=a[r]) r--;
        if(l<r)
        {
            swap(a[l],a[r]);
            l++;
        }
        while(l<r&&a[l]<=a[r]) l++;
        if(l<r)
        {
            swap(a[l],a[r]);
            r--;
        }
    }
    return l;
}
void quicksort(int a[],int first,int last)
{
    if(first<last)
    {
        int pivot=partition(a,first,last);
        quicksort(a,first,pivot-1);
        quicksort(a,pivot+1,last);
    }
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
