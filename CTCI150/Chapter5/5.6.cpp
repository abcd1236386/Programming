/*
Auther:haozy
Problem:5.6
Language:C++
Description:swap even and odd bit
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
#define oddmsk (0xaaaaaaaa)
#define evenmsk  (0x55555555)
int swp(int x)
{
    int ev=x&evenmsk;
    int od=x&oddmsk;
    return (ev<<1)|(od>>1);
}
int main(){
    cout<<swp(21)<<endl;
}

