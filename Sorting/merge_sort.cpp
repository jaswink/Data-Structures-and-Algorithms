#include <bits/stdc++.h>
using namespace std;
void merge (int a[],int l, int m, int h)
{
    int i=l;
    int k=l;
    int j=m+1;
    int b[1000];
    while(i<=m && j<=h)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    for(;i<=m;i++)
        b[k++]=a[i];
    for(;j<=h;j++)
        b[k++]=a[j];
    for(int c=l;c<=h;c++)
        a[c]=b[c];//cout<<a[i]<<" ";}
}
void mergeSort (int a[], int l, int h)
{//cout<<"hi\n";
    if(l<h)
    {
        int m=(l+h)/2;//cout<<l<<m<<h;
        mergeSort(a,l,m);
        mergeSort(a,m+1,h);
        merge(a,l,m,h);
    }
}
