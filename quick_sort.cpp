#include <bits/stdc++.h>
using namespace std;
void swap(int *x,int *y)
{
int temp=*x;
*x=*y;
*y=temp;
}
int partition (int a[], int l, int h)
{
    int pivot=a[l];
    int i=l,j=h;
    while(i<j)
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
            swap(&a[i],&a[j]);
    }
    swap(&a[l],&a[j]);
    return j;
}
void quickSort(int a[], int l, int h)
{
    int j; 
    if(l<h)
    {
        j=partition(a,l,h);
        quickSort(a,l,j);
        quickSort(a,j+1,h);
    }
}
int main()
{
    int n;
    int a[]={5,6,7,1,2};
    n=5;
    quickSort(a,0,n-1);
    //heapSort(a,n-1);
    for (int i=0; i < n; i++)
        cout<<a[i]<<" ";
    return 0;
}