/*
ID:haoziyi1
PROG:fact4
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
ifstream fin("fact4.in");
ofstream fout("fact4.out");
int main(){
    int n;
    fin>>n;
    unsigned int r=1;
    for(int i=1;i<=n;i++)
    {
        r*=i;
        while(r%10==0)
            r/=10;
        r%=10000;

    }
    cout<<r%10<<endl;
    fout<<r%10<<endl;
}

