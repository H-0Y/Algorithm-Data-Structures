#include <stdlib.h>
#include <iostream>
#include<algorithm>
using namespace std;

template<typename Type>
class Quene{
    private:
        int quene_size;
        int ifront;
        int iback;
        int array_capacity;
    public:
        int ibackfunc() const;
        int ifrontfunc() const;
        Type *array;
        Quene(int = 10);
        //~Quene(); 
        bool empty() const;
        Type front() const;
        void push (Type const &);
        Type pop();
        void show();
        Type remove();
        void add(Type const &,int pos);
        Type deletesubs(int pos);
        //void Reaction(Quene<Type> QQuene);
};

template<typename Type>
int Quene<Type>::ibackfunc() const{
    return iback;
}

template<typename Type>
int Quene<Type>::ifrontfunc() const{
    return ifront;
}

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
void Quene<Type>::add(Type const &obj,int pos){
    ++quene_size;
    for(int i=array_capacity;i>=pos;i--){
        array[i]=array[i-1];
    }
    iback++; 
}

template<typename Type>
Type Quene<Type>::deletesubs(int pos){
    for(int i=pos-1;i<=array_capacity;i++){
        array[i]=array[i+1];
    }
    iback--;
    quene_size--;
}

template<typename Type>
void Quene<Type>::push(Type const &obj){
    ++quene_size;
    ++iback;
    array[iback]=obj;
}

template<typename Type>
void Quene<Type>::show(){
    int front=ifront;
    while(front<iback+1){
        printf("%d",array[front]);
        front++;
    }
}

template<typename Type>
Type Quene<Type>::pop(){
    --quene_size;
    ++ifront;
    return array[ifront - 1];

}

template<typename Type>
Type Quene<Type>::remove(){
    --quene_size;
    --iback;
    return array[quene_size];
}
/*template<typename Type>
void Quene<Type>::Reaction(Quene<Type> QQuene ){
    int *p = new int[3*rules]();
    for(int i=0;i<3*rules;i++){
        cin>>p[i];
    }
    for(int i=0;i<3*rules;i)
}*/

void Insert(int *arr ,int num1,int num2,int pos,int len)
 {   

     for(int i=len;i>=pos;i--)
     {
         arr[i]=arr[i-1];  
     }
     arr[pos-1]=num2;
    for(int i=len+1;i>=pos;i--)
     {
         arr[i]=arr[i-1];  
     }
     arr[pos-1]=num1;
 }


int main(){
    int subs,rules,ops;
    Quene<int> aaa(500000);
    scanf("%d %d %d",&subs,&rules,&ops);
    int *p = new int[3*rules]();
    for(int i=0;i<3*rules;i++){
        cin>>p[i];
    }

    int **swp;      
	swp=new int*[rules];
	for(int i=0;i<rules;i++)
	swp[i]=new int[rules];
    for(int i=0;i<rules;i++){
        for(int j=0;j<rules;j++){
            swp[i][j]=-1;
        }
    }


    for(int i=0;i<3*rules;i+=3){        //give the value
        swp[p[i]][p[i+1]]=p[i+2];
        swp[p[i+1]][p[i]]=p[i+2];
    }

    /*for(int i=0;i<rules;i++){          //check the 2D matrix
        printf("\n");
        for(int j=0;j<rules;j++){
            printf("%d ''",swp[i][j]);
        }
    }*/


    int addelete[500000];             //store oprations
    for(int i=0;i<500000;i++){
        addelete[i]=-2;
    }
    for(int k=0;k<2*ops;k++){
        cin>>addelete[k];
    }


    bool reactbefore=false;
    int count=0;
    for(int k=0;k<2*ops;k+=2){  
        //printf("%d\n",k);     //reaction moves

        for(int j=0;j<addelete[k+1];j++){
            if(addelete[k]>=0){
                aaa.push(addelete[k]);
                
            }
            else{
                aaa.pop();
                count++;
            }
        }
        //cout<<aaa.ibackfunc()<<endl;
        //printf("\none!!!\n");
        
        int iter=k;
        if(addelete[k]==-1||addelete[k+1]==0)
        continue;
        if(addelete[k+2]==-2)
        break;
        if(addelete[k+2]==-1&&addelete[k+4]!=-2||addelete[k+3]==0&&addelete[k+4]!=-2){
            iter=k+2;
        }
        else if (addelete[k+2]==-1&&addelete[k+4]==-2||addelete[k+3]==0&&addelete[k+4]==-2)
        {
            continue;
        }
        
        if(swp[addelete[k]][addelete[iter+2]]!=-1){
            if(addelete[k+1]<addelete[iter+3]){
                for(int i=0; i<addelete[k+1];i++){
                    aaa.remove();
                    
                }
                addelete[iter+3]=addelete[iter+3]-addelete[k+1];
                //count+=addelete[k+3]-addelete[k+1];
                 for(int i=0; i<addelete[k+1];i++){
                    aaa.push(swp[addelete[k]][addelete[iter+2]]);
                    reactbefore=true;
                  
                }
            }
            else{
                //count+=addelete[k+1]-addelete[k+3];
                for(int i=0; i<addelete[iter+3];i++){
                    aaa.remove();
                    
                }
                for(int i=0; i<addelete[iter+3];i++){
                    aaa.push(swp[addelete[k]][addelete[iter+2]]);
                    reactbefore=true;
                }
                Insert(addelete,swp[addelete[k]][addelete[iter+2]],addelete[iter+3],iter+3,500000);
                count+=addelete[iter+3];
                addelete[iter+5]=0;
                ops++;
            }
            
        if(reactbefore==true){
        
            while(swp[addelete[k]][addelete[k-2]!=-1]||k>1){
                if(addelete[k]==-1||addelete[k-1]==0&&k>0)
                    continue;
                if(k-2<0||k-1<0){
                    break;
                }
                
                if (addelete[k-2]==-1&&k-4<=0||addelete[k-3]==0&&k-4<=0)
                {
                    continue;
                }
             
                if(addelete[k]>addelete[k-2]){
                   
                    for(int i=0;i<addelete[k+1];i++){
                        int n=0;
                        aaa.deletesubs(aaa.ibackfunc()-count+1-n-addelete[k+1]);
                        count++;
                        n++;
                    }
                    for(int i=0;i<addelete[k+1];i++){
                        aaa.add(swp[addelete[k]][addelete[k-2]],aaa.ibackfunc()-count+1-addelete[k+1]);
                    }
                    Insert(addelete,swp[addelete[k]][addelete[k-2]],addelete[k+1],k+1,500000);
                    count+=addelete[k+1];
                    addelete[k-1]=0;
                    ops++;
                }
                else{
                   
                    for(int i=0;i<addelete[k+1];i++){
                        int n=0;
                        aaa.deletesubs(aaa.ibackfunc()-count+1-n-addelete[k+1]);
                        aaa.remove();
                        count++;
                        n++;
                    }
                    for(int i=0;i<addelete[k+1];i++){
                        aaa.add(swp[addelete[k]][addelete[k-2]],aaa.ibackfunc()-count+1-addelete[k+1]);
                    }
                    Insert(addelete,swp[addelete[k]][addelete[k-2]],addelete[k+1],k+1,500000);
                    count+=addelete[k+1];
                    addelete[k-1]=0;
                    ops++;
                }
                
                k-=2;
            }
        }
            
            reactbefore=false;
        }
        /*for(int i=0;i<2*ops;i++)
            printf("%d " "",addelete[i]);
            printf("\n");*/
    }
    //printf("%d",count);
    //aaa.show(); 
    cout<<aaa.ibackfunc()-count+1<<endl;
    return 0;
}