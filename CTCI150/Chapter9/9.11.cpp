/*
Auther:haozy
Problem:9.11
Language:C++
Description:give a express 0,1,&,|,^,find a parenthesizing  way to get value result.
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
//result can be true or false.
int ways(char *exp,int n,char result)
{
    if(n==0)
        return exp[0]==result;
    int w=0;
    char op=exp[n-1];
    switch(op){
        case '&':
        if(result=='0')
        {
            if(exp[n]=='0')
                w+=ways(exp,n-2,'0')+ways(exp,n-2,'1');
            else
                w+=ways(exp,n-2,'0');
        }
        else if(exp[n]=='1')
        {
            w+=ways(exp,n-2,'1');
        }
        break;
        case '|':
        break;
        case '^'
        break;
}

int main(){

}

