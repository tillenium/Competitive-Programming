#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct image{
  char p;
  int f;
};

int comp(image a, image b){
  return a.f>b.f;
}

int main(){
  int x;
  cin>>x;
  int r,c,m,n;
  char ch;
  vector<image> v;
  for(int i='A';i<='Z';i++){
    image m;
    m.p = (char)i;
    m.f = 0;
    v.push_back(m);
  }
  for(int cc=0;cc<x;cc++){
    cin>>r>>c>>m>>n;
    for(int i=0;i<v.size();i++)
      v[i].f = 0;

    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++){
	cin>>ch;
	v[ch-'A'].f++;
      }

    sort(v.begin(),v.end(),comp);
    int max = v[0].f;
    int total = 0;
    for(int i=0;i<v.size();i++){
      if(v[i].f==max)
	total += v[i].f * m;
      else
	total += v[i].f * n;
    }
    cout<<"Case "<<cc+1<<": "<<total<<endl;
  }
}


