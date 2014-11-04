/*
Auther:haozy
Problem:9.7
Language:C++
Description:implement paint fill
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
// it like bfs, or dfs.nothing more . just pick one add it to queue, and fill it.
void dfs(vector<vector<int> > &screen ,int x,int y,int orig,int tocolor)
{
    if(orig==tocolor||x<0||y<0||x>screen.size()-1||y>=screen[0].size()||screen[x][y]!=orig)
        return;
    screen[x][y]=tocolor;
    dfs(screen,x,y+1,orig,tocolor);
    dfs(screen,x+1,y,orig,tocolor);
    dfs(screen,x-1,y,orig,tocolor);
    dfs(screen,x,y-1,orig,tocolor);
}

int main(){

}

