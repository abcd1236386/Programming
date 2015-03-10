/*
Auther:haozy
Problem:5.5
Language:C++
Description:number of bit to convert
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

int ones(int x)
{
    int o=0;
    while(x){
        x&=x-1;
        o++;
    }
    return o;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<ones(a^b)<<endl;
}

