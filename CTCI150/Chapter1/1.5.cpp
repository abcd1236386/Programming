/*
Auther:haozy
Problem:1.5
Language:C++
Description:compression repeated characters
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
string compress(const string &str)
{
    char c;
    int cnt=0;
    string ret;
    for(int i=0;i<str.size();i++)
    {
        if(i==0||str[i]!=str[i-1])
        {
            if(cnt!=0)
            {
               ret.push_back(c);
               ret.push_back('0'+cnt); 
            }
            c=str[i];
            cnt=1;
        }
        else 
            cnt++;
    }
    //compress the last one
    if(cnt!=0)
    {
        ret.push_back(c);
        ret.push_back('0'+cnt);
    }
    return ret.size()<str.size()?ret:str;
}
int main(){
    string str="aabcccccaaa";
    cout<<compress(str)<<endl;
    str="abcdefg";
    cout<<compress(str)<<endl;
}

