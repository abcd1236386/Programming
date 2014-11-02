/*
Auther:haozy
Problem:4.1
Language:C++
Description:check a binary tree is balanced which two subtree of any node never differ by more than one
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
bool balanced(bnode *root,int &mx,int &mi)
{
    if(root==NULL)
    {
        mx=mi=0;
        return true;
    }
    bool rt=balanced(root->left,mx,mi);
    if(!rt)
        return false;
    int rmx,rmi;
    rt=balanced(root->right,rmx,rmi);
    if(!rt)
        return false;
    if(mx<rmx)
        mx=rmx;
    if(mi>rmi)
        mi=rmi;
    mx++;
    mi++;
    return mx-mi<=1;
}

int main(){

}

