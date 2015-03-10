/*
ID:haoziyi1
PROG:fracdec
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
ifstream fin("fracdec.in");
ofstream fout("fracdec.out");

int main(){
    int N,D;
    fin>>N>>D;
    int itg=N/D;
    N%=D;
    int vst[D];
    memset(vst,0,sizeof(vst));
    string del;
    while(N!=0&&!vst[N])
    {
        vst[N]=del.size()+1;
        N*=10;
        del.push_back('0'+N/D);
        N%=D;
    }
    fout<<itg<<'.';
    int clen=0;
    while(itg){
        clen++;
        itg/=10;
    }
    if(clen==0)
        clen=1;
    clen++;
    if(N==0)
    {
        if(del.size()==0)
            fout<<"0";
        else{
            for(int i=0;i<del.size();i++)
            {

            fout<<del[i];
            clen++;
            if(clen%76==0)
                fout<<'\n';
            }
        }
    }
    else
    {
        for(int i=0;i<vst[N]-1;i++)
        {
                fout<<del[i];
                clen++;
                if(clen%76==0)
                    fout<<'\n';
        }
        fout<<'(';
                clen++;
                if(clen%76==0)
                    fout<<'\n';
        for(int i=vst[N]-1;i<del.size();i++)
        {
                fout<<del[i];
                clen++;
                if(clen%76==0)
                    fout<<'\n';
        }
        fout<<')';
                clen++;
                if(clen%76==0)
                    fout<<'\n';
    }
    if(clen%76!=0)
        fout<<endl;
}

