/*
Auther:haozy
Problem:5.1
Language:C++
Description:insert M to N between i, j
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include"../struct.h"
using namespace std;
void insertM(int &N,int M,int i,int j)
{
    int mask=~0;
    mask=(~(mask<<j+1))&(mask<<i);
    mask=~mask;
    N&=mask; //clear the bits.
    N|=(M<<i);
}
int Base10(const char *str)
{
    int r=0;
    while(*str){
        r*=2;
        r+=*str-'0';
        str++;
    }
    return r;
}
void ouput(int x)
{
    string s;
    while(x){
        s.push_back((x&1)+'0');
        x>>=1;
    }
    for(int i=s.size();i>=0;i--)
        cout<<s[i];
    cout<<endl;
}
int main(){
    int n=Base10("10000000000");
    int m=Base10("10011");
    insertM(n,m,2,6);
    ouput(n);
}

