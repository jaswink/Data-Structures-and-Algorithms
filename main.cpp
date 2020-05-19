#include <bits/stdc++.h>
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
using namespace std;

int main()
{
    int n;
    int a[]={5,6,7,1,2};
    n=5;
    quickSort(a, 0, n-1);
    //heapSort(a,n-1);
    for (int i=0; i < n; i++)
        cout<<a[i]<<" ";
    return 0;
}
