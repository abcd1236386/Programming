#!/bin/bash
#this shell will make a template.
#usage cmd filename comment.
if [ "$1" = "" ] 
then
    echo "missing file name!"
    exit;
fi
str='/*
Auther:haozy
Problem:'"$1"'
Language:C++
Description:'"$2"'
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
using namespace std;'"


int main(){

}
"
echo "$str" > "./$1.cpp"
