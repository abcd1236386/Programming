/*
Auther:haozy
Problem:5.2
Language:C++
Description:convert real number from base10 to base 2 
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
void real10to2(double x)
{
    string s="0.";
    int len=0;
    do{
        x*=2;
        if(x>1-1e-10){
            s.push_back('1');
            len++;
            x-=1;
        }
        else{
            s.push_back('0');
            len++;
        }
    }
    while(x>1e-10&&len<32);
    if(x>1e-10)
        cout<<"ERROR\n";
    else
    {
        for(int i=0;i<s.size();i++)
            cout<<s[i];
        cout<<endl;
    }

}

int main(){
   int n=10;
   for(int i=0;i<n;i++)
   {
       double x=i/10.0;

       cout<<x<<' ';
       real10to2(x);
   }
}

