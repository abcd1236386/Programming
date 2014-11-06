/*
Auther:haozy
Problem:11.2
Language:C++
Description:write a method to sort an array of strings anagrams are next to each other
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<unordered_map>
#include"../struct.h"
using namespace std;
//we can use a hash table to 
string sortanagram(string s)
{
    sort(s.begin(),s.end());
    return s;
}
void Anagrams(vector<string> &s)
{
    unordered_map<string,vector<string> > hash;
    unordered_map<string,vector<string> >::iterator iter;
    for(int i=0;i<s.size();i++)
    {
        hash[sortanagram(s[i])].push_back(s[i]);
    }
    int i=0;
    for(iter=hash.begin();iter!=hash.end();++iter)
    {
        vector<string> &vs=iter->second;
        for(int j=0;j<vs.size();j++)
            s[i++]=vs[j];
    }

}
int main(){
    vector<string> vs;
    vs.push_back("abc");
    vs.push_back("cab");
    vs.push_back("acd");
    vs.push_back("cba");
    vs.push_back("dca");
    Anagrams(vs);
    for(int i=0;i<vs.size();i++)
        cout<<vs[i]<<endl;

}

