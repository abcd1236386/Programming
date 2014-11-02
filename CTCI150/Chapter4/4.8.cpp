/*
Auther:haozy
Problem:4.8
Language:C++
Description:is a subtree of T1
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
bool matchTree(bnode *t1,bnode *t2)
{
    if(t1==NULL||t2==NULL)
        return t1==t2;
    if(t1->val!=t2->val)
        return false;
    return matchTree(t1->left,t2->left)&&matchTree(t1->right,t2->right);
}
bool isSubTree(bnode *t1,bnode *t2)
{
    if(t2==NULL)
        return true;
    if(t1==NULL)
        return false;
    return matchTree(t1,t2)||
        isSubTree(t1->left,t2)||
        isSubTree(t1->right,t2);
}


int main(){
    //some test case.
}

