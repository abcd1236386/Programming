/*
Auther:haozy
Problem:5.8
Language:C++
Description:implement drawHorizonLine
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
typedef unsigned char byte;
void drawhorizontalLine(byte screen[] ,int length,int width,int x1,int x2,int y)
{
    int bwth=width/8;
    int sid=y*bwth; //start id
    int eid=sid+bwth-1;// end id
    int dsid=x1/8;
    int deid=x2/8;
    for(int i=dsid+1;i<deid;i++)
        screen[i]=~0;
    //first and last byte special handle
    int msk=0~;
    screen[dsid]|=~(msk<<(7-x1%8);
    screen[deid]|=msk<<x2%8;
}

int main(){

}

