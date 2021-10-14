#include <stdlib.h>
#include <iostream>
using namespace std;


template<typename Type>
class Quene{
    private:
        int quene_size;
        int ifront;
        int iback;
        int array_capacity;
    public:
        Type *array;
        Quene(int = 10);
        //~Quene(); 
        bool empty() const;
        Type front() const;
        void push (Type const &);
        Type pop();
        void show();
};

template<typename Type>
Quene<Type>::Quene(int n):
quene_size(0),iback(-1),ifront(0),array_capacity(max(1,n)),array(new Type[array_capacity]){
    // Empty constructor
}

template<typename Type>
bool Quene<Type>::empty() const{
    return (quene_size==0);
}

template<typename Type>
Type Quene<Type>::front() const{
    if(empty()){
       
    }

    return array[ifront];
}

template<typename Type>
void Quene<Type>::push(Type const &obj){
    ++iback;
    array[iback]=obj;
}

template<typename Type>
void Quene<Type>::show(){
    while(ifront<iback+1){
        printf("%d",array[ifront]);
        ifront++;
    }
}


int main(){
    
    int n,i,j,k,l,a,maxnum,count=0;
    cin>>n;
    Quene<int> aaa(n);
    for(k=0;k<n;k++){
        cin>>l;
        aaa.push(l);
    }
    //aaa.show();
    for(i=0;i<n;i++){
        maxnum=aaa.array[i+1];
        for(j=i+2;j<n;j++){
            if(aaa.array[j-1]>maxnum) maxnum=aaa.array[j-1];
            if(maxnum>aaa.array[i]) break;
            if(maxnum<=min(aaa.array[j],aaa.array[i])) count++;       
        }
    }
    cout<<count+n-1;
    return 0;
}