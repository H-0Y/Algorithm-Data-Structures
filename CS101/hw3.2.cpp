#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
void quickSort(int *arr, int bgn, int end){  
    
    if (bgn >= end - 1)
        return;

    int lindex = bgn;
    int rindex = end - 1;
    int std = arr[lindex];
    while (lindex < rindex)
    {
        while (lindex < rindex)
        {
            if (arr[rindex] < std)
            {
                arr[lindex++] = arr[rindex];
                break;
            }
            --rindex;
        }

        while (lindex < rindex)
        {
            if (arr[lindex] >= std)
            {
                arr[rindex--] = arr[lindex];
                break;
            }
            ++lindex;
        } 
    }

    arr[lindex] = std;
    quickSort(arr, bgn, lindex);
    quickSort(arr, rindex + 1, end);
}
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
    int n,edges,k;
    cin>>n;
    cin>>edges;
    cin>>k;
    
    int **a=new int*[n+1];
	for(int i=0;i<n+1;i++){
		a[i]=new int[n+1];
    }
    for(int i=0;i<n+1;i++){
        for(int k=0;k<n+1;k++){
            a[i][k]=1000000001;
        }
        a[i][i]=0;
    }
   
    
    for(int i=0;i<edges;i++){
        long v1,v2,dis;
        scanf("%d %d %d",&v1,&v2,&dis);
        a[v1][v2]=dis;
        a[v2][v1]=dis;
    
    }

   /*for(int i=0;i<n+1;i++){
        printf("\n");
        for(int k=0;k<n+1;k++){
            printf("%d ",a[i][k]);
        }
    }*/


    for(int k=1;k<n+1;++k){
        for(int i=1;i<n+1;++i){
            for(int j=1;j<n+1;++j){
                a[i][j]=std::min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
   /*for(int i=0;i<n+1;i++){
        printf("\n");
        for(int k=0;k<n+1;k++){
            printf("%d ",a[i][k]);
        }
    }*/


int *p=new int[n*(n-1)/2]();
int init=0;
    for(int i=1;i<n+1;i++){
        //printf("\n");
        for (int j=1;j<i;j++){
           p[init]=a[i][j];
           init+=1;
        }
    }

    /*for(int i=0;i<n*(n-1)/2;i++){
        printf("%d ",p[i]);
    }*/

    heapSort(p,0,n*(n-1)/2);
    printf("\n");
    for(int i=0;i<n*(n-1)/2;i++){
        printf("%d ",p[i]);
    }
    printf("%ld",p[k-1]);
}