/*
Auther:haozy
Problem:1.8
Language:C++
Description:call once isSubstring to check if s2 is rotation of s1
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
using namespace std;
bool callOnce(string &s1,string &s2)
{
    return isSubstring(s1+s1,s2);
}
int main(){

}

