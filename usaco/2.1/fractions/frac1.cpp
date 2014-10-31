/*
ID:haoziyi1
PROG:frac1
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
ifstream fin("frac1.in");
ofstream fout("frac1.out");
struct frc{
    int x,y;
    frc(int xx,int yy){
        x=xx;
        y=yy;
    }
    bool operator<(const frc& f)const{
        if( x*f.y==y*f.x)
            return y<f.y;
        return x*f.y<y*f.x;
    }
    bool operator == (const frc &f ) const{
        return x*f.y==y*f.x;
    }
    bool operator !=(const frc &f ) const{
        return !(*this==f);
    }
};
int main(){
    int n;
    fin>>n;
   vector<frc> vf;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            vf.push_back(frc(j,i));
        }
    }
    sort(vf.begin(),vf.end());
    for(int i=0;i<vf.size();i++){
        if(i==0||vf[i]!=vf[i-1])
            fout<<vf[i].x<<'/'<<vf[i].y<<'\n';
    }

}

