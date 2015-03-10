/*
ID:haoziyi1
PROG:humble
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
using namespace std;
ifstream fin("humble.in");
ofstream fout("humble.out");
int st[100];
int num[100000+1];
int id[100];
int len=0;
int main(){
    int k,n;
    fin>>k>>n;
    for(int i=0;i<k;i++){
        fin>>st[i];
        id[i]=0;
    }
    num[0]=1;
    len++;
    while(len<=n){
        //find the min
        int m=-1;
        for(int i=0;i<k;i++)
            if(m==-1||m>st[i]*num[id[i]])
                m=st[i]*num[id[i]];
        //
        num[len]=m;
        //skip the
        for(int i=0;i<k;i++)
            if(m==st[i]*num[id[i]])
                id[i]++;
        len++;
    }
    fout<<num[n]<<endl;
}

