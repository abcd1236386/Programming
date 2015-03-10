/*
Auther:haozy
Problem:11.1
Language:C++
Description:merge sorted arrays A and B. To A.
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
void merge(int A[],int lena,int B[],int blen)
{
    int i=lena-1,j=lenb-1,k=lena+lenb-1;
    while(i>=0&&j>=0)
    {
        if(A[i]>B[i])
            A[i--]=A[k--];
        else
            B[j--]=A[k--];
    }
    while(j>=0)
        B[j--]=A[k--];
}

int main(){

}

