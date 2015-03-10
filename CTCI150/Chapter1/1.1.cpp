/*
Auther:haozy
Problem:1.1
Language:C++
Description:determine if a string has all unique char
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
bool unique(string &str)
{
    bool ch[128]={false};
    for(int i=0;i<str.size();i++)
    {
        if(ch[str[i]])
            return false;
        ch[str[i]]=1;
    }
    return true;
}
int main(){

}

