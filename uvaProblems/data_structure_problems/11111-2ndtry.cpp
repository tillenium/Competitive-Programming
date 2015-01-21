#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

struct Toy{
  int val;
  int rest;
};

bool toys(vector<int> v){ 

  stack<Toy> s;
  Toy temp;
  temp.val = v[0];
  temp.rest = abs(v[0]);

  s.push(temp);
  for(int i=1;i<v.size();i++){
    if(v[i]<0){
      if(s.empty()){
        Toy temp;
        temp.val = v[i];
        temp.rest = abs(v[i]);
        s.push(temp);
      }
      else if(abs(v[i])<s.top().rest){
        Toy temp;
        temp.val = v[i];
        temp.rest = abs(v[i]);
        s.push(temp);
      }
      else
        return false;
    }

    if(v[i]>0){
      if(s.empty())
        return false;
      if(v[i] + s.top().val==0){
          s.pop();
          if(!s.empty())
            s.top().rest -=v[i];
      }
      else 
        return false;
    }
  }

  if(s.empty())
    return true;
}

int main(){
  int n;
  char s[1000000];
  while(cin.getline(s,1000000)){
    vector<int> v;
    for(int i=0;i<strlen(s);i++){
      if(s[i]==' ')
	continue;
      bool minus = false;
      n = 0;
      if(s[i]=='-'){
        i++;
	minus = true;
      }
      while(s[i]!=' ' && i!=strlen(s)){
	n = n*10 + (s[i]-'0');
	i++;
      }
      if(minus)
	n = -1*n;
      v.push_back(n);
    }
    //for(int i=0;i<v.size();i++)
      //cout<<v[i]<<endl;
    if(v.size()%2==0 && toys(v))
      cout<<":-) Matrioshka!"<<endl;
    else
      cout<<":-( Try again."<<endl;
  }
}


