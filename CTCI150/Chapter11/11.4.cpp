/*
Auther:haozy
Problem:11.4
Language:C++
Description:sort a 20GB file of memory limits.
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
// we can mimic this .for 20GB file .we use 20*1024 numbers.
// the memery we limits is 512M .so we have 512 at most numbers.
// 

int main(){
    vector<int> file(20*1024);
    for(int i=0;i<file.size();i++){
        file[i]=rand();
    }
    int memory[512];
    //all we do will in the memory.
    vector<vector<int> > disk;
    int j=0;
    for(int i=0;i<file.size();i++)
    {
            memory[j++]=file[i];
        if(j==512)
        {
            sort(memory,memory+j);
            disk.push_back(vector<int>(memory,memory+j));
            j=0;
        }
    }
    if(j!=0)
    {
        sort(memory,memory+j);
        disk.push_back(vector<int>(memory,memory+j));
        j=0;
    }
    //we have soted in all the files.
    //file i'th id is in memory[i].
    vector<int> sortedfile;
    for(int i=0;i<disk.size();i++)
        memory[i]=0;
    int *remMem=memory+disk.size();
    int k=disk.size();
    while(1){
        bool end=true;
        int mid=-1;
        for(int i=0;i<disk.size();i++)
        {
            if(memory[i]>=disk[i].size())
                continue;
            else if(mid==-1){
                mid=i;
                end=false;
            }
            else if(disk[i][memory[i]]<disk[mid][memory[mid]]){
                mid=i;
            }
        }
        //find min
        if(end)
          break;
        memory[k++]=disk[mid][memory[mid]++];
        if(k==512)//memory full
        {
            for(int i=disk.size();i<512;i++)
                sortedfile.push_back(memory[i]);
            k=disk.size();
        }
    }
    for(int i=disk.size();i<k;i++)
       sortedfile.push_back(memory[i]);
    //all the file have sorted.
    cout<<sortedfile.size()<<endl;
    bool sorted=true;
    for(int i=1;i<sortedfile.size();i++)
        if(sortedfile[i]<sortedfile[i-1])
        {
            sorted=false;
            break;
        }
    cout<<sorted<<endl;
}

