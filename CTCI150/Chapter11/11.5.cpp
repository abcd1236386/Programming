/*
Auther:haozy
Problem:11.5
Language:C++
Description:sorted array of strings interspresed with empty strings, write a method to find a given string.
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
int search(vector<string> &vs,string & str)
{
    int l=0,r=vs.size();
    while(l<=r){
        while(vs[l]=="")
            l++;
        while(vs[r]=="")
            r--;
        if(l>r)
            break;
        int m=(l+r)/2;
        while(m<r&&vs[m]=="")
            m++;
        if(vs[m]==str)
            return m;
        else if(str>vs[m])
            l=m+1;
        else
            r=m-1;
    }
    return -1;   

}

int main(){
   
}

