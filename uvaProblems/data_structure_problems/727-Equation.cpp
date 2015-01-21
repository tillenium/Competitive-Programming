#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

int pre(char c){
  if(c=='+' || c=='-')
    return 1;
  if(c=='*' || c=='/')
    return 2;
  else 
    return 3;
}
int main(){
  stack<char> s;

  int t;cin>>t;
  char c;
  char str[2];
  string output = "";
  cin.getline(str,2);
  cin.getline(str,2);
  while(t--){
  
    output = "";
    while(true){
      cin.getline(str,2);
    c = str[0];
    
    if((int)c==0){
      while(!s.empty()){
	output += s.top();
	s.pop();
      }
      break;
    }
    if(c>= '0' && c<='9'){
      output += c;
    }
    else if(c==')'){
      while(!s.empty() && s.top()!='('){
        output += s.top();
        s.pop();
      }
      if(!s.empty())
       s.pop();
    }
    else{
      while(!s.empty()  && pre(c)<=pre(s.top()) &&s.top()!='('){
	output += s.top();
	s.pop();
      } 
      s.push(c);
    }
    }
    
    cout<<output<<endl;
    if(t!=0)
      cout<<endl;
  }
}
