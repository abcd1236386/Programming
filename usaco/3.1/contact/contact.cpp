/*
ID:haoziyi1
PROG:contact
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
ifstream fin("contact.in");
ofstream fout("contact.out");
struct nd{
    string str;
    int freq;
    nd(const string &s,int f=1)
    {
        str=s;
        freq=f;
    }
    bool operator<(const nd &n) const{
        if( freq!=n.freq)
            return freq>n.freq;
        else if(str.size()!=n.str.size())
            return str.size()<n.str.size();
        else
            return str<n.str;
    }
};
int main(){
    map<string,int> mp;
    int a,b,n;
    fin>>a>>b>>n;
    string str,s;
    fin.get();
    while(fin>>s){
        str+=s;
    }
    for(int i=0;i<=str.size()-a;i++)
    {
        s=str.substr(i,a);
        mp[s]++;
        for(int j=a;j<b&&i+j<str.size();j++)
        {
            s.push_back(str[j+i]);
            mp[s]++;
        }
    }
    vector<nd> vn;
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();++it){
        vn.push_back(nd(it->first,it->second));
    }
    // soga.
    sort(vn.begin(),vn.end());
    int t=0;
    int i=0;
    while(t<n&&i<vn.size()){
       fout<<vn[i].freq<<'\n';
       int c=0;
       while(i<vn.size()-1&&vn[i].freq==vn[i+1].freq){
           fout<<vn[i].str;
           i++;
           c++;
           if(c%6==0)
               fout<<'\n';
           else
               fout<<' ';
       }
       fout<<vn[i].str<<endl;
       i++;
       t++;
    }
    
            
}

