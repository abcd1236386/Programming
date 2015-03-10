/*
Auther:haozy
Problem:8.3
Language:C++
Description:implement a junkebox
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
class cdplayer;
class CD;
class Song;
class Song{
    public:
    string auther;
    string title;
    string content;

};
class CD{
    string name;
    vector<Song> songs;
    public:
    Song &getSong(int x)
    {
        return songs[x];
    }
    int size(){
        return songs.size();
    }
    void addSong(Song &s){
        songs.push_back(s);
    }
    string &getName(){
        return name;
    }
};
class cdplayer{
    CD cd;
    public:
    void play(){
        cout<<"playing cd"<<cd.getName()<<endl;
        for(int i=0;i<cd.size();i++)
           {
               cout<<"playing song "<<cd.getSong(i).title<<endl;
               cout<<cd.getSong(i).content<<endl;
           }
        cout<<"CD over\n";
    }
    void setCD(CD &c)
    {
        cd=c;
    }

};
class jukebox{
    cdplayer player;
    vector<CD> cds;
    public:
    void play(){
       for(int i=0;i<cds.size();i++)
       {
           player.setCD(cds[i]);
           player.play();
       }
    }
    void putCD(CD&c)
    {
        cds.push_back(c);
    }
};
int main(){
    Song s;
    s.title="song 1";
    s.content="beautiful day";
    CD cd;
    cd.addSong(s);
    s.title="song 2";
    s.content="have a nice day";
    cd.addSong(s);
    jukebox jb;
    jb.putCD(cd);
    jb.play();
}

