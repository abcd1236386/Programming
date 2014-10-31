/*
Auther:haozy
Problem:1.4
Language:C++
Description:replace space with %20
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
void replace(char str[]) //str have sufficient buffer to contain string.
{
    //first check where to stop.
    int space=0;
    int len=0;
    for(int i=0;str[i]!=0;i++)
    {
        len++;
        if(str[i]==' ')
            space++;
    }
    //new len will increase 2*space
    int newlen=len+2*space;
    str[newlen--]='\0';
    for(int i=len-1;i>=0;i--)
    {
        if(str[i]==' ')
        {
            str[newlen--]='0';
            str[newlen--]='2';
            str[newlen--]='%';
        }
        else
            str[newlen--]=str[i];
    }
}

int main(){
    char buf[1000]="Mr John Smith";
    replace(buf);
    cout<<buf<<endl;
}

