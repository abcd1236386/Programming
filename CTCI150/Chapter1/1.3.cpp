/*
Auther:haozy
Problem:1.3
Language:C++
Description:check permutation
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
bool checkPerm(string &s1,string &s2)
{
    if(s1.size()!=s2.size())
        return false;
    //use a buffer to check.
    int buf[128]={0};
    for(int i=0;i<s1.size();i++){
        buf[s1[i]]++;
        buf[s2[i]]--;
    }
    for(int i=0;i<128;i++)
        if(buf[i]!=0)
            return false;
    return true;
}
int main(){

}

