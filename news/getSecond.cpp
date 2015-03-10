#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	int line=0;
	while(getline(cin,str)){
		line++;
		if(line%4==2){
			cout<<str<<'\n';
		}
	}
}
