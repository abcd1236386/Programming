/*
Auther:haozy
Problem:9.5
Language:C++
Description:all permutations of a string
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
void permutation(string &str,int i)
{
    if(i==str.size())
    {
        cout<<str<<endl;
        return;
    }
    for(int j=i;j<str.size();j++)
    {
        swap(str[i],str[j]);
        permutation(str,i+1);
        swap(str[i],str[j]);
    }

}

int main(){
    string str="1234";
    permutation(str,0);

}

