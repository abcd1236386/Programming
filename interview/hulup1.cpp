#include<iostream>
using namespace std;
//for f(i,j) means 'a's and 'b's.
//f(a,b)=f(a-1,b)+f(a,b-1)
int f[100][100];
int main(){
    //f(0,0)=1;
    //f(0,j)=0;
    //f(i,0)=1;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(j==0)
                f[i][j]=1;
            else if(i==0)
                f[i][j]=0;
            else
            {
                if(i>j)
                    f[i][j]=f[i-1][j]+f[i][j-1];
                else if(i==j)
                    f[i][j]=f[i][j-1];
                else
                    f[i][j]=0;
            }
        }
    }
    cout<<f[m][n]<<endl;
}
