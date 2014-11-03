/*
Auther:haozy
Problem:9.6
Language:C++
Description:print all valid parenthese
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
void parenthese(char path[],int id,int l,int r)
{
    if(l==0&&r==0)
    {
        for(int i=0;i<id;i++)
            cout<<path[i];
        cout<<endl;
        return;

    }
    //
    if(l!=0)
    {
        path[id]='(';
        parenthese(path,id+1,l-1,r);
    }
    if(l<r)
    {
        path[id]=')';
        parenthese(path,id+1,l,r-1);
    }

}

int main(){
    char path[6];
    parenthese(path,0,3,3);
}

