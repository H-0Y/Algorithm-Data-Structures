#include <stdlib.h>
#include <iostream>
using namespace std;

int remove_repeat(int *a, int l)
{
    int i, j, k;
     
    for(i = 1; i < l; i ++)
    {
        for(j = i+1; j <l; j ++)
        {
            if(a[j] == a[i])
            {
                for(k = j+1; k<l; k ++)
                    a[k-1] = a[k];
                l--;
            }
        }
    }
    return l;

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
    int j=0;
    int count=0;
    cin>>n;
    cin>>edges;
    cin>>k;
    int *num=new int[3*edges];
    for(int i=0;i<3*edges;i++){
        cin>>num[i];
    }

    int *newnum=new int[edges];
    for(int i=2;i<3*edges;i+=3){
        newnum[j]=num[i];
        j++;
    }
    
    
    heapSort(newnum,0,edges);
    
    
    int limit=newnum[k-1];

    int *node1=new int[400000];
    int *node2=new int[400000];
    int *weight=new int[400000];
    


    int **a=new int*[2*k+1];          //build the matrix
	for(int i=0;i<2*k+1;i++){
		a[i]=new int[2*k+1];           
    }                                   //end
    
    for(int i=0;i<2*k+1;i++){           //initialize the matrix
        for(int u=0;u<2*k+1;u++){
            a[i][u]=1000000001;
        }
        a[i][i]=0;
    }                                   //end
   
    for(int i=0;i<3*edges;i+=3){
        if(num[i+2]<=limit){
            node1[count]=num[i];
            node2[count]=num[i+1];
            weight[count]=num[i+2];
            count++;
        }
    }
    int *mergearray=new int[500000];
    int *mergearray2=new int[500000];
    for(int i=0;i<n;i++){
        mergearray[i]=0;
    }
    
    int newcount=1;
    for(int i=0;i<count;){
        mergearray[newcount]=node1[i];
        newcount++;
        mergearray[newcount]=node2[i];
        newcount++;
        ++i;
    }
    /*for(int i=0;i<count;i++){
        cout<<node1[i];
    }
    printf("\n");
    for(int i=0;i<count;i++){
        cout<<node2[i];
    }*/
    /*for(int i=1;i<2*count+1;i++){
        cout<<mergearray[i];
    }*/
    for(int i=0;i<2*count+1;i++){
        mergearray2[i]=mergearray[i];
    }
    //printf("\n");
    int shorterlenth=2*count+1;
    shorterlenth=remove_repeat(mergearray2,shorterlenth);
    //printf("\n");
    //cout<<shorterlenth;
    /*for(int i=1;i<shorterlenth;i++){
        cout<<mergearray2[i];
    }*/
    /*printf("\n");
    for(int i=1;i<2*count+1;i++){
        cout<<mergearray[i];
    }
    printf("\n");*/
    for(int i=1;i<2*count+1;i++){
        for(int j=1;j<shorterlenth;j++){
            if(mergearray[i]==mergearray2[j]){
                mergearray[i]=j;
                break;
            }
        }
    }
    /*for(int i=1;i<2*count+1;i++){
        cout<<mergearray[i];
    }*/
   /* printf("\n");
    for(int i=0;i<count;i++){
        cout<<node2[i];
    }*/

    
    
   /*for(int i=0;i<n+1;i++){
        printf("\n");
        for(int k=0;k<n+1;k++){
            printf("%d ",a[i][k]);
        }
    }*/
    int countcount=0;
    for(int i=1;i<2*count+1;i+=2){
        a[mergearray[i]][mergearray[i+1]]=weight[countcount];
        a[mergearray[i+1]][mergearray[i]]=weight[countcount];
        countcount++;
    }
    

    /*for(int i=0;i<2*k+1;i++){
        printf("\n");
        for(int j=0;j<2*k+1;j++){
            printf("%d ",a[i][j]);
        }
    }*/

    for(int u=1;u<2*k+1;++u){
        for(int i=1;i<2*k+1;++i){
            for(int j=1;j<2*k+1;++j){
                if(a[i][j]>=a[i][u]+a[u][j])
                a[i][j]=a[i][u]+a[u][j];
            }
        }
    }

    /*printf("-----------------------------------------------");
    for(int i=0;i<2*k+1;i++){
        printf("\n");
        for(int j=0;j<2*k+1;j++){
            printf("%d ",a[i][j]);
        }
    }*/

    int *p=new int[2*k*2*k]();
    int init=0;
    for(int i=1;i<2*k+1;i++){
        //printf("\n");
        for (int j=1;j<i;j++){
           p[init]=a[i][j];
           init+=1;
        }
    }

   /* for(int i=0;i<2*k*(2*k-1)/2;i++){
        printf("%d ",p[i]);
    }*/

    heapSort(p,0,2*k*(2*k-1)/2);
    /*printf("\n");
    for(int i=0;i<2*k*(2*k-1)/2;i++){
        printf("%d ",p[i]);
    }*/
    printf("%d",p[k-1]);

}