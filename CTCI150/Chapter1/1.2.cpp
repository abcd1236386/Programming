/*
Auther:haozy
Problem:1.2
Language:C++
Description:implement function reverse(char *str)
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
void reverse(char *str)
{
    if(str==NULL)
        return;
    int len=strlen(str);
    int i=0,j=len-1;
    while(i<j)
        swap(str[i],str[j]);

}
int main(){
    char buf[100]="hello world";
    char *t=NULL;
    cout<<reverse(buf)<<endl;
}

