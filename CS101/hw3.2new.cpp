#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

void insertion(long *array,int n){
    for(int i=1;i<n;++i){
        if(array[i]==0&&array[i+1]!=0){
            continue;
        }
        else if(array[i]==0&&array[i+1]==0){
            break;
        }
        else{
            int tmp=array[i];
            for(int j=i;j>0;--j){
                if(array[j-1]>tmp){
                    array[j]=array[j-1];
                }
                else{
                    array[j]=tmp;
                    goto finished;
                }
            }
            array[0]=tmp;
            finished: ;
        }
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
            a[i][k]=0;
        }
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
    for(int i=0;i<n+1;i++){
        printf("\n");
        for(int k=0;k<n+1;k++){
            printf("%d ",a[i][k]);
        }
    }

/*for(int i=1;i<n+1;i++){
        printf("\n");
        for (int j=1;j<i;j++){
            printf("%d ",a[i][j]);
        }
    }*/    

    for(int i=1;i<n+1;i++){
        for (int j=1;j<i;j++){
            for(int k=j;k>1;--k){
                int temp;
                if(a[i][k-1]){
                    if(a[i][k-1]>a[i][k]){
                        int temp=a[i][k-1];
                        a[i][k-1]=a[i][k];
                        a[i][k]=temp;
                    }
                }
            }    
        }
    }

    /*for(int i=1;i<n+1;i++){
        printf("\n");
        for (int j=1;j<i;j++){
            printf("%d ",a[i][j]);
        }
    }*/    
    /*for(int i=0;i<n*(n-1)/2;i++){
        printf("%d ",p[i]);
    }*/
    long *p=new long[1000]();
    int iter=0;
    for(int i=1;i<n+1;i++){
        for(int j=i;j<n+1;j++){
            if(a[j][i]!=0){
                p[iter]=a[j][i];
                iter+=1;
            }
        }
    }
    insertion(p,1000);
    printf("\n");
    for(int i=0;i<n*(n-1)/2;i++){
        printf("%d ",p[i]);
    }
    //printf("%ld",p[k-1]);
}