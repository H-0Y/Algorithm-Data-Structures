#include <stdlib.h>
#include <iostream>
using namespace std;

void mySwap(int *pa, int *pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void downToMaxHeap(int *arr, int bgn, int end)
{
    int child;
    int parent = bgn;

    
    while ((child = parent * 2 + 1) < end)
    {
        if ((child < end - 1) && (arr[child] < arr[child + 1]))
            ++child;    
        if (arr[child] > arr[parent])
            mySwap(&arr[child], &arr[parent]);
        else
            break;
        parent = child;
    }
}

void buildMaxHeap(int *arr, int bgn, int end)
{
    if (bgn >= end - 1)
        return;

    int parent = end / 2 - 1;
    while (parent >= 0)
    {
        downToMaxHeap(arr, parent, end);
        --parent;
    }
}

void heapSort(int *arr, int bgn, int end)
{
    
    buildMaxHeap(arr, bgn, end);

    while (end > 1)
    {
        mySwap(&arr[0], &arr[--end]);
        downToMaxHeap(arr, 0, end);
    }
}
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    int *nn=new int[n];
    int *mm=new int[m];
    
    for(int i=0;i<n;i++){
        cin>>nn[i];
    }
    for(int i=0;i<m;i++){
        cin>>mm[i];
    }

    heapSort(nn,0,n);
    heapSort(mm,0,m);

/*for(int i=0;i<m;i++){
    cout<<mm[i];
}
for(int i=0;i<n;i++){
    cout<<nn[i];
}*/
    int j=0;
    int cost=0;
    for(int i=0;i<n;){
        if(j>=m){
            cout<<"you died!";
            break;
        }
        if(nn[i]<=mm[j]){  
            cost+=mm[j]; 
            i++;
        }
        j++;
        if(i>=n){
            cout<<cost;
        }
    }

}