#include <stdlib.h>
#include <iostream>
using namespace std;

void find_optimal(char *arr1,char *arr2,int len1,int len2){
    int maxnum=len1;
    int smallnum=len2;
    if(len2>len1){
        maxnum=len2;
        smallnum=len1;
    }
    int *opt=new int[maxnum-smallnum+1];
    for(int i=0;i<maxnum-smallnum+1;i++){
        opt[i]=0;
    }
    if(len1>len2){
        for(int k=0;k<maxnum-smallnum+1;k++){
            int count=0;
            for(int i=0;i<smallnum;i++){
                    int j=0;
                    if(arr1[i]==arr2[j]){
                        opt[k]+=5;
                    }
                    else if(arr1[i]=='A'&&arr2[j+count]=='T'||arr1[i]=='T'&&arr2[j+count]=='A'){
                        opt[k]-=1;
                    }
                    else if(arr1[i]=='A'&&arr2[j+count]=='C'||arr1[i]=='C'&&arr2[j+count]=='A'){
                        opt[k]-=1;
                    }
                    else if(arr1[i]=='A'&&arr2[j+count]=='G'||arr1[i]=='G'&&arr2[j+count]=='A'){
                        opt[k]-=2;
                    }
                    else if(arr1[i]=='A'&&arr2[j+count]=='X'||arr1[i]=='X'&&arr2[j+count]=='A'){
                        opt[k]-=3;
                    }
                    else if(arr1[i]=='C'&&arr2[j+count]=='G'||arr1[i]=='G'&&arr2[j+count]=='C'){
                        opt[k]-=3;
                    }
                    else if(arr1[i]=='C'&&arr2[j+count]=='T'||arr1[i]=='T'&&arr2[j+count]=='C'){
                        opt[k]-=2;
                    }
                    else if(arr1[i]=='C'&&arr2[j+count]=='X'||arr1[i]=='X'&&arr2[j+count]=='C'){
                        opt[k]-=4;
                    }
                    else if(arr1[i]=='G'&&arr2[j+count]=='T'||arr1[i]=='T'&&arr2[j+count]=='G'){
                        opt[k]-=2;
                    }
                    else if(arr1[i]=='G'&&arr2[j+count]=='X'||arr1[i]=='X'&&arr2[j+count]=='G'){
                        opt[k]-=2;
                    }
                    else if(arr1[i]=='T'&&arr2[j+count]=='X'||arr1[i]=='X'&&arr2[j+count]=='T'){
                        opt[k]-=1;
                    }
                    count++;
                }
            }
    }
    else{
        for(int k=0;k<maxnum-smallnum+1;k++){
            int count=0;
            for(int i=0;i<smallnum;i++){
                    int j=0;
                    if(arr1[i]==arr2[j]){
                        opt[k]+=5;
                    }
                    else if(arr2[i]=='A'&&arr1[j+count]=='T'||arr2[i]=='T'&&arr1[j+count]=='A'){
                        opt[k]-=1;
                    }
                    else if(arr2[i]=='A'&&arr1[j+count]=='C'||arr2[i]=='C'&&arr1[j+count]=='A'){
                        opt[k]-=1;
                    }
                    else if(arr2[i]=='A'&&arr1[j+count]=='G'||arr2[i]=='G'&&arr1[j+count]=='A'){
                        opt[k]-=2;
                    }
                    else if(arr2[i]=='A'&&arr1[j+count]=='X'||arr2[i]=='X'&&arr1[j+count]=='A'){
                        opt[k]-=3;
                    }
                    else if(arr2[i]=='C'&&arr1[j+count]=='G'||arr2[i]=='G'&&arr1[j+count]=='C'){
                        opt[k]-=3;
                    }
                    else if(arr2[i]=='C'&&arr1[j+count]=='T'||arr2[i]=='T'&&arr1[j+count]=='C'){
                        opt[k]-=2;
                    }
                    else if(arr2[i]=='C'&&arr1[j+count]=='X'||arr2[i]=='X'&&arr1[j+count]=='C'){
                        opt[k]-=4;
                    }
                    else if(arr2[i]=='G'&&arr1[j+count]=='T'||arr2[i]=='T'&&arr1[j+count]=='G'){
                        opt[k]-=2;
                    }
                    else if(arr2[i]=='G'&&arr1[j+count]=='X'||arr2[i]=='X'&&arr1[j+count]=='G'){
                        opt[k]-=2;
                    }
                    else if(arr2[i]=='T'&&arr1[j+count]=='X'||arr2[i]=='X'&&arr1[j+count]=='T'){
                        opt[k]-=1;
                    }
                    count++;
                }
            }
    }
        for(int k=0;k<maxnum-smallnum+1;k++){
            cout<<opt[k]<<"\n";
        }
}
int main(){
    
    int num1,num2;
    cin>>num1;
    char *line1=new char[num1];
    for(int i=0;i<num1;i++){
        cin>>line1[i];
    }
    cin>>num2;
    char *line2=new char[num2];
    for(int i=0;i<num2;i++){
        cin>>line2[i];
    }
    int maxnum=num1;
    if(num2>num1){
        maxnum=num2;
    }
    char *newline1=new char[maxnum];
    char *newline2=new char[maxnum];
    for(int i=0;i<maxnum;i++){
        newline1[i]='X';
    }
    for(int i=0;i<maxnum;i++){
        newline2[i]='X';
    }
    for(int i=0;i<num1;i++){
        newline1[i]=line1[i];
    }
    for(int i=0;i<num2;i++){
        newline2[i]=line2[i];
    }

    for(int i=0;i<maxnum;i++){
        cout<<newline1[i];
    }
    for(int i=0;i<maxnum;i++){
        cout<<newline2[i];
    }
    find_optimal(newline1,newline2,num1,num2);

}