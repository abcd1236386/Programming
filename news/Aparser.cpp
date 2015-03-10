#include<iostream>
#include<string>
#include<list>
#include<map>
#include<utility>
using namespace std;
class ATag{
	enum state{
		start,
		tag_lt,
		tag_A,
		tag_A_attr_key,
		tag_A_attr_val,
		tag_elem,
		tag_end_lt,
		tag_end,
	};
	public:
		list<pair<string,string> >Attr;//
		string value;
		string toString(){
			string str="<a";
			for(list<pair<string,string> >::iterator it=Attr.begin();it!=Attr.end();++it){
				str+=" ";
				str+=it->first;
				str+="=";
				str+=it->second;
			}
			str+=">";
			str+=value;
			str+="</a>";
			return str;
		}
		bool blank(char c){
			return c==' '||c=='\t'||c=='\n';
		}
		void parse(string line){
			int st=start;
			string tmp;
			pair<string,string> ptmp;
			for(int i=0;i<line.size()&&st!=tag_end;){
				switch(st){
					case start:
						if(!blank(line[i])){
							if(line[i]=='<')
								st=tag_lt;
						}
						i++;
						break;
					case tag_lt:
						while(blank(line[i]))
							i++;
						while(!blank(line[i]))
						{
							tmp.push_back(line[i]);
							i++;
						}
						tmp.clear();// tmp is "a"
						i++;
						st=tag_A;
						break;
					case tag_A:
						while(blank(line[i]))
							i++;
						//attr=value
						while(line[i]!='='&&line[i]!='>')
						{
							tmp.push_back(line[i]);
							i++;
						}
						if(line[i]=='>')
						{
							i++;
							st=tag_elem;
							break;
						}
						ptmp.first=tmp;
						tmp.clear();
						i++;//skip '='
						st=tag_A_attr_key;
						break;
					case tag_A_attr_key:
						while(blank(line[i]))
							i++;
						while(!blank(line[i])&&line[i]!='>')
						{
							tmp.push_back(line[i]);i++;
						}
						ptmp.second=tmp;
						Attr.push_back(ptmp);//add to Attr
						tmp.clear();
						if(line[i]=='>')
						{
							st=tag_elem;
						}
						else
							st=tag_A;
						i++;//skip the '>' 
						break;
					case tag_elem:
						while(line[i]!='<'){
							value.push_back(line[i]);
							i++;
						}
						st=tag_end;
						break;
				}//switch
			}//for
		}//parse
};
int main(){
	string line;
	while(getline(cin,line)){
		ATag a;
		a.parse(line);
		cout<<a.toString()<<'\n';
	}
}
