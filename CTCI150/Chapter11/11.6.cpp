/*
Auther:haozy
Problem:11.6
Language:C++
Description:M*N matrix in each row and each column is sorted in ascending order to find a element
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
//we can start at the left corner of this matrix,
//when it biger than the x.so we should go upper ,or when it smaller than x ,we should go righter.
bool findinMatrix(vector<vector<int> > & mat, int x)
{
    int i=mat.size()-1;
    int j=0;
    while(i>=0&&j<mat[0].size())
    {
        if(mat[i][j]==x)
            return true;
        else if(mat[i][j]<x)
            j++;
        else
            i--;
    }
    return false;
}

int main(){

}

