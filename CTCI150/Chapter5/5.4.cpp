/*
Auther:haozy
Problem:5.4
Language:C++
Description:explain codes ((n&(n-1))==0) meanings.
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
//n-1 will make the last '1' bit be '0' ,and after that ,it will be all '0'.
//so n-1 &n will be exactly the remmains of others before last '1'.
//so if it is zero. it is that it must only have one bit is '1'. so it will be 2^x
//so this means that ,whether n is a power of 2.

int main(){

}

