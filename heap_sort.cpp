#include <bits/stdc++.h>
using namespace std;
void insert (int a[],int n)
{
    int temp=a[n];
    int i=n;
    while(i>0 && temp>a[i/2])
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}
void deleteE (int a[],int n)
{
    int temp=a[n];
    a[n]=a[0];
    a[0]=temp;
    int i=0;
    int j=(2*i)+1;
    while(j<=n-1)
    {
        if(a[j]<a[j+1] && j<n-1)
            j++;
        if(a[j]>a[i])
        {
            int l=a[j];
            a[j]=a[i];
            a[i]=l;
            i=j;
            j=(i*2)+1;
        }
        else
            break;
    }
}
void heapSort (int a[], int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        insert (a,i);
    }
    for(i=0;i<=n;i++)
        cout<<a[i]<<" ";
    for(i=n;i>=0;i--)
    {
        deleteE (a,i);
        for(int x=0;x<=n;x++)
            cout<<"Hi "<<a[x]<<" ";
    }
}
