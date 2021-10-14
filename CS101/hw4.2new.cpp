#include <stdlib.h>
#include <iostream>
using namespace std;

int max(int x,int y){
    if(x>=y){
        return x;
    }
    else{
        return y;
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
    int *numline1=new int[300];
    int *numline2=new int[300];
    for(int i=1;i<=num1;i++){
        if(line1[i-1]=='A'){
            numline1[i]=0;
        }
        else if(line1[i-1]=='C'){
            numline1[i]=1;
        }
        else if(line1[i-1]=='G'){
            numline1[i]=2;
        }
        else if(line1[i-1]=='T'){
            numline1[i]=3;
        }
    }

    for(int i=1;i<=num2;i++){
        if(line2[i-1]=='A'){
            numline2[i]=0;
        }
        else if(line2[i-1]=='C'){
            numline2[i]=1;
        }
        else if(line2[i-1]=='G'){
            numline2[i]=2;
        }
        else if(line2[i-1]=='T'){
            numline2[i]=3;
        }
    }

    int a[5][5]={{5,-1,-2,-1,-3},
                {-1,5,-3,-2,-4},
                {-2,-3,5,-2,-2},
                {-1,-2,-2,5,-1},
                {-3,-4,-2,-1,0}};
    int **dp=new int*[300];
	for(int i=0;i<300;i++){
		dp[i]=new int[300];
    }
    for(int i=1;i<300;i++){
        for(int k=1;k<300;k++){
            dp[i][k]=-999;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=num1;i++){
        dp[i][0]=dp[i-1][0]+a[numline1[i]][4];
    }
    for(int i=1;i<=num2;i++){
        dp[0][i]=dp[0][i-1]+a[numline2[i]][4];
    }
    //dp[0][0]=0;
    for(int i=1;i<=num1;i++){
        for(int j=1;j<=num2;j++){
            dp[i][j]=max(dp[i][j],max(dp[i][j],max(dp[i-1][j-1]+a[numline1[i]][numline2[j]],max(dp[i-1][j]+a[numline1[i]][4],dp[i][j-1]+a[4][numline2[j]]))));
        }
    }
    cout<<dp[num1][num2];
}