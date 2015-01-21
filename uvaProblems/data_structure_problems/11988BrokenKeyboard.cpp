#include <iostream>
#include <string>
#include <list>
using namespace std;
int main(){
  string text;
  
  list<char> output, startString;
  bool start = false;
  while(cin>>text){
    output.erase(output.begin(),output.end());
    startString.erase(startString.begin(),startString.end());
    for(int i=0;i<text.size();i++){
      if(text[i] == '['){
	if(start){
	  output.splice(output.begin(),startString);
	  startString.erase(startString.begin(),startString.end());
	  start = false;
	}
	start = true;
      }
      else if(start && text[i]!='['){
	  if(text[i]==']'){
	    output.splice(output.begin(),startString);
	    startString.erase(startString.begin(),startString.end());
	    start = false;
	  }
	  else
	    startString.push_back(text[i]);
      }
      else if(text[i]!=']' && text[i]!='[' ){
	output.push_back(text[i]);
      }
    }
    if(!startString.empty())
      output.splice(output.begin(),startString);

    for(list<char>::iterator it = output.begin();it!=output.end();it++)
      cout<<*it;
    cout<<endl;
  }
}

