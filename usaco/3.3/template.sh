#!/bin/bash
#this shell will make a template.
if [ "$1" = "" ] 
then
    echo "missing file name!"
    exit;
fi
if [ ! -d "./$1" ]; then
    echo "no directory, create it."
    mkdir "$1"
fi
str='/*
ID:haoziyi1
PROG:'$1'
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<cstring>
using namespace std;'"
ifstream fin(\"$1.in\");
ofstream fout(\"$1.out\");
int main(){

}
"
echo "$str" > "./$1/$1.cpp"
