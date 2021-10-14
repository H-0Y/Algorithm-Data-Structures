#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    int b[500000];
    int n,i,j,k,l,a,c,maxnum1,maxnum2,count=0;
    cin>>n;
     for(k=0;k<n;k++){
        cin>>l;
        b[k]=l;
    }
    for(c=0;c<n;c++){
        maxnum1=b[c];
        if(maxnum1<b[c]){
            maxnum1=b[c];
        }
    }
    //aaa.show();
    for(i=0;i<n;i++){   
        maxnum2=b[i+1];     
        for(j=i+2;j<n;j++){
            if(b[j-1]>maxnum2){
                maxnum2=b[j-1];
            }
            
            if(maxnum2>=maxnum1){
                break;
            }
            if(maxnum2<=b[j]&&maxnum2<=b[i]){
               count++;
            }
            
        }
    }
    cout<<count+n-1;
    return 0;
}