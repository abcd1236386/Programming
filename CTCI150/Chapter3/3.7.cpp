/*
Auther:haozy
Problem:3.7
Language:C++
Description:mimic a dog cat system. 
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
struct dogcat{
    int label;
    queue<int> dog;
    queue<int> cat;
    dogcat(){
        label=0;
    }
    void enqueue(int tp)
    {
        if(tp==0)
            dog.push(label++);
        else
            cat.push(label++);

    }
    int dequeueAny(){
        if(dog.empty()||cat.front()<dog.front())
        {
            int t=cat.front();
            cat.pop();
            return t;
        }
        if(cat.empty()||dog.front()<cat.front())
        {
            int t=dog.front();
            dog.pop();
            return t;
        }
    }
    int dequeueDog(){
        int t=dog.front();
        dog.pop();
        return t;
    }
    int dequeueCat(){
       int t=cat.front();
       cat.pop();
       return t;
    }
};
    
int main(){

}

