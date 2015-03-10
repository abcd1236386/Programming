#include<iostream>
#include<algorithm>
using namespace std;
// m floors and n eggs.
//f[m.n] means min number of m floors of n eggs.
//so for k th floor.throw a egg. then 
//if the egg broken ,then we have k-1 floors now f[k-1,m-1].
//if the egg not broken, then have n-k to test upstairs. f[n-k][m];
int f[101][101]={0};
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        f[i][0]=0;
        for(int j=1;j<=n;j++)
        {
            if(j==1){
                f[i][j]=i;
                continue;
            }
            f[i][j]=m;
            for(int k=1;k<=i;k++)
            {
                int mx=max(f[k-1][j-1],f[i-k][j]);
                if(mx<f[i][j])
                    f[i][j]=mx;
            }
            f[i][j]++;

        }
    }
    cout<<f[m][n]<<endl;
}
