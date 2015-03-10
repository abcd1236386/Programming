/*
Auther:haozy
Problem:4.9
Language:C++
Description:print all paths sum to value. path is top-down
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
void findsum(bnode *rt,int path[],int level,int sum)
{
    if(rt==NULL)
        return;
    path[level]=rt->val;
    int t=0;
    for(int i=level;i>=0;i--)
    {
        t+=path[i];
        if(t==sum)
        {//find one
           //print it out. print shouble be l
        }
    }
    findsum(rt->left,path,level+1,sum);
    findsum(rt->right,path,level+1,sum);
    //T(n)=2T(n/2)+log(N);
    // time complexity is O(nlogn).

}

int main(){

}

