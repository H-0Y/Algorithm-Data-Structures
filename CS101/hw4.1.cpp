#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

int gcd(int a,int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

int daq(int *ar, int left ,int right){
    int mid=(left+right)/2+1;
    if(left+1==right){
        return gcd(ar[left],ar[right]);
    }
    else{
        daq(ar,left,mid);
        
    }
}

int main(){
    int a[10]={1,3,4,2,5,34,21,32,30,22};
    cout<<daq(a,0,10);



}